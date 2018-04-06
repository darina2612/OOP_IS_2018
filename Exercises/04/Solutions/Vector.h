#pragma once

#include <cassert>

template <typename T>
class Vector
{
private:
    T* elements;
    size_t size;
    size_t capacity;

    void copy(const Vector<T>& other);
    void freeMemory();

    void resize(size_t newCapacity);
public:
    Vector(size_t capacity = 1);
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
    this->capacity = capacity;
    elements = new T[capacity];
    size = 0;
}

Vector::Vector(size_t capacity, const T& initialValue)
{
    this->capacity = capacity;
    elements = new T[capacity];
    size = 0;

    for(size_t i = 0; i < capacity; ++i)
    {
        elements[i] = initialValue;
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
    capacity = other.capacity;
    size = other.size;

    elements = new T[capacity];

    for(size_t i = 0; i < size; ++i)
    {
        this->elements[i] = other.elements[i];
    }
}

template <typename T>
void Vector<T>::freeMemory()
{
    delete [] this->elements;
}

template <typename T>
void Vector<T>::resize(size_t newCapacity)
{
    assert(newCapacity <= size);

    capacity = newCapacity;

    T* temp = new T[capacity];

    for(size_t i = 0; i < size; ++i)
    {
        temp[i] = elements[i];
    }

    delete[] elements;
    elements = temp;
}

template <typename T>
T& Vector<T>::operator[] (size_t index)
{
    assert(index >= 0  && index < size);

    return elements[index];
}

template <typename T>
T operator[](size_t index) const;
T& Vector<T>::operator[] (size_t index)
{
    assert(index >= 0  && index < size);

    return elements[index];
}

template <typename T>
void Vector<T>::push_back(T elem)
{
    if(size <= capacity)
    {
        resize(capacity * 2);
    }

    elements[size] = elem;
    ++size;
}

template <typename T>
T Vector<T>::pop_back()
{
    assert(!empty());

    return elements[size--];
}

template <typename T>
bool empty()
{
    return size > 0;
}

template <typename T>
size_t Vector<T>::size() const
{
    return size;
}

template <typename T>
size_t Vector<T>::capacity() const
{
    return capacity;
}
