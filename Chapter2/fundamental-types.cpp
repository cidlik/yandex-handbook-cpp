#include <iostream>
#include <numeric>

int main() {
    std::cout
        << "int: size = " << sizeof(int)
        << " min = " << std::numeric_limits<int>::min()
        << " max = " << std::numeric_limits<int>::max()
        << std::endl;
    std::cout
        << "unsigned int: size = " << sizeof(unsigned int)
        << " min = " << std::numeric_limits<unsigned int>::min()
        << " max = " << std::numeric_limits<unsigned int>::max()
        << std::endl;
    std::cout
        << "short int: size = " << sizeof(short int)
        << " min = " << std::numeric_limits<short int>::min()
        << " max = " << std::numeric_limits<short int>::max()
        << std::endl;
}

// Linux ... 4.18.0-513.el8.x86_64 #1 SMP Fri Aug 25 14:33:28 UTC 2023 x86_64 x86_64 x86_64 GNU/Linux

// int: size = 4 min = -2147483648 max = 2147483647
// unsigned int: size = 4 min = 0 max = 4294967295
// short int: size = 2 min = -32768 max = 32767
