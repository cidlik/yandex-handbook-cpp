#include <iostream>

int main() {
    std::cout << 10 + 3 << std::endl;  // 13
    std::cout << 10 - 3 << std::endl;  // 7
    std::cout << 10 * 3 << std::endl;  // 30
    std::cout << 10 / 3 << std::endl;  // 3
    std::cout << 10 % 3 << std::endl;  // 1

    std::cout << (double)10 / 3 << std::endl;  // 3.33333
    std::cout << static_cast<double>(10) / 3 << std::endl;  // 3.33333
    std::cout << 10 * 1.0f / 3 << std::endl;  // 3.33333
}
