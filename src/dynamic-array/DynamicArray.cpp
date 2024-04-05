#include "DynamicArray.h"
#include <format>
#include <algorithm>

template<typename T>
DynamicArray<T>::DynamicArray(size_t size): _size(size) {
    _array = new T[size];
}

template<typename T>
DynamicArray<T>::DynamicArray(size_t size, const T *other) : _size(size) {
    _array = new T[size];
    std::copy_n(other, _size, _array);
}

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T> &other) {
    _size = other._size;
    _array = new T[_size];
    std::copy_n(other._array, _size, _array);
}

template<typename T>
std::istream &operator>>(std::istream &in, DynamicArray<T> &arr) {
    for (int i = 0; i < arr._size; i++) {
        in >> arr._array[i];
    }
    return in;
}

template<typename K>
std::ostream &operator<<(std::ostream &out, const DynamicArray<K> &array) {
    if (std::is_same_v<K, std::string>) {
        out << '{';
        for (int i = 0; i < array._size; i++) {
            out << '"' << array._array[i] << '"';
            if (i != array._size - 1) {
                out << ", ";
            }
        }
        out << '}';
        return out;
    }

    if (std::is_same_v<K, char>) {
        out << '{';
        for (int i = 0; i < array._size; i++) {
            out << "'" << array._array[i] << "'";
            if (i != array._size - 1) {
                out << ", ";
            }
        }
        out << '}';
        return out;
    }

    out << '{';
    for (int i = 0; i < array._size; i++) {
        out << array._array[i];
        if (i != array._size - 1) {
            out << ", ";
        }
    }
    out << '}';
    return out;
}

template<typename T>
T &DynamicArray<T>::operator[](const int index) {
    if (index < 0) {
        return _array[_size + index];
    }
    return _array[index];
}

template<typename T>
DynamicArray<T> &DynamicArray<T>::operator=(const DynamicArray<T> &other) {
    if (this != &other) {
        delete _array;
        _size = other._size;
        _array = other._array;
    }
    return *this;
}

template<typename T>
bool DynamicArray<T>::operator==(const DynamicArray<T> &other) {
    if (_size != other._size) {
        return false;
    }
    for (int i = 0; i < _size; i++) {
        if (_array[i] != other._array[i]) {
            return false;
        }
    }
    return true;
}

template<typename T>
bool DynamicArray<T>::operator!=(const DynamicArray<T> &other) {
    return !this->operator==(other);
}

template<typename K>
K max(const DynamicArray<K> &array) {
    if (array._size == 0) {
        throw std::invalid_argument("max() arg is an empty sequence");
    }
    K mx = array._array[0];
    for (int i = 0; i < array._size; i++) {
        mx = std::max(mx, array._array[i]);
    }
    return mx;
}

template<typename K>
K min(const DynamicArray<K> &array) {
    if (array._size == 0) {
        throw std::invalid_argument("min() arg is an empty sequence");
    }
    K mn = array._array[0];
    for (int i = 0; i < array._size; i++) {
        mn = std::min(mn, array._array[i]);
    }
    return mn;
}

template<typename T>
void DynamicArray<T>::sort() {
    std::sort(_array, _array + _size);
}

template<typename T>
void DynamicArray<T>::reverse() {
    std::reverse(_array, _array + _size);
}


template<typename T>
int DynamicArray<T>::find_index(T value) {
    for (int i = 0; i < _size; ++i) {
        if (_array[i] == value)
            return i;
    }
    return -1;
}
