#ifndef STRING_H
#define STRING_H

#include <iostream>

class String
{
public:
    using size_type = unsigned long long;
    using char_type = char;

    String();
    ~String();
    String(const char* cstr);
    String(const String& other);

    char_type* data();
    const char_type* data() const;

    void clear();
    size_type length() const;
    size_type capacity() const;
    bool empty() const;

    char_type& operator[](size_type idx);
    const char_type& operator[](size_type idx) const;

    String& operator=(const String& rhs);
    String& operator=(const char* rhs);
    String& operator=(const char rhs);

    String& operator+=(String& rhs);
    String& operator+=(const char* rhs);
    String& operator+=(char rhs);

    String operator+(String& rhs);
    String operator+(const char* rhs);
    String operator+(char rhs);

    friend std::ostream& operator<<(std::ostream& os, const String& data);
    friend std::istream& operator>>(std::istream& is, String& data);

private:
    void _erase();
    void _resize(size_type new_size);
    void _copy(const char* other);
    void _append(char to_append);
    void _emptyString();
    char_type* m_data = nullptr;
    size_type m_size = 0;
    size_type m_capacity = 0;

};

#endif // STRING_H
