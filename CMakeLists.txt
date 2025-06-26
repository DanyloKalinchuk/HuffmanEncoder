cmake_minimum_required(VERSION 3.10)

project(HuffmanEncoder)

set(CMAKE_CXX_STANDARD 17)

add_executable(HuffmanEncoder
    src/main.cpp 
    src/huffman_encoder/huffmanEncoder.cpp
    src/huffman_tree/huffman_tree.cpp
    src/node/node.cpp
    src/file_handling/readWriteFiles.cpp
    src/file_handling/rw_encoding.cpp
    src/lz77/lz77.cpp
    src/lz77/pointer/pointer.cpp
)