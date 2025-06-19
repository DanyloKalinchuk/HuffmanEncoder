#include "huffmanEncoder.hpp"

std::string decoder::decode_huffman(std::map<std::string, char> decoding_map, std::string incoded_string){
    std::string current_code = "";
    std::string decoded_string = "";
    for (char character : incoded_string){
        current_code += std::string(1, character);
        if (decoding_map.find(current_code) != decoding_map.end()){
            decoded_string += decoding_map[current_code];
            current_code = "";
        }
    }
    return decoded_string;
}

std::string HuffmanEncoder::encode(std::string input){
    this->count_frequences(input);
    this->tree.nodes_to_tree(this->to_nodes());
    this->dfs_encoding(this->tree.root, "");

    std::vector<std::string> input_v;
    for(char ch : input){
        input_v.push_back(std::string(1,ch));
    }

    for (int i = 0; i < input_v.size(); i++){
        std::string code = this->codes[input_v[i][0]];
        input_v[i] = code;
    }

    for (std::string code : input_v){
        this->encoded += code;
    }
            
    return this->encoded;
}

std::string HuffmanEncoder::get_original(){
    std::string original = "";

    std::string current_code = "";
    for (char character : this->encoded){
        current_code += std::string(1, character);

        if (this->code_to_char.find(current_code) != this->code_to_char.end()){
            original += this->code_to_char[current_code];
            current_code = "";
        }
    }

    return original;
}

std::string HuffmanEncoder::get_encoded_text(){
    return this->encoded;
}

std::map<std::string, char> HuffmanEncoder::get_decode_map(){
    return this->code_to_char;
}

void HuffmanEncoder::count_frequences(std::string input){
    for (char ch : input){
        this->frequences[ch]++;
    }
}

std::vector<std::unique_ptr<Node>> HuffmanEncoder::to_nodes(){
    std::vector<std::unique_ptr<Node>> nodes;
    for (auto character : this->frequences){
        std::unique_ptr<Node> node = std::make_unique<Node>(character.first, character.second, nullptr, nullptr);
        nodes.push_back(std::move(node));
    }
    sort(nodes.begin(), nodes.end(), [](const std::unique_ptr<Node>& a, const std::unique_ptr<Node>& b){
        return a->get_frequency() > b->get_frequency();
    });
            

    return nodes;   
}

void HuffmanEncoder::dfs_encoding(const std::unique_ptr<Node>& current_node, std::string current_code){
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