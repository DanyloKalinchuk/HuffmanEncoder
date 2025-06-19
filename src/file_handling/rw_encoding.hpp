#pragma once

#include "readWriteFiles.hpp"
#include "../huffman_encoder/huffmanEncoder.hpp"

namespace huffman_coding{
    void encode(const std::string&, const std::string&);
    std::string decode(const std::string&);
};

namespace lz77_coding{
    void encode(const std::string&, const std::string&);
    std::string decode(const std::string&);
};