
#ifndef MYVECTOR_HPP
#define MYVECTOR_HPP

template <typename T>
MyVector<T>::MyVector(size_t s)
    : size(s), capacity(INITIAL_CAPACITY), data(new T[capacity]) {}

template <typename T>
MyVector<T>::MyVector(std::initializer_list<T> lst)
    : size(lst.size()), capacity(lst.size() + INITIAL_CAPACITY), data(new T[capacity])
{
    std::copy(lst.begin(), lst.end(), data);
}

template <typename T>
MyVector<T>::MyVector(const MyVector &other)
    : size(other.size), capacity(other.capacity), data(new T[other.capacity])
{
    std::copy(other.data, other.data + other.size, data);
}

template <typename T>
MyVector<T>::MyVector(MyVector &&other) noexcept
    : size(other.size), capacity(other.capacity), data(other.data)
{
    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;
}

template <typename T>
MyVector<T>::~MyVector()
{
    delete[] data;
}

template <typename T>
size_t MyVector<T>::getSize() const
{
    return size;
}

template <typename T>
T &MyVector<T>::operator[](size_t index)
{
    return data[index];
}

template <typename T>
T &MyVector<T>::operator[](size_t index) const
{
    return data[index];
}

template <typename T>
MyVector<T> &MyVector<T>::operator=(MyVector &&other)
{
    if (this != &other)
    {
        delete[] data;
        size = other.size;
        capacity = other.capacity;
        data = other.data;
        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;
    }
    return *this;
}

template <typename T>
void MyVector<T>::push_back(const T value)
{
    if (size >= capacity)
    {
        reserve(capacity * 2); // Raddoppia la capacità
    }
    data[size++] = value;
}

template <typename T>
void MyVector<T>::pop_back()
{
    if (size == 0)
    {
        throw std::out_of_range("Pop da vettore vuoto");
    }
    --size;
}

template <typename T>
T MyVector<T>::at(size_t index) const
{
    if (index >= size)
    {
        throw std::out_of_range("Indice fuori dai limiti");
    }
    return data[index];
}

template <typename T>
void MyVector<T>::reserve(size_t new_capacity)
{
    if (new_capacity > capacity)
    {
        T *new_data = new T[new_capacity];
        std::copy(data, data + size, new_data);
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }
}

#endif // MYVECTOR_HPP