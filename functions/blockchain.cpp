#include "../headers/main.h"
#include "../headers/block.h"
#include "../headers/blockchain.h"

Blockchain::Blockchain()
{
    chain_.emplace_back(Block(0,0));
};

Block Blockchain::getLastBlock() const
{
    return chain_.back();
};

vector<Block> Blockchain::getBlockchain(){
    return this -> chain_;
}

void Blockchain::addBlock(int index, uint32_t difficulty, vector<Transaction>& allTransactions){

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
};