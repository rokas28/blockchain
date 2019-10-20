#include "../headers/main.h"
#include "../headers/block.h"
#include "../headers/blockchain.h"

/*Blockchain::Blockchain()
{
    chain_.emplace_back(Block(0,0));
};*/
Blockchain::Blockchain()
{
    this -> root_ = NULL;
    this -> length_ = 0;
};

Block Blockchain::getLastBlock() const
{
    return chain_.back();
};

vector<Block> Blockchain::getBlockchain(){
    return this -> chain_;
}

/*void Blockchain::addBlock(int index, uint32_t difficulty, vector<Transaction>& allTransactions){

    Block a(index,difficulty);
    a.setBlockTransactions(allTransactions);
    //cout << "All transactions: " << a.getTransactions().size() << endl;
    //cout << "Block a(index,difficulty,transactions);" << endl;
    a.setPrevHash(getLastBlock().getBlockHash());
    //cout << "a.setPrevHash(getLastBlock().getBlockHash());" << endl;
    a.mineBlock(difficulty);
    //cout << "a.mineBlock(difficulty);" << endl;
    addBlock(a);
    //chain_.push_back(a);
    //cout << "chain.push_back(a);" << endl;
};*/

void Blockchain::addBlock(int index, uint32_t difficulty, vector<Transaction>& allTransactions){
    Block *t = new Block(index,difficulty);
    t->prevHash = root_;
    t->setTimestamp();
    t->setBlockTransactions(allTransactions);
    t->merkleRootHash();
    t->mineBlock(difficulty);
    root_ = t;
    length_++;
}

void Blockchain::printBlockchain() {
    int i = length_;
    while (root_) {
        cout << "Block: " << i << " | Index: " << root_->getIndex() << " | Nonce: " << root_->getNonce() << " | Hash: " << root_->getBlockHash() << endl;
        cout <<  " | Timestamp: " << root_->getTimestamp() << endl << endl;
        root_ = root_->prevHash;
        i--;
    }
}