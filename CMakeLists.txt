cmake_minimum_required(VERSION 3.13)
project(blockchain)

set(CMAKE_CXX_STANDARD 17)

add_executable(blockchain main.cpp headers/main.h functions/block.cpp headers/block.h headers/hash.h functions/hash.cpp headers/blockchain.h functions/blockchain.cpp headers/user.h headers/merkleTree.h functions/merkleTree.cpp)