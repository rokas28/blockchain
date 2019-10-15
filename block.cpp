#include "main.h"
#include "block.h"
#include "hash.h"

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

Block::Block(int index, int nonce){
    this -> index = index;
    this -> nonce = nonce;
    this ->timestamp = time(nullptr);
}

int Block::getIndex(){
    return this -> index;
}

int Block::getNonce(){
    return this -> nonce;
}

string Block::getPrevHash(){
    return this -> prevHash;
}

string Block::getBlockHash(){
    return this -> blockHash;
}

string Block::getMerkleRootHash(){
    return this -> merkleRootHash;
}

time_t Block::getTimestamp(){
    return this -> timestamp;
}

int Block::getDifficulty(){
    return this -> difficulty;
}

vector<string> Block::getTransactions(){
    return this -> transactions;
}

string Block::genBlockHash(){
    stringstream ss;
    ss << index << nonce << prevHash << timestamp;

    return hash(ss.str());
}