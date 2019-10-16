#include <iostream>

#include "main.h"
#include "hash.h"
#include "block.h"
#include "blockchain.h"
#include "user.h"

int main() {

    vector<Transaction>s;
    Blockchain a = Blockchain();

    cout << "1 mined block:  ";
    a.addBlock(1,1,s);
    cout << endl;

    cout << "2 mined block:  ";
    a.addBlock(2,2,s);
    cout << endl;

    cout << "3 mined block:  ";
    a.addBlock(3,1,s);
    cout << endl;

    cout << "4 mined block:  ";
    a.addBlock(4,2,s);
    cout << endl;

    return 0;
}