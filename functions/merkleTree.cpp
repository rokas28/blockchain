#include "../headers/main.h"
#include "../headers/merkleTree.h"
#include "../headers/hash.h"

// prints all hashes contained within a vector of nodes
inline void printNodeHashes(vector<Node*> v) {
    for (unsigned int a = 0; a < v.size(); a++) {
        std::cout << v[a]->hash << std::endl;
    }
}

Node::Node(string data) {
    this->hash = data;
}

MerkleTree::MerkleTree(vector<Node*> blocks) {
    vector<Node*> nodes;
    while (blocks.size() != 1) {
        //printNodeHashes(blocks);
        for (unsigned int l = 0, n = 0; l < blocks.size(); l = l + 2, n++) {
            if (l != blocks.size() - 1) { // checks for adjacent block
                nodes.push_back(new Node(hash(blocks[l]->hash + blocks[l+1]->hash))); // combine and hash adjacent blocks
                nodes[n]->left = blocks[l]; // assign children
                nodes[n]->right = blocks[l+1];
            } else {
                nodes.push_back(blocks[l]);
            }
        }
        blocks = nodes;
        nodes.clear();

    }
    this->root = blocks[0];
}

MerkleTree::~MerkleTree() {
    deleteTree(root);
    //std::cout << "Tree deleted" << std::endl;
}

void MerkleTree::deleteTree(Node* n) {
    if (n) {
        deleteTree(n->left);
        deleteTree(n->right);
        n = NULL;
        delete n;
    }
}