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

    vector<Transaction> allTransactionsa = allTransactions;
    vector<Transaction> allTransactionsb = allTransactions;
    vector<Transaction> allTransactionsc = allTransactions;
    vector<Transaction> allTransactionsd = allTransactions;
    vector<Transaction> allTransactionse = allTransactions;

    Block *a1 = new Block(index,difficulty);
    a1->setTimestamp();
    a1->setBlockTransactions(allTransactionsa);
    a1->merkleRootHash();
    Block *b1 = new Block(index,difficulty);
    b1->setTimestamp();
    b1->setBlockTransactions(allTransactionsb);
    b1->merkleRootHash();
    Block *c1 = new Block(index,difficulty);
    c1->setTimestamp();
    c1->setBlockTransactions(allTransactionsc);
    c1->merkleRootHash();
    Block *d1 = new Block(index,difficulty);
    d1->setTimestamp();
    d1->setBlockTransactions(allTransactionsd);
    d1->merkleRootHash();
    Block *e1 = new Block(index,difficulty);
    e1->setTimestamp();
    e1->setBlockTransactions(allTransactionse);
    e1->merkleRootHash();

    std::random_device rd;
    std::mt19937 gen(rd());

    uniform_int_distribution<int> block(1,5);
    int time = 0;
    int kk = 0;
    while(kk!=1){
        time = time + 100000;
        int kkk = 0;
        vector<int> used(5,0);
        while(a1->getBlockHash().empty() || b1->getBlockHash().empty() ||
              c1->getBlockHash().empty() || d1->getBlockHash().empty() || e1->getBlockHash().empty()){

            /*for (int i = 0; i <5;i++)cout << "used: " << used[i] << " ";
            cout << endl;*/
            int num = 0;
            int k = 0;
            int done = 0;

            while(k!=1){
                int temp = block(gen);
                if(temp!=used[0] && temp!=used[1] && temp!=used[2] && temp!=used[3] && temp!=used[4]){
                    num = temp;
                    k++;
                }
            }
            if(num == 1){
                a1->mineBlock(difficulty, done, time);
                if(done == 1){
                    allTransactions = allTransactionsa;
                    a1->prevHash = root_;
                    root_ = a1;
                    kkk++;
                    kk++;
                    break;
                }
                else used[0] = 1;
            }
            else if(num == 2){
                b1->mineBlock(difficulty, done, time);
                if(done == 1){
                    allTransactions = allTransactionsb;
                    b1->prevHash = root_;
                    root_ = b1;
                    kkk++;
                    kk++;
                    break;
                }
                else if(done == 0)used[1] = 2;
            }
            else if(num == 3){
                c1->mineBlock(difficulty, done, time);
                if(done == 1){
                    allTransactions = allTransactionsc;
                    c1->prevHash = root_;
                    root_ = c1;
                    kkk++;
                    kk++;
                    break;
                }
                else if(done == 0) used[2] = 3;
            }
            else if(num == 4){
                d1->mineBlock(difficulty, done, time);
                if(done == 1){
                    allTransactions = allTransactionsd;
                    d1->prevHash = root_;
                    root_ = d1;
                    kkk++;
                    kk++;
                    break;
                }
                else if(done == 0) used[3] = 4;
            }
            else if(num == 5){
                e1->mineBlock(difficulty, done, time);
                if(done == 1){
                    allTransactions = allTransactionse;
                    e1->prevHash = root_;
                    root_ = e1;
                    kkk++;
                    kk++;
                    break;
                }
                else if(done == 0) used[4] = 5;
            }
            if (used[0]==1 && used[1]==2 && used[2]==3 && used[3]==4 && used[4]==5) break;

        }

    }


    /*Block *t = new Block(index,difficulty);
    t->prevHash = root_;
    t->setTimestamp();
    t->setBlockTransactions(allTransactions);
    t->merkleRootHash();
    t->mineBlock(difficulty);
    root_ = t;*/

    length_++;
}

void Blockchain::printBlockchain() {
    int i = length_;
    while (root_) {
        cout << "Block: " << i << " | Index: " << root_->getIndex() << " | Nonce: " << root_->getNonce() << " | Hash: " << root_->getBlockHash() << endl;
        cout <<  " | Timestamp: " << root_->getTimestamp() <<  " | MerkleTreeHash: " << root_->getMerkleRootHash() << endl << endl;
        root_ = root_->prevHash;
        i--;
    }
}

void transactionValidation(vector<Transaction>& allTransactions){
    string a;
    for (auto &i : allTransactions) {
        stringstream ss;
        ss << i.sender_.getPublicKey() << i.receiver_.getPublicKey() << i.amount_;
        a = hash(ss.str());
        if(i.transactionID_ != a)throw "Ivalid Transaction!";
        //cout << a << " " << i.transactionID_ << endl;
    }
};

void balanceValidation(vector<Transaction>& allTransactions){
    int k = 0;
    for (int i = 0; i < allTransactions.size(); i ++){
        if (allTransactions[i].sender_.getBalance() < allTransactions[i].amount_){
            auto it = allTransactions.begin() + i;
            std::rotate(it, it + 1, allTransactions.end());
            k++;
        }
       // cout << "Balance: " << allTransactions[i].sender_.getBalance() << " | amount: " << allTransactions[i].amount_ << endl;
    }
    allTransactions.erase(allTransactions.end()-k,allTransactions.end());
};