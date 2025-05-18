#include <iostream>
#include <string>

// Stdout:
// H       72
// e       101
// l       108
// l       108
// o       111

int main() {
    std::string line = "Hello";
    for (char symbol : line) {
        std::cout << symbol << "\t" << static_cast<int>(symbol) << "\n";
    }
}
