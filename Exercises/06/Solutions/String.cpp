#include "String.h"

#include <cstring>
#include <cassert>

String::String()
{
    size = capacity = 1;

    data = new char[capacity];
    data[0] = '\0';
}

String::String(const char* str)
{
    size = capacity = strlen(str);

    data = new char[capacity];
    strcpy(data, str);
}

String::String(const String& other)
{
    copy(other);
}

String& String::operator =(const String& other)
{
    if(this != &other)
    {
        freeMemory();
        copy(other);
    }

    return *this;
}

String::~String()
{
    freeMemory();
}

void String::copy(const String& other)
{
    size = other.size;
    capacity = other.capacity;

    data = new char[capacity];
    strcpy(data, other.data);
}

void String::freeMemory()
{
    delete[] data;
}

size_t String::length() const
{
    assert(size >= 1);

    return size - 1;
}

bool String::operator == (const String& other) const
{
    return strcmp(data, other.data) == 0;
}
