#include "pointer.hpp"

Pointer::Pointer(int offset, int length, char character)
    : offset(offset), length(length), character(character) {}

int Pointer::get_offset() const{
    return this->offset;
}

int Pointer::get_length() const{
    return this->length;
}

char Pointer::get_character() const{
    return this->character;
}