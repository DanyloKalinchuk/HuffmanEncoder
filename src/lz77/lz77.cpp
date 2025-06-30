#include "lz77.hpp"

std::vector<std::unique_ptr<Pointer>> lz77::encode(const std::string input){
    std::vector<std::unique_ptr<Pointer>> output;

    int window = std::min(static_cast<int>(input.size() / 3), 4095);
    int cp = 0;
    while (cp < input.size()){
        int best_length = 0;
        int best_offset = 0;
        
        int start = std::max(0, cp - window);
        for (int i = start; i < cp; i++){
            int length = 0;
            while (cp + length < input.size()){
                if (input[i + length] == input[cp + length]){
                    length++;
                }else{
                    break;
                }
                if (i+length >= cp || length >= 15){
                    break;
                }
            }

            if(length > best_length){
                best_length = length;
                best_offset = cp - i;
            }
        }

        char character;
        if (cp + best_length < input.size()){
            character = input[cp + best_length];
        }else{
            character = '\0';
        }

        output.push_back(std::move(std::make_unique<Pointer>(best_offset, best_length, character)));
        cp += best_length + 1;
    }
    
    return output;
}

std::string lz77::decode(const std::vector<std::unique_ptr<Pointer>>& encoded){
    std::string decoded = "";

    for (const auto& pointer : encoded){
        int current = decoded.size() - pointer->get_offset();
        for (int i = 0; i < pointer->get_length(); i++){
            decoded += decoded[current];
            current++;
        }
        decoded += pointer->get_character();
    }

    return decoded;
}