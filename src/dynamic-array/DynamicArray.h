#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <cstddef>
#include <ostream>
#include <iostream>

template<typename T>
class DynamicArray {
private:
    size_t _size{};
//    size_t _capacity{1};
    T *_array{};
public:
    ~DynamicArray() {
        delete[] _array;
    }

//    DynamicArray() = default;

    explicit DynamicArray(size_t size);

    explicit DynamicArray(size_t size, const T *other);

    DynamicArray(const DynamicArray<T> &other);

    template<typename K>
    friend std::istream &operator>>(std::istream &in, DynamicArray<K> &array);

    template<typename K>
    friend std::ostream &operator<<(std::ostream &out, const DynamicArray<K> &array);

    T &operator[](int index);

    DynamicArray<T> &operator=(const DynamicArray<T> &other);

    bool operator==(const DynamicArray<T> &other);

    bool operator!=(const DynamicArray<T> &other);

    template<typename K>
    friend K max(const DynamicArray<K> &array);

    template<typename K>
    friend K min(const DynamicArray<K> &array);

    void sort();

    void reverse();

    int find_index(T value);
};

#endif // DYNAMICARRAY_H