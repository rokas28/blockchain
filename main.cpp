#include <iostream>

#include "main.h"
#include "hash.h"
#include "block.h"
#include "blockchain.h"
#include "user.h"

const int n = 100;
const int m = 1000;

int main() {

    vector<Transaction> t;
    vector<User> u;
    u = genUsers(n);
    cout << "users size: " << u.size() << endl;
    Blockchain a = Blockchain();
    genTransactions(n,m,a,u);
    cout << "allTransactions size:  " << a.allTransactions.size() << endl;

   /* cout << "1 mined block:  ";
    a.addBlock(1,1,t);
    cout << endl;

    cout << "2 mined block:  ";
    a.addBlock(2,2,t);
    cout << endl;

    cout << "3 mined block:  ";
    a.addBlock(3,1,t);
    cout << endl;

    cout << "4 mined block:  ";
    a.addBlock(4,2,t);
    cout << endl;*/

    return 0;
}