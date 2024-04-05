#include "../dynamic-array/DynamicArray.h"

template<typename T>
class SecureDynamicArray : public DynamicArray<T> {
public:
//    using DynamicArray<T>::operator[];

    explicit SecureDynamicArray(size_t size) : DynamicArray<T>(size) {}

    explicit SecureDynamicArray(size_t size, const T *other) : DynamicArray<T>(size, other) {}

    SecureDynamicArray(const SecureDynamicArray<T> &other) : DynamicArray<T>(other) {}

    T &operator[](int index);
};
