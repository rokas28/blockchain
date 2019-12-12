#ifndef BLOCKCHAIN_MERKLETREE_H
#define BLOCKCHAIN_MERKLETREE_H

#include "main.h"

struct Node {
    std::string hash;
    Node *left;
    Node *right;

    Node(string data);
};

struct MerkleTree {
    Node* root;
    MerkleTree(vector<Node*> blocks);
    ~MerkleTree();
    void printTree(Node *n, int indent);
    void deleteTree(Node *n);
};

#endif //BLOCKCHAIN_MERKLETREE_H
