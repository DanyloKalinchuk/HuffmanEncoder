#include "readWriteFiles.hpp"

ReadWriteFile::ReadWriteFile(){
    
}

void ReadWriteFile::save_file(std::string encoded_text, std::map<std::string, char> decode_map, std::string path){
    path += "/encoded_data.bin";
    std::ofstream out(path, std::ios::binary);
    if (!out){
        std::cerr << "Invalid path! \n";
        out.close();
        return;
    }

    char type = '1';
    out.write(reinterpret_cast<char*>(&type), sizeof(type));

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

    out.close();
}

void ReadWriteFile::read_file(std::ifstream& in){
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

    in.close();
}

std::map<std::string, char> ReadWriteFile::get_decode_map(){
    return this->decode_map;
}

std::string ReadWriteFile::get_encoded_text(){
    return this->encoded_text;
}

void ReadWriteLZ77::save_file(const std::vector<std::unique_ptr<Pointer>>& encoded, std::string path){
    path += "/encoded_data.bin";
    std::ofstream out(path, std::ios::binary);

    if (!out){
        std::cerr << "Invalid path! \n";
        out.close();
        return;
    }

    char type = '2';
    out.write(reinterpret_cast<char*>(&type), sizeof(type));

    size_t encoded_size = encoded.size();
    out.write(reinterpret_cast<const char*>(&encoded_size), sizeof(encoded_size));
    for (const auto& ptr : encoded){
        const char character = ptr->get_character();

        uint16_t offset = ptr->get_offset() & 0x0FFF;
        uint16_t length = ptr->get_length() & 0x0F;

        uint16_t offset_length = offset << 4 | length;

        out.write(reinterpret_cast<const char*>(&offset_length), sizeof(offset_length));

        out.write(reinterpret_cast<const char*>(&character), sizeof(character));
    }

    out.close();
}

void ReadWriteLZ77::read_file(std::ifstream& in){
    size_t pointers_size ;
    in.read(reinterpret_cast<char*>(&pointers_size), sizeof(pointers_size));
    for (int i = 0; i < pointers_size; i++){
        uint16_t offset_length;
        in.read(reinterpret_cast<char*>(&offset_length), sizeof(offset_length));
        
        int length = static_cast<int>(offset_length & 0x0F);
        int offset = static_cast<int>((offset_length >> 4) & 0x0FFF);

        char character;
        in.read(reinterpret_cast<char*>(&character), sizeof(character));

        this->pointers.push_back(std::make_unique<Pointer>(offset, length, character));
    }

    in.close();
}