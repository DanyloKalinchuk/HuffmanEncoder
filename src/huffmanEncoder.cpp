#include "huffmanEncoder.hpp"
#include <iostream>
#include <algorithm>

string decode_huffman(map<string, char> decoding_map, string incoded_string){
    string current_code = "";
    string decoded_string = "";
    for (char character : incoded_string){
        current_code += string(1, character);
        if (decoding_map.find(current_code) != decoding_map.end()){
            decoded_string += decoding_map[current_code];
            current_code = "";
        }
    }
    return decoded_string;
}

int Node::get_frequency() const {
    return this->frequency;
}

char Node::get_character() const {
    return this->character;
}

void HuffmanTree::nodes_to_tree(vector<Node*> nodes){
    while (nodes.size() > 1){
        Node* left = nodes.back();
        nodes.pop_back();

        Node* right = nodes.back();
        nodes.pop_back();

        Node* to_add = new Node('\0', (*right).get_frequency() + (*left).get_frequency(), left, right);

        nodes.push_back(to_add);

        sort(nodes.begin(), nodes.end(), [](Node* a, Node* b) {
        return a->get_frequency() > b->get_frequency();
        });
    }

    this->root = nodes[0]; 
}

string HuffmanEncoder::encode(string input){
    this->count_frequences(input);
    this->tree.nodes_to_tree(this->to_nodes());
    this->dfs_encoding(this->tree.root, "");

    vector<string> input_v;
    for(char ch : input){
        input_v.push_back(string(1,ch));
    }

    for (int i = 0; i < input_v.size(); i++){
        string code = this->codes[input_v[i][0]];
        input_v[i] = code;
    }

    for (string code : input_v){
        this->encoded += code;
    }
            
    return this->encoded;
}

string HuffmanEncoder::get_original(){
    string original = "";

    string current_code = "";
    for (char character : this->encoded){
        current_code += string(1, character);

        if (this->code_to_char.find(current_code) != this->code_to_char.end()){
            original += this->code_to_char[current_code];
            current_code = "";
        }
    }

    return original;
}

string HuffmanEncoder::get_encoded_text(){
    return this->encoded;
}

map<string, char> HuffmanEncoder::get_decode_map(){
    return this->code_to_char;
}

void HuffmanEncoder::count_frequences(string input){
    for (char ch : input){
        this->frequences[ch]++;
    }
}

vector<Node*> HuffmanEncoder::to_nodes(){
    vector<Node*> nodes;
    for (auto character : this->frequences){
        Node* node = new Node(character.first, character.second, nullptr, nullptr);
        nodes.push_back(node);
    }
    sort(nodes.begin(), nodes.end(), [](Node* a, Node* b){
        return a->get_frequency() > b->get_frequency();
    });
            

    return nodes;   
}

void HuffmanEncoder::dfs_encoding(Node* current_node, string current_code){
    if (current_node->get_character() != '\0'){
        this->codes[current_node->get_character()] = current_code;
        this->code_to_char[current_code] = current_node->get_character();
    }

    if (current_node->left != nullptr){
        dfs_encoding(current_node->left, current_code+"0");
    }

    if (current_node->right != nullptr){
        dfs_encoding(current_node->right, current_code+"1");
    }
}