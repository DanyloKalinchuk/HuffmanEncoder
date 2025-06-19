#include "node.hpp"

Node::Node(char character, int frequency, std::unique_ptr<Node> left, std::unique_ptr<Node> right)
    : character(character), frequency(frequency), left(std::move(left)), right(std::move(right)) {}

int Node::get_frequency() const {
    return this->frequency;
}

char Node::get_character() const {
    return this->character;
}