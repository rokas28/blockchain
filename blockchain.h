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
    void addBlock(int index, uint32_t difficulty, vector<Transaction> transactions);
    void addAllTransactions(vector<Transaction>& transactions){
        allTransactions = transactions;
    };
};

#endif //BLOCKCHAIN_BLOCKCHAIN_H
