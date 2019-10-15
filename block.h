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
    int getIndex();
    int getNonce();
    string getPrevHash();
    string getblockHash();
    string getMerkleRootHash();
    time_t getTimestamp();
    int getDifficulty();
    vector<string> getTransactions();
};
#endif //BLOCKCHAIN_BLOCK_H
