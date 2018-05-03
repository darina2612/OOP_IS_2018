
template<typename value_type>
Vector<value_type>::Vector() = default;

template<typename value_type>
Vector<value_type>::~Vector()
{
    _erase();
}

template<typename value_type>
Vector<value_type>::Vector(const Vector& other)
{
    _copy(other);
}

template<typename value_type>
Vector<value_type>& Vector<value_type>::operator=(const Vector& rhs)
{
    if(this != &rhs)
    {
        _copy(rhs);
    }
    return *this;
}

template<typename value_type>
void Vector<value_type>::push_back(const value_type& to_add)
{
    if(m_size + 1 > m_capacity)
    {
        if(m_capacity == 0)
        {
            _resize(2);
        }
        else
        {
            _resize(m_capacity * 2);
        }
    }
    m_data[m_size] = to_add;
    m_size++;
}

template<typename value_type>
void Vector<value_type>::pop_back()
{
    if(m_size > 0)
    {
        --m_size;
    }
}

template<typename value_type>
bool Vector<value_type>::empty() const
{
    return m_size == 0;
}

template<typename value_type>
void Vector<value_type>::clear()
{
    m_size = 0;
}

template<typename value_type>
void Vector<value_type>::_erase()
{
    if(m_data != nullptr)
    {
        delete[] m_data;
    }
}

template<typename value_type>
typename Vector<value_type>::size_type Vector<value_type>::get_size() const
{
    return m_size;
}

template<typename value_type>
typename Vector<value_type>::size_type Vector<value_type>::get_capacity() const
{
    return m_capacity;
}

template<typename value_type>
value_type* Vector<value_type>::get_data()
{
    return m_data;
}

template<typename value_type>
const value_type* Vector<value_type>::get_data() const
{
    return m_data;
}

template<typename value_type>
value_type& Vector<value_type>::operator[](size_type idx)
{
    return m_data[idx];
}

template<typename value_type>
const value_type& Vector<value_type>::operator[](size_type idx) const
{
    return m_data[idx];
}

template<typename value_type>
void Vector<value_type>::_copy(const Vector& other)
{
    clear();
    for(size_type i = 0; i < other.get_size(); i++)
    {
        push_back(other[i]);
    }
}

template<typename value_type>
void Vector<value_type>::_resize(size_type new_size)
{
    if(new_size <= m_capacity)
    {
        m_size = new_size;
    }
    else
    {
        value_type* temp = new value_type[new_size];
        for(size_type i = 0; i < m_size; i++)
        {
            temp[i] = m_data[i];
        }
        //
        delete[] m_data;
        m_data = temp;
        m_capacity = new_size;
    }
}
