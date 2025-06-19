#pragma once

#include <string>
#include <map>
#include "../huffman_tree/huffman_tree.hpp"

namespace decoder{
    std::string decode_huffman(std::map<std::string, char>, std::string);
};

class HuffmanEncoder{
    public:
        std::string encode(std::string);
        std::string get_original();

        std::string get_encoded_text();
        std::map<std::string, char> get_decode_map();

    private:
        std::string encoded = "";
        std::map<char, std::string> codes;
        std::map<std::string, char> code_to_char;
        std::map<char, int> frequences;
        HuffmanTree tree;

        void count_frequences(std::string);
        std::vector<std::unique_ptr<Node>> to_nodes();
        void dfs_encoding(const std::unique_ptr<Node>& , std::string);
};