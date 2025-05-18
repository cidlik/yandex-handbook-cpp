#include <iostream>

int main() {
    unsigned int ui = 123456;  // на 64-битной платформе sizeof(a) == 4
    unsigned long ul = ui;

    // Произведение a * a не помещается в 4 байта, так как оно больше 2^32
    std::cout << ui * ui << "\n";
    std::cout << ul * ul << "\n";

    int i = 123456;  // на 64-битной платформе sizeof(a) == 4
    long l = i;

    // Произведение a * a не помещается в 4 байта, так как оно больше 2^32
    std::cout << i * i << "\n";
    std::cout << l * l << "\n";
}

// 2356482048
// 15241383936
// test.cpp:15:20: runtime error: signed integer overflow: 123456 * 123456 cannot be represented in type 'int'
// SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior test.cpp:15:20 in 
// -1938485248
// 15241383936
