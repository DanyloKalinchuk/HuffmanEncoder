#include <iostream>
#include <string>
#include <map>
#include "readWriteFiles.hpp"

using namespace std;

ReadWriteFile::ReadWriteFile(){
    
}

void ReadWriteFile::save_file(string encoded_text, map<string, char> decode_map, string path){
    path += "/encoded_data.bin";
    ofstream out(path, ios::binary);
    if (!out){
        cerr << "Not a valid path" << "\n";
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

void ReadWriteFile::read_file(string path){
    ifstream in(path, ios::binary);
    if (!in) {
        cerr << "Couldn't open file";
        return;
    }

    int size;
    in.read(reinterpret_cast<char*>(&size), sizeof(size));
    this->encoded_text = string(size, '\0');
    in.read(&this->encoded_text[0], size);

    in.read(reinterpret_cast<char*>(&size), sizeof(size));
    for(int i = 0; i < size; i++){
        int key_size;
        in.read(reinterpret_cast<char*>(&key_size), sizeof(key_size));
        string key(key_size, '\0');
        in.read(&key[0], key_size);

        char value;
        in.read(reinterpret_cast<char*>(&value), sizeof(value));

        this->decode_map[key] = value;
    }
}

map<string, char> ReadWriteFile::get_decode_map(){
    return this->decode_map;
}

string ReadWriteFile::get_encoded_text(){
    return this->encoded_text;
}