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
    string getBlockHash();
    string getMerkleRootHash();
    time_t getTimestamp();
    int getDifficulty();
    vector<string> getTransactions();
    string genBlockHash();
};
#endif //BLOCKCHAIN_BLOCK_H
