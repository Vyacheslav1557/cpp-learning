#include <format>
#include "SecureDynamicArray.h"


template<typename T>
T &SecureDynamicArray<T>::operator[](const int index) {
    if (index < 0 && index < -DynamicArray<T>::_size || index > 0 && index >= DynamicArray<T>::_size) {
        throw std::out_of_range(std::format("index {} out of range", index));
    }
    return DynamicArray<T>::operator[](index);
}