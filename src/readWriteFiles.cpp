#include <string>
#include <map>
#include "readWriteFiles.hpp"

ReadWriteFile::ReadWriteFile(){
    
}

void ReadWriteFile::save_file(std::string encoded_text, std::map<std::string, char> decode_map, std::string path){
    path += "/encoded_data.bin";
    std::ofstream out(path, std::ios::binary);
    if (!out){
        std::cerr << "Not a valid path" << "\n";
        return;
    }

    int size = encoded_text.length();
    out.write(reinterpret_cast<const char*>(&size), sizeof(size));
    out.write(encoded_text.c_str(), size);

    size = decode_map.size();
    out.write(reinterpret_cast<const char*>(&size), sizeof(size));
    for (const auto& [key, value] : decode_map){
        int key_size = key.size();
        out.write(reinterpret_cast<const char*>(&key_size), sizeof(key_size));
        out.write(key.c_str(), key.size());
        out.write(reinterpret_cast<const char*>(&value), sizeof(value));
    }
}

void ReadWriteFile::read_file(std::string path){
    std::ifstream in(path, std::ios::binary);
    if (!in) {
        std::cerr << "Couldn't open file";
        return;
    }

    int size;
    in.read(reinterpret_cast<char*>(&size), sizeof(size));
    this->encoded_text = std::string(size, '\0');
    in.read(&this->encoded_text[0], size);

    in.read(reinterpret_cast<char*>(&size), sizeof(size));
    for(int i = 0; i < size; i++){
        int key_size;
        in.read(reinterpret_cast<char*>(&key_size), sizeof(key_size));
        std::string key(key_size, '\0');
        in.read(&key[0], key_size);

        char value;
        in.read(reinterpret_cast<char*>(&value), sizeof(value));

        this->decode_map[key] = value;
    }
}

std::map<std::string, char> ReadWriteFile::get_decode_map(){
    return this->decode_map;
}

std::string ReadWriteFile::get_encoded_text(){
    return this->encoded_text;
}