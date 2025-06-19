#include "lz77.hpp"

std::vector<std::unique_ptr<Pointer>> lz77::encode(const std::string input){
    std::vector<std::unique_ptr<Pointer>> output;
    output.push_back(std::make_unique<Pointer>(0, 0, input[0]));

    int window = input.size() / 3;
    int cp = 1;
    while (cp < input.size()){
        int len = 0;
        int offset = 0;
        int search = std::max(0, cp - window);
        int buffer = cp;

        while (search < cp && buffer < cp + window){
            if (input[search] == input[buffer]){
                if (offset == 0){
                    offset = buffer - search;
                }
                len++;
                buffer++;
            }
            else if (len > 0){
                break;
            }

            search++;
        }

        if (cp + len < input.size()){
            output.push_back(std::make_unique<Pointer>(offset, len, input[cp + len]));
        }else{
            output.push_back(std::make_unique<Pointer>(offset, len, '\0'));
        }

        cp += output.back()->get_length() + 1;


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