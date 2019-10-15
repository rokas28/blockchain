#ifndef BLOCKCHAIN_USER_H
#define BLOCKCHAIN_USER_H

#include "main.h"

struct transaction {
    string sender;
    string receiver;
    double amount;
};

class User {
private:
    string name_;
    string publicKey_;
    double balance_;
public:
    User(string name, string publicKey, double balance);
    User();
};

User::User(string name, string publicKey, double balance){
    this -> name_ = name;
    this -> publicKey_ = publicKey;
    this -> balance_ = balance;
};

User::User(){
    this -> name_ = "-";
    this -> publicKey_ = "-";
    this -> balance_ = 0;
};

#endif //BLOCKCHAIN_USER_H
