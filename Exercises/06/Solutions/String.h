#pragma once

#include <cstddef> //size_t is declard here

class String
{
private:
    size_t capacity;
    size_t size;
    char* data;

    void copy(const String& other);
    void freeMemory();

public:
    String();
    String(const char* str);

    String(const String& other);
    String& operator =(const String& other);

    ~String();

    bool operator == (const String& other) const;

    size_t length() const;
};
