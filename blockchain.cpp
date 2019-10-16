#include "main.h"
#include "block.h"
#include "blockchain.h"

Blockchain::Blockchain()
{
    chain_.emplace_back(Block(0,0));
}

Block Blockchain::getLastBlock() const
{
    return chain_.back();
}

void Blockchain::addBlock(int index, uint32_t difficulty, vector<string> transactions){

    Block a(index,difficulty,transactions);
    //cout << "Block a(index,difficulty,transactions);" << endl;
    a.setPrevHash(getLastBlock().getBlockHash());
    //cout << "a.setPrevHash(getLastBlock().getBlockHash());" << endl;
    a.mineBlock(difficulty);
    //cout << "a.mineBlock(difficulty);" << endl;
    chain_.push_back(a);
    //cout << "chain.push_back(a);" << endl;
}