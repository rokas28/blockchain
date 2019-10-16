#include "main.h"
#include "block.h"
#include "hash.h"

Block::Block(int index, uint32_t difficulty, vector<string> transactions){

    this -> index_ = index;
    this -> nonce_ = 0;
    this -> difficulty_ = difficulty;
    this -> transactions_ = transactions;
}

Block::Block(int index, int nonce){
    this -> index_ = index;
    this -> nonce_ = nonce;
    this -> blockHash_ = genBlockHash();
    this ->timestamp_ = time(nullptr);
    this -> difficulty_ = 3;
}

int Block::getIndex(){
    return this -> index_;
}

int Block::getNonce(){
    return this -> nonce_;
}

string Block::getPrevHash(){
    return this -> prevHash_;
}

string Block::getBlockHash(){
    return this -> blockHash_;
}

string Block::getMerkleRootHash(){
    return this -> merkleRootHash_;
}

time_t Block::getTimestamp(){
    return this -> timestamp_;
}

int Block::getDifficulty(){
    return this -> difficulty_;
}

vector<string> Block::getTransactions(){
    return this -> transactions_;
}

void Block::setPrevHash(string a){
    prevHash_ = a;
}

string Block::genBlockHash(){
    stringstream ss;
    ss << index_ << nonce_ << prevHash_;
    //cout << ss.str() << endl;

    return hash(ss.str());
}

void Block::mineBlock(uint32_t difficulty){

    string str(difficulty,'0');
    //cout << "string str(difficulty,0);" << endl;
    do {
        nonce_++; //cout << "nonce++ = " << nonce << endl;
        blockHash_ = genBlockHash(); //cout << "blockHash = genBlockHash(); = " << blockHash << endl;
    } while (blockHash_.substr(0, difficulty) != str);
    cout << blockHash_ << endl;
}