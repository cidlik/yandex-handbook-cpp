#include <iostream>

enum class Colour {
    Red = 0,
    Green,
    Blue,

// TODO: Add operator << support
};

// Stdout:
// Colour 2
// Colour 0
// Colour 4
// Colour size = 4

int main() {
    Colour c1 = Colour::Blue;
    Colour c2 = Colour::Red;

    // std::cout << "Colour " << c1 << std::endl;  // no operator "<<" matches these operands error
    std::cout << "Colour " << static_cast<int>(c1) << std::endl;
    std::cout << "Colour " << static_cast<int>(c2) << std::endl;

    Colour c3 = static_cast<Colour>(4);
    std::cout << "Colour " << static_cast<int>(c3) << std::endl;

    std::cout << "Colour size = " << sizeof(Colour) << std::endl;
}
