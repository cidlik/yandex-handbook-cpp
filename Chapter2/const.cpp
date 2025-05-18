#include <iostream>
#include <random>
#include <ctime>

int main() {
    std::srand(std::time({}));  // set time as seed
    const int number = std::rand();
    std::cout << "Your constant random number is " << number << std::endl;
}
