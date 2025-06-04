#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

class ReadWriteFile{
    public:
        void save_file(string, map<string, char>, string);

        void read_file(string);

        map<string, char> get_decode_map();

        string get_encoded_text();

        ReadWriteFile();
    private:
        map<string, char> decode_map;
        string encoded_text;
};