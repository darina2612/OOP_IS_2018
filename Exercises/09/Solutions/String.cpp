#include "String.h"

static String::size_type _strlen(const char* str)
{
    String::size_type len = 0;
    while(str && *str != '\0')
    {
        str++;
        len++;
    }
    return len;
}

String::String()
{
    _emptyString();
}

String::~String()
{
    _erase();
}

String::String(const char* cstr)
{
    _emptyString();
    _copy(cstr);
}

String::String(const String& other)
{
    _emptyString();
    _copy(other.data());
}

String::char_type* String::data()
{
    return m_data;
}

const String::char_type* String::data() const
{
    return m_data;
}

void String::clear()
{
    m_data[0] = '\0';
    m_size = 0;
}

String::size_type String::length() const
{
    return m_size;
}

String::size_type String::capacity() const
{
    return m_capacity;
}

bool String::empty() const
{
    return m_size == 0;
}

String::char_type& String::operator[](size_type idx)
{
    return m_data[idx];
}

const String::char_type& String::operator[](size_type idx) const
{
    return m_data[idx];
}

String& String::operator=(const String& rhs)
{
    if(this != &rhs)
    {
        *this = rhs.data();
    }
    return *this;
}

String& String::operator=(const char* rhs)
{
    clear();
    if(rhs != nullptr)
    {
        _copy(rhs);
    }
    return *this;
}

String& String::operator=(const char rhs)
{
    clear();
    _append(rhs);
    return *this;
}

String& String::operator+=(String& rhs)
{
    *this += rhs.data();
    return *this;
}

String& String::operator+=(const char* rhs)
{
    if(rhs != nullptr)
    {
        size_type len = _strlen(rhs);
        for(size_type i = 0; i < len; i++)
        {
            _append(rhs[i]);
        }
    }
    return *this;
}

String& String::operator+=(char rhs)
{
    _append(rhs);
    return *this;
}

String String::operator+(String& rhs)
{
    return String(*this) += rhs;
}

String String::operator+(const char* rhs)
{
    return String(*this) += rhs;
}

String String::operator+(char rhs)
{
    return String(*this) += rhs;
}

void String::_erase()
{
    if(m_data != nullptr)
    {
        delete[] m_data;
    }
}

void String::_resize(size_type new_size)
{
    if(new_size > m_capacity)
    {
        char_type* temp  = new char_type[new_size + 1];
        for(size_type i = 0; i < m_size; i++)
        {
            temp[i] = m_data[i];
        }
        delete[] m_data;
        m_data = temp;
        temp[m_size] = '\0';
        m_capacity = new_size;
    }
    else
    {
        m_size = new_size;
        m_data[m_size] = '\0';
    }
}

void String::_copy(const char* other)
{
    clear();
    size_type len = _strlen(other);
    for(size_type idx = 0; idx < len; idx++)
    {
        _append(other[idx]);
    }
}

void String::_append(char to_append)
{
    if(m_size + 1 > m_capacity)
    {
        _resize((m_capacity + 1) * 2);
    }
    m_data[m_size] = to_append;
    m_size++;
    m_data[m_size] = '\0';
}

void String::_emptyString()
{
    if(m_data != nullptr)
    {
        delete[] m_data;
    }

    m_data = new char[1];
    *m_data = '\0';
}

std::ostream& operator<<(std::ostream& os, const String& data)
{
    os << data.data();
    return os;
}

std::istream& operator>>(std::istream& is, String& data)
{
    data.clear();
    char to_add = '\0';
    while((to_add = (char)is.peek()) == ' ')
    {
        is.get();
    }
    //
    while((to_add = is.get()) != ' ' && to_add != '\n')
    {
        data._append(to_add);
    }
    return is;
}
