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

void Blockchain::addBlock(){
    Block a(0,0);

    a.setPrevHash(getLastBlock().getBlockHash());
    chain.push_back(a);
}