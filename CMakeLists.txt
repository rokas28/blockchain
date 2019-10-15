cmake_minimum_required(VERSION 3.13)
project(blockchain)

set(CMAKE_CXX_STANDARD 17)

add_executable(blockchain main.cpp main.h block.cpp block.h hash.h hash.cpp blockchain.h blockchain.cpp)