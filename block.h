#ifndef BLOCKCHAIN_BLOCK_H
#define BLOCKCHAIN_BLOCK_H

# include "main.h"

class Block{
private:
    int index;
    int nonce;
    string prevHash;
    string blockHash;
    string merkelRootHash;
    time_t timestamp;
    int difficulty;
    vector<string> transactions;
public:
};
#endif //BLOCKCHAIN_BLOCK_H
