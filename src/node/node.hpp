#pragma once

#include <memory>

class Node{
    public:
        const char character;
        const int frequency;
        std::unique_ptr<Node> left = nullptr;
        std::unique_ptr<Node> right = nullptr;

        Node(char, int, std::unique_ptr<Node>, std::unique_ptr<Node>);
        virtual ~Node() = default;

        Node(Node&&) = default;
        Node& operator=(Node&&) = default;

        Node(const Node&) = delete;
        Node& operator=(const Node&) = delete;

        int get_frequency() const;
        char get_character() const;
};