#include "main.h"
#include "block.h"
#include "blockchain.h"

Blockchain::Blockchain()
{
    chain.emplace_back(Block(0,0));
}

Block Blockchain::getLastBlock() const
{
    return chain.back();
}

void Blockchain::addBlock(int index, uint32_t difficulty, vector<string> transactions){

    Block a(index,difficulty,transactions);
    a.mineBlock(difficulty);
    a.setPrevHash(getLastBlock().getBlockHash());
    chain.push_back(a);
}