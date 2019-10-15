#include "main.h"
#include "block.h"
#include "blockchain.h"

Blockchain::Blockchain()
{
    chain.emplace_back(Block(0, 0, string prevHash, string blockHash, string merkleRootHash,
            time_t timestamp, int difficulty, vector<string> transactions));
}