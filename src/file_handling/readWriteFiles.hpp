#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include "../lz77/lz77.hpp"

class ReadWriteFile{
    public:
        ReadWriteFile();
        ~ReadWriteFile() = default;

        void save_file(std::string, std::map<std::string, char>, std::string);

        void read_file(std::string);

        std::map<std::string, char> get_decode_map();

        std::string get_encoded_text();
    private:
        std::map<std::string, char> decode_map;
        std::string encoded_text;
};

class ReadWriteLZ77{
    public:
    ReadWriteLZ77(){};
    ~ReadWriteLZ77() = default;

    std::vector<std::unique_ptr<Pointer>> pointers;

    void save_file(const std::vector<std::unique_ptr<Pointer>>&, std::string);
    void read_file(std::string);

};