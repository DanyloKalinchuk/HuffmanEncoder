#include "rw_encoding.hpp"

void huffman_coding::encode(const std::string& text, const std::string& path){
    HuffmanEncoder encoder;
    encoder.encode(text);
    
    std::string path_copy = path;
    ReadWriteFile reader;
    reader.save_file(encoder.get_encoded_text(), encoder.get_decode_map(), path_copy);
}

std::string huffman_coding::decode(const std::string& path){
    ReadWriteFile reader;
    reader.read_file(path);

    std::string text = decoder::decode_huffman(reader.get_decode_map(), reader.get_encoded_text());
    return text;
}

void lz77_coding::encode(const std::string& text, const std::string& path){
    ReadWriteLZ77 reader;
    std::string path_copy = path;
    reader.save_file(lz77::encode(text), path_copy);
}

std::string lz77_coding::decode(const std::string& path){
    ReadWriteLZ77 reader;
    reader.read_file(path);
    std::string text = lz77::decode(reader.pointers);
    return text;
}