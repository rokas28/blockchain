#include "main.h"
#include "block.h"
#include "hash.h"

Block::Block(int index, int difficulty, vector<string> transactions){

    this -> index = index;
    this -> nonce = 0;
    this -> difficulty = difficulty;
    this -> transactions = transactions;
}

Block::Block(int index, int nonce){
    this -> index = index;
    this -> nonce = nonce;
    this -> blockHash = genBlockHash();
    this ->timestamp = time(nullptr);
    this -> difficulty = 3;
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

void Block::setPrevHash(string a){
    prevHash = a;
}

string Block::genBlockHash(){
    stringstream ss;
    ss << index << nonce << prevHash;

    return hash(ss.str());
}