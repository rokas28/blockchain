#include "../headers/main.h"
#include "../headers/block.h"
#include "../headers/hash.h"
//#include "user.h"

Block::Block(int index, uint32_t difficulty){
    this -> index_ = index;
    this -> nonce_ = 0;
    this -> difficulty_ = difficulty;
}

/*Block::Block(int index, int nonce){
    this -> index_ = index;
    this -> nonce_ = nonce;
    this -> blockHash_ = genBlockHash();
    this ->timestamp_ = time(nullptr);
    this -> difficulty_ = 3;
}*/

int Block::getIndex(){
    return this -> index_;
}

int Block::getNonce(){
    return this -> nonce_;
}

string Block::getPrevHash(){
    return this -> prevHash_;
}

string Block::getBlockHash(){
    return this -> blockHash_;
}

string Block::getMerkleRootHash(){
    return this -> merkleRootHash_;
}

string Block::getTimestamp(){
    return this -> timestamp_;
}

int Block::getDifficulty(){
    return this -> difficulty_;
}

vector<Transaction> Block::getTransactions(){
    return this -> transactions_;
}

void Block::setPrevHash(string a){
    prevHash_ = a;
}

string Block::genBlockHash(){
    stringstream ss;
    ss << index_ << nonce_ << merkleRootHash_ << timestamp_;
    //cout << ss.str() << endl;
    return hash(ss.str());
}

void Block::mineBlock(uint32_t difficulty){

    string str(difficulty,'0');
    //cout << "string str(difficulty,0);" << endl;
    do {
        nonce_++; //cout << "nonce++ = " << nonce_ << endl;
        blockHash_ = genBlockHash(); //cout << "blockHash = genBlockHash(); = " << blockHash_ << endl;
    } while (blockHash_.substr(0, difficulty) != str);
    cout << blockHash_ << endl;
}

void Block::setBlockTransactions(vector<Transaction>& allTransactions){

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> random(0,allTransactions.size()-1);

    //cout << "allTransactions size: " << allTransactions.size() << endl;

    for(int i = 0; i <= 99; i ++){
        int t = random(gen);
        addTransaction(allTransactions[t]);
        auto it = allTransactions.begin() + t;
        std::rotate(it, it + 1, allTransactions.end());
    }
    allTransactions.erase(allTransactions.end()-100,allTransactions.end());
    //cout << "allTransactions size: " << allTransactions.size() << endl;
};

void Block::merkleRootHash(){
    string transactionsHash;
    for(int i = 0; i < transactions_.size(); i++){
        transactionsHash = transactionsHash + transactions_[i].sender_ + transactions_[i].receiver_;
    }
    //cout << transactionsHash << endl;
    merkleRootHash_ = hash(transactionsHash);
    //cout << "  merkleRootHash(): " << merkleRootHash_ << endl;
};

void Block::setTimestamp(){
    stringstream ss;
    auto timestamp = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    auto tm = *std::localtime(&timestamp);
    ss << std::put_time(&tm, "%F %H:%M:%S");
    timestamp_ = ss.str();
};