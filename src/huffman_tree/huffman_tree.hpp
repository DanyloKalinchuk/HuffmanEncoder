#pragma once

#include "../node/node.hpp"
#include <vector>
#include <algorithm>

class HuffmanTree{
    public:
        std::unique_ptr<Node> root = nullptr;

        void nodes_to_tree(std::vector<std::unique_ptr<Node>>);
};