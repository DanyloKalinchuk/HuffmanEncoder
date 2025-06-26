#include "pointer.hpp"

Pointer::Pointer(const unsigned int& offset, const unsigned int& length, const char& character)
    : offset(offset), length(length), character(character) {}

unsigned int Pointer::get_offset() const{
    return this->offset;
}

unsigned int Pointer::get_length() const{
    return this->length;
}

char Pointer::get_character() const{
    return this->character;
}