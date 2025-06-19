#pragma once

#include <vector>
#include <string>
#include <memory>
#include "pointer/pointer.hpp"

namespace lz77{
    std::vector<std::unique_ptr<Pointer>> encode(std::string);
    std::string decode(const std::vector<std::unique_ptr<Pointer>>&);
};