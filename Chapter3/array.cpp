#include <array>
#include <algorithm>
#include <iostream>

#include "common.h"

// Stdout:
// 3 2 1 
// 1 2 3 
// 3 2 1 
// Size = 3
// Is empty = 0
// 45 45 45 

int main() {
    std::array <int, 3> array = {3, 2, 1};
    print(array);

    std::sort(array.begin(), array.end());
    print(array);

    std::sort(array.rbegin(), array.rend());
    print(array);

    std::cout << "Size = " << array.size() << std::endl;
    std::cout << "Is empty = " << array.empty() << std::endl;

    array.fill(45);
    print(array);
}

