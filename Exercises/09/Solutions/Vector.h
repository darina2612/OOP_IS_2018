#ifndef VECTOR_H
#define VECTOR_H

template<typename value_type>
class Vector
{
public:
    using size_type = unsigned long long;

    Vector();
    ~Vector();

    Vector(const Vector& other);
    Vector& operator=(const Vector& rhs);

    void push_back(const value_type& to_add);
    void pop_back();

    bool empty() const;
    void clear();

    size_type get_size() const;
    size_type get_capacity() const;
    value_type* get_data();
    const value_type* get_data() const;
    value_type& operator[](size_type idx);
    const value_type& operator[](size_type idx) const;
private:
    void _erase();
    void _copy(const Vector& other);
    void _resize(size_type new_size);
    value_type* m_data = nullptr;
    size_type m_size = 0;
    size_type m_capacity = 0;
};

#include "Vector.hpp"

#endif // VECTOR_H
