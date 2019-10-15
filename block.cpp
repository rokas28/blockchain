#include "main.h"
#include "block.h"

Block::Block(int index, int nonce, string prevHash, string blockHash, string merkleRootHash,
             time_t timestamp, int difficulty, vector<string> transactions){

    this -> index = index;
    this -> nonce = nonce;
    this -> prevHash = prevHash;
    this -> blockHash = blockHash;
    this -> merkleRootHash = merkleRootHash;
    this -> timestamp = timestamp;
    this -> difficulty = difficulty;
    this -> transactions = transactions;
}

int Block::getIndex() {
    return this -> index;
}

string Block::getPrevHash() {
    return this -> prevHash;
}

string Block::getHash() {
    return this -> blockHash;
}

vector<string> Block::getData(){
    return this -> transactions;
}