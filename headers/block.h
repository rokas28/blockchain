#ifndef BLOCKCHAIN_BLOCK_H
#define BLOCKCHAIN_BLOCK_H

#include "main.h"

struct Transaction {
    string sender_;
    string receiver_;
    double amount_;

    Transaction(string sender, string receiver, double amount){
        sender_ = sender;
        receiver_ = receiver;
        amount_ = amount;
    }
};

class Block{
private:
    int index_;
    int nonce_;
    string prevHash_;
    string blockHash_;
    string merkleRootHash_;
    time_t timestamp_;
    uint32_t difficulty_;
    vector<Transaction> transactions_;
public:
    Block(int index, uint32_t difficulty);
    //Block(int index, int nonce);
    int getIndex();
    int getNonce();
    string getPrevHash();
    string getBlockHash();
    string getMerkleRootHash();
    time_t getTimestamp();
    int getDifficulty();
    vector<Transaction> getTransactions();
    void Block::setPrevHash(string a);
    string genBlockHash();
    void mineBlock(uint32_t difficulty);
    void setBlockTransactions(vector<Transaction> &allTransactions);
    void addTransaction(Transaction transaction){
        transactions_.push_back(transaction);
    }
};
#endif //BLOCKCHAIN_BLOCK_H
