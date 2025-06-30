#pragma once

class Pointer{
    const unsigned int offset;
    const unsigned int length;
    const char character;

    public:
    Pointer(const unsigned int&, const unsigned int&, const char&);
    virtual ~Pointer() = default;

    Pointer(Pointer&&) = default;
    Pointer& operator=(Pointer&&) = default;

    Pointer(const Pointer&) = delete;
    Pointer& operator=(const Pointer&) = delete;


    unsigned int get_offset() const;
    unsigned int get_length() const;
    char get_character() const;
};