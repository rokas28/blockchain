#ifndef BLOCKCHAIN_USER_H
#define BLOCKCHAIN_USER_H

#include "main.h"
#include "hash.h"
#include "block.h"
#include "blockchain.h"

class User {
private:
    string name_;
    string publicKey_;
    double balance_;
public:
    User(string name, string publicKey, double balance);
    User();
    string getName();
};

User::User(string name, string publicKey, double balance){
    this -> name_ = name;
    this -> publicKey_ = publicKey;
    this -> balance_ = balance;
};

User::User(){
    this -> name_ = "-";
    this -> publicKey_ = "-";
    this -> balance_ = 0;
};

string User::getName(){
    return this -> name_;
};

vector<User> genUsers(int n) {
    std::random_device rd;
    std::mt19937 gen(rd());
    vector<User> users;
    string l_name(30,0);
    string name;
    string publicKey;
    uniform_int_distribution<int> nameGen(48, 122);
    std::uniform_int_distribution<int> balance(100,1000000);
    for (int i = 0; i < n; i++) {
        for (int i = 0; i < 30; i++) l_name[i] = nameGen(gen);
        name = hash(l_name);
        publicKey = hash(name);
        //cout << "user: " << i << " __ " << name << " _ " << publicKey << endl;
        users.emplace_back(User(name,publicKey,balance(gen)));
    }
    return users;
}

void genTransactions(int n, int m, Blockchain& blockchain, vector<User>& users){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> random(0,n-1);
    std::uniform_int_distribution<int> amount(0,100);
    vector<Transaction> transactions;
    for(int i = 0; i < m; i++){
        transactions.emplace_back(Transaction(users[random(gen)].getName(),users[random(gen)].getName(),amount(gen)));
    }
    blockchain.addAllTransactions(transactions);
};

#endif //BLOCKCHAIN_USER_H
