#include <iostream>

#define ITERATIONS 0

// Stdout:
// While loop
//
// Do-While loop
// 1       1

int main() {
    int n = 1;

    std::cout << "While loop\n";
    while (n <= ITERATIONS) {
        std::cout << n << "\t" << n * n << "\n";
        ++n;
    }

    std::cout << "\nDo-While loop\n";
    n = 1;
    do {
        std::cout << n << "\t" << n * n << "\n";
        ++n;
    } while (n <= ITERATIONS);
}
