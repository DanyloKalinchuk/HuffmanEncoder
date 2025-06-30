#include <iostream>
#include <stdlib.h> 
#include "huffman_encoder/huffmanEncoder.hpp"
#include "lz77/lz77.hpp"
#include "file_handling/rw_encoding.hpp"

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
            string text = input;

            cout << "Provide path for the output \n";
            cin >> input;

            en_decoding::encode(text, input, 2);
        }

        else if (input == "2"){
            cout << "Provide path to a .bin file with an encoded text \n";
            cin >> input;

            input = en_decoding::decode(input);
            cout << "Decoded text: \n" << input;
        }
        else if (input == "3"){
            break;
        }
    }
    
    return 0;
}