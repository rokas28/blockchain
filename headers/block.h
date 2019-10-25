#ifndef BLOCKCHAIN_BLOCK_H
#define BLOCKCHAIN_BLOCK_H

#include "main.h"
#include "hash.h"
//#include "user.h"

class User {
private:
    string name_;
    string publicKey_;
    double balance_;
public:
    User(string name, string publicKey, double balance){
        this -> name_ = name;
        this -> publicKey_ = publicKey;
        this -> balance_ = balance;
    }
    User(){
        this -> name_ = "-";
        this -> publicKey_ = "-";
        this -> balance_ = 0;
    }
    string getName(){
        return this -> name_;
    }
    string getPublicKey(){
        return this -> publicKey_;
    }
    double getBalance(){
        return this -> balance_;
    }
};

struct Transaction {
    string transactionID_;
    User sender_;
    User receiver_;
    double amount_;

    Transaction(User sender, User receiver, double amount){
        sender_ = sender;
        receiver_ = receiver;
        amount_ = amount;
        stringstream ss;
        ss << sender_.getPublicKey() << receiver_.getPublicKey() << amount_;
        transactionID_ = hash(ss.str());
    }
};

class Block{
private:
    int index_;
    int nonce_;
    string prevHash_;
    string blockHash_;
    string merkleRootHash_;
    string timestamp_;
    uint32_t difficulty_;
    vector<Transaction> transactions_;

public:
    Block *prevHash;
    Block(int index, uint32_t difficulty);
    //Block(int index, int nonce);
    int getIndex();
    int getNonce();
    string getPrevHash();
    string getBlockHash();
    string getMerkleRootHash();
    string getTimestamp();
    int getDifficulty();
    vector<Transaction> getTransactions();
    void Block::setPrevHash(string a);
    string genBlockHash();
    void mineBlock(uint32_t difficulty);
    void setBlockTransactions(vector<Transaction> &allTransactions);
    void addTransaction(Transaction transaction){
        this->transactions_.push_back(transaction);
    }
    void merkleRootHash();
    void setTimestamp();
};
#endif //BLOCKCHAIN_BLOCK_H
