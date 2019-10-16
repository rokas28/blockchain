#ifndef BLOCKCHAIN_BLOCK_H
#define BLOCKCHAIN_BLOCK_H

# include "main.h"

class Block{
private:
    int index_;
    int nonce_;
    string prevHash_;
    string blockHash_;
    string merkleRootHash_;
    time_t timestamp_;
    uint32_t difficulty_;
    vector<string> transactions_;
public:
    Block(int index, uint32_t difficulty, vector<string> transactions);
    Block(int index, int nonce);
    int getIndex();
    int getNonce();
    string getPrevHash();
    string getBlockHash();
    string getMerkleRootHash();
    time_t getTimestamp();
    int getDifficulty();
    vector<string> getTransactions();
    void Block::setPrevHash(string a);
    string genBlockHash();
    void mineBlock(uint32_t difficulty);
};
#endif //BLOCKCHAIN_BLOCK_H
