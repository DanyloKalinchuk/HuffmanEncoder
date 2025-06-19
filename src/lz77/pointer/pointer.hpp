#pragma once

class Pointer{
    const unsigned  int offset;
    const unsigned int length;
    const char character;

    public:
    Pointer(int, int, char);
    virtual ~Pointer() = default;

    Pointer(Pointer&&) = default;
    Pointer& operator=(Pointer&&) = default;

    Pointer(const Pointer&) = delete;
    Pointer& operator=(const Pointer&) = delete;


    int get_offset() const;
    int get_length() const;
    char get_character() const;
};