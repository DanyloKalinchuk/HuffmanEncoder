#include <iostream>
#include <stdlib.h> 
#include "huffmanEncoder.hpp"
#include "readWriteFiles.hpp"

using namespace std;

int main(){

    while (true){
        cout << "Choose the option: \n \'1\' - Encode text \n \'2\' - Decode text from file \n \'3\' To exit the app \n";
        string input;
        cin >> input;

        system ("CLS");
        if (input == "1"){
            cout << "Print text for encoding \n";
            cin >> input;

            system ("CLS");
            cin >> input;

            HuffmanEncoder encoder;
            encoder.encode(input);

            cout << "Provide path for the output \n";
            cin >> input;

            ReadWriteFile file_reader;
            file_reader.save_file(encoder.get_encoded_text(), encoder.get_decode_map(), input);
        }

        else if (input == "2"){
            cout << "Provide path to a .bin file with an encoded text \n";
            cin >> input;

            ReadWriteFile file_reader;
            file_reader.read_file(input);

            input = decode_huffman(file_reader.get_decode_map(), file_reader.get_encoded_text());
            cout << "Decoded text: \n" << input;
        }
        else if (input == "3"){
            break;
        }
    }
    
    return 0;
}