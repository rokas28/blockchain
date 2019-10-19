#ifndef BLOCKCHAIN_BLOCKCHAIN_H
#define BLOCKCHAIN_BLOCKCHAIN_H

#include "main.h"
#include "block.h"

class Blockchain {
private:
    vector<Block> chain_;
public:
    vector<Transaction> allTransactions;
    Blockchain();
    Block getLastBlock() const;
    void addBlock(int index, uint32_t difficulty, vector<Transaction>& allTransactions);
    void addAllTransactions(vector<Transaction>& transactions){
        allTransactions = transactions;
    };
    void addBlock(Block block){
        chain_.push_back(block);
    };
    vector<Block> Blockchain::getBlockchain();
};

#endif //BLOCKCHAIN_BLOCKCHAIN_H
