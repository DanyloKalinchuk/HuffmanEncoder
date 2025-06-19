#include "huffman_tree.hpp"

void HuffmanTree::nodes_to_tree(std::vector<std::unique_ptr<Node>> nodes){
    while (nodes.size() > 1){
        std::unique_ptr<Node> left = std::move(nodes.back());
        nodes.pop_back();

        std::unique_ptr<Node> right = std::move(nodes.back());
        nodes.pop_back();

        std::unique_ptr<Node> to_add = std::make_unique<Node>('\0', right->get_frequency() + left->get_frequency(), std::move(left), std::move(right));

        nodes.push_back(std::move(to_add));

        sort(nodes.begin(), nodes.end(), [](const std::unique_ptr<Node>& a, const std::unique_ptr<Node>& b) {
        return a->get_frequency() > b->get_frequency();
        });
    }

    this->root = std::move(nodes[0]); 
}
