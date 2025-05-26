#include <iostream>
#include "huffmanEncoder.hpp"

using namespace std;

int main(){
    cout << "Provide text for encoding" << "\n";

    string sample;
    getline(cin, sample);

    HuffmanEncoder encoder;

    string encoded = encoder.encode(sample);

    cout << encoded << "\n" << "bits used: " << encoded.size() << "\n" << "\n";
    
    string original = encoder.get_original();

    cout << original << "\n";

    system("pause");

    return 0;
}