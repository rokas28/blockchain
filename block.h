#ifndef BLOCKCHAIN_BLOCK_H
#define BLOCKCHAIN_BLOCK_H

# include "main.h"

class Block{
private:
    int index;
    int nonce;
    string prevHash;
    string blockHash;
    string merkleRootHash;
    time_t timestamp;
    int difficulty;
    vector<string> transactions;
public:
    Block(int index, int nonce, string prevHash, string blockHash, string merkleRootHash,
            time_t timestamp, int difficulty, vector<string> transactions);
    string getPrevHash();
    string getHash();
    int getIndex();
    vector<string> getData();
};
#endif //BLOCKCHAIN_BLOCK_H
