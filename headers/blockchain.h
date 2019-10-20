#ifndef BLOCKCHAIN_BLOCKCHAIN_H
#define BLOCKCHAIN_BLOCKCHAIN_H

#include "main.h"
#include "block.h"

class Blockchain {
private:
    vector<Block> chain_;
    Block *root_;
    int length_;
public:
    vector<Transaction> allTransactions;
    Blockchain();
   // Blockchain(Block *&root);
    Block getLastBlock() const;
    void addBlock(int index, uint32_t difficulty, vector<Transaction>& allTransactions);
    void addAllTransactions(vector<Transaction>& transactions){
        allTransactions = transactions;
    };
    void addBlock(Block block){
        chain_.push_back(block);
    };
    //void addNode(int index, uint32_t difficulty, vector<Transaction>& allTransactions);
    vector<Block> Blockchain::getBlockchain();
    void printBlockchain();
    int getBlockchainLength(){
        return length_;
    }
};

#endif //BLOCKCHAIN_BLOCKCHAIN_H
