#include <iostream>
#include "src/dynamic-array/DynamicArray.cpp"
#include "src/secure-dynamic-array/SecureDynamicArray.cpp"
#include <string>

int main() {
    auto a = new int[]{1, 2, 3, 4, 5};
    SecureDynamicArray arr(5, a);
    delete[] a;
    std::cout << "arr: " << arr << "\n";

    SecureDynamicArray<std::string> brr(4);
    brr[0] = "abc";
    brr[1] = "def";
    brr[2] = "ghi";
    brr[100] = "jkl";
    std::cout << "brr: " << brr << "\n";

    DynamicArray crr(brr);
    std::cout << "crr: " << crr << "\n";

    std::cout << "crr == brr: " << (crr == brr) << "\n";
    std::cout << "crr != brr: " << (crr != brr) << "\n";

    std::cout << "max(arr): " << max(arr) << "\n";
    std::cout << "min(brr): " << min(brr) << "\n";


    crr.sort();
    std::cout << "crr: " << crr << "\n";
    crr.reverse();
    std::cout << "crr: " << crr << "\n";

    std::cout << "brr.find_index(\"ghi\"): " << brr.find_index("ghi") << "\n";
    std::cout << "arr.find_index(666): " << arr.find_index(666) << "\n";
    return 0;
}