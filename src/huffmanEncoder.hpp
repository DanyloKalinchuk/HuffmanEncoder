#ifndef HUFFMANENCODER_HPP
#define HUFFMANENCODER_HPP

#include <string>
#include <vector>
#include <map>

std::string decode_huffman(std::map<std::string, char>, std::string);

class Node{
    public:
        const char character;
        const int frequency;
        Node* left = nullptr;
        Node* right = nullptr;

        Node(char character, int frequency, Node* left, Node* right)
            : character(character), frequency(frequency), left(left), right(right) {}
        int get_frequency() const;
        char get_character() const;
};

class HuffmanTree{
    public:
        Node* root = nullptr;

        void nodes_to_tree(std::vector<Node*>);
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
        std::vector<Node*> to_nodes();
        void dfs_encoding(Node*, std::string);
};

#endif