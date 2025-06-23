#include "rw_encoding.hpp"

void en_decoding::encode(const std::string& text, const std::string& path, const int& type){
    switch (type){
        case 1:{
            HuffmanEncoder encoder;
            encoder.encode(text);

            std::string path_copy = path;
            ReadWriteFile reader;
            reader.save_file(encoder.get_encoded_text(), encoder.get_decode_map(), path_copy);
            break;
        }
        case 2:{
            ReadWriteLZ77 reader;
            std::string path_copy = path;
            reader.save_file(lz77::encode(text), path_copy);
            break;
        }
    }
}

std::string en_decoding::decode(const std::string& path){
    std::ifstream in(path, std::ios::binary);
    if (!in) {
        std::cerr << "Couldn't open file \n";
        in.close();
        return "Error: Could not open the file";
    }

    char coding_type;
    in.read(reinterpret_cast<char*>(&coding_type), sizeof(coding_type));

    switch (coding_type - '0'){
        case 1:{
            ReadWriteFile reader;
            reader.read_file(in);

            std::string text = decoder::decode_huffman(reader.get_decode_map(), reader.get_encoded_text());
            return text;
            break;
        }
        case 2:{
            ReadWriteLZ77 reader;
            reader.read_file(in);
            std::string text = lz77::decode(reader.pointers);
            return text;
            break;
        }

        default:
            return "Error: Text wasn't read";
    }
}