#include <iostream>
#include <fstream>
#include <string>
#include <map>

class ReadWriteFile{
    public:
        void save_file(std::string, std::map<std::string, char>, std::string);

        void read_file(std::string);

        std::map<std::string, char> get_decode_map();

        std::string get_encoded_text();

        ReadWriteFile();
    private:
        std::map<std::string, char> decode_map;
        std::string encoded_text;
};