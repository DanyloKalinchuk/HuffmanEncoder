#pragma once

#include "readWriteFiles.hpp"
#include "../huffman_encoder/huffmanEncoder.hpp"

namespace en_decoding{
    void encode(const std::string&, const std::string&, const int&);
    std::string decode(const std::string&);
};