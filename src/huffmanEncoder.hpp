#ifndef HUFFMANENCODER_HPP
#define HUFFMANENCODER_HPP

#include <string>
#include <vector>
#include <map>

using namespace std;

string decode_huffman(map<string, char>, string);

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

        void nodes_to_tree(vector<Node*>);
};

class HuffmanEncoder{
    public:
        string encode(string);
        string get_original();

        string get_encoded_text();
        map<string, char> get_decode_map();

    private:
        string encoded = "";
        map<char, string> codes;
        map<string, char> code_to_char;
        map<char, int> frequences;
        HuffmanTree tree;

        void count_frequences(string);
        vector<Node*> to_nodes();
        void dfs_encoding(Node*, string);
};

#endif