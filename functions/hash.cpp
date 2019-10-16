#include "../headers/hash.h"
#include "../headers/main.h"

string readFromFile(string file) {
    string str;
    ifstream df(file);
    if (!df) cout << "Duomenu failas nerastas" << endl;
    else {
        str.assign((std::istreambuf_iterator<char>(df) ),(std::istreambuf_iterator<char>()));
    }
    return str;
};

string readFromConsole() {
    string str;
    cout << "Iveskite duomenis" << endl;
    cin.ignore();
    getline(cin,str);
    return str;
}

string readData(string file){
    cout << "Jei norite ivesti duomenis ranka, spauskite 1, jei norite juos imti is failo 2" << endl;
    int a;
    cin >> a;
    string str;
    if (a == 1){
        str = readFromConsole();
    }
    if (a == 2){
        str = readFromFile(file);
    }
    return str;
}

long long int seedGen(string str) {
    long long int seed;
    seed = str.length() * str.length() * 12345;
    for(int i = 0; i < str.length(); i++){
        if(i%2!=0)seed = seed + ((int)str[i]/3*2);
        if(i%3!=0)seed = seed + ((int)str[i]/4*3);
        if(i%4!=0)seed = seed + ((int)str[i]/3*5);
        if(i%5!=0)seed = seed + ((int)str[i]/5*3);
        if(i%6!=0)seed = seed + ((int)str[i]/4*5);
        if(i%7!=0)seed = seed + ((int)str[i]/3*7);
        if(i%9!=0)seed = seed + ((int)str[i]/4*9);
        seed = seed + (int)str[i] + 134679285;
    }
    return seed;
}

string hash(string str){
    mt19937 gen(seedGen(str));
    uniform_int_distribution<int> num(48, 57);
    uniform_int_distribution<int> clett(65, 70);
    uniform_int_distribution<int> lett(97, 122);
    uniform_int_distribution<int> type(1,3);
    string hsh(64,0);

    for (int i = 0; i < 64; i++) {
        int sym = type(gen);
        if (sym==1) hsh[i] = num(gen);
        if (sym==2) hsh[i] = clett(gen);
        if (sym==3) hsh[i] = lett(gen);
    }
    return hsh;
}

void start_c(std::chrono::time_point<std::chrono::high_resolution_clock> &start) {
    start = std::chrono::high_resolution_clock::now();
}

void end_c(std::chrono::time_point<std::chrono::high_resolution_clock> &end) {
    end = std::chrono::high_resolution_clock::now();
}

void hash_k(){
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    std::chrono::duration<double> durationCount;

    ifstream df("konstitucija.txt");
    if (!df) cout << "Duomenu failas nerastas" << endl;
    string str;
    vector<string> str_lines;
    vector<string> hash_lines;
    int a = 0;
    while (std::getline(df,str)) {
        str_lines.push_back(str);
        a++;
    }
    start_c(start);
    for(int i = 0; i < a; i++){
        hash_lines.push_back(hash(str_lines[i]));
    }
    end_c(end);
    std::chrono::duration<double> time = end-start;
    for(int i = 0; i < a; i++){
        cout << i << " eil: " << hash_lines[i] << endl;
    }
    cout << "Hash'uoti konstitucijos eilutes uztruko:" << time.count() << "sec"  << endl;
}
