#include <iostream>

#include "headers/main.h"
#include "headers/hash.h"
#include "headers/block.h"
#include "headers/blockchain.h"
#include "headers/user.h"

const int n = 1000;
const int m = 1000;
const int d = 1;

int main() {

    vector<Transaction> t;
    vector<User> u;
    u = genUsers(n);
    cout << "__users size: " << u.size() << endl;
    Blockchain a = Blockchain();
    genTransactions(n,m,a,u);
    transactionValidation(a.allTransactions);
    balanceValidation(a.allTransactions);

    cout << "__allTransactions size:  " << a.allTransactions.size() << endl;
    cout << "__Blockchain size: " << a.getBlockchainLength() << endl;
    int i = 1;
    while(a.allTransactions.size() >= 1){
        cout  << i << " mined block:  ";
        a.addBlock(i,d,a.allTransactions);
        cout << "__allTransactions size:  " << a.allTransactions.size() << endl;
        //cout << "Block added" << endl << endl;
        i++;
    };
    cout << "__Blockchain size: " << a.getBlockchainLength() << endl;
    a.printBlockchain();

    return 0;
}