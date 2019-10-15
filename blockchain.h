#ifndef BLOCKCHAIN_BLOCKCHAIN_H
#define BLOCKCHAIN_BLOCKCHAIN_H

#include "main.h"
#include "block.h"

class Blockchain {
private:
    vector<Block> chain;

public:
    Blockchain();
    Block getLastBlock() const;
    void addBlock();
};

#endif //BLOCKCHAIN_BLOCKCHAIN_H
