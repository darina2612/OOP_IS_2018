#pragma once

#include <cassert>
#include <cstdlib>

template <typename T>
class Vector
{
private:
    T* _elements  ;
    size_t _size;
    size_t _capacity;

    void copy(const Vector<T>& other);
    void freeMemory();

    void resize(size_t newCapacity);
public:
    Vector(size_t _capacity = 1);
    Vector(size_t capacity, const T& initialValue);

    Vector(const Vector<T>& other);
    Vector<T>& operator =(const Vector<T>& other);

    ~Vector();

    T& operator[](size_t index);
    T operator[](size_t index) const;

    void push_back(const T& element);
    T pop_back();

    bool empty();

    size_t size() const;
    size_t capacity() const;
};

template <typename T>
Vector<T>::Vector(size_t capacity)
{
    _capacity = capacity;
    _elements = new T[_capacity];
    _size = 0;
}

template <typename T>
Vector<T>::Vector(size_t capacity, const T& initialValue)
{
    _capacity = capacity;
    _elements = new T[_capacity];
    _size = 0;

    for(size_t i = 0; i < _capacity; ++i)
    {
        _elements[i] = initialValue;
    }
}

template <typename T>
Vector<T>::Vector(const Vector<T>& other)
{
    copy(other);
}

template <typename T>
Vector<T>& Vector<T>::operator =(const Vector<T>& other)
{
    if(this != &other)
    {
        freeMemory();
        copy(other);
    }

    return *this;
}

template <typename T>
Vector<T>::~Vector()
{
    freeMemory();
}

template <typename T>
void Vector<T>::copy(const Vector<T>& other)
{
    _capacity = other._capacity;
    _size = other._size;

    _elements = new T[_capacity];

    for(size_t i = 0; i < _size; ++i)
    {
        _elements[i] = other._elements[i];
    }
}

template <typename T>
void Vector<T>::freeMemory()
{
    delete [] _elements ;
}

template <typename T>
void Vector<T>::resize(size_t newCapacity)
{
    assert(newCapacity >= _size);

    _capacity = newCapacity;

    T* temp = new T[_capacity];

    for(size_t i = 0; i < _size; ++i)
    {
        temp[i] = _elements[i];
    }

    delete[] _elements;
    _elements = temp;
}

template <typename T>
T& Vector<T>::operator[] (size_t index)
{
    assert(index >= 0  && index < _size);

    return _elements[index];
}

template <typename T>
T Vector<T>::operator[](size_t index) const
{
    assert(index >= 0  && index < _size);

    return _elements[index];
}

template <typename T>
void Vector<T>::push_back(const T& elem)
{
    if(_size <= _capacity)
    {
        resize(_capacity * 2);
    }

    _elements[_size] = elem;
    ++_size;
}

template <typename T>
T Vector<T>::pop_back()
{
    assert(!empty());

    return _elements[size--];
}

template <typename T>
bool Vector<T>::empty()
{
    return _size > 0;
}

template <typename T>
size_t Vector<T>::size() const
{
    return _size;
}

template <typename T>
size_t Vector<T>::capacity() const
{
    return _capacity;
}
