#include <iostream>
#include <string>

int main() {
    std::string s1 = "Hello, world!";
    std::string s2 = s1;
    s1.clear();
    std::cout << "s1: " << s1 << std::endl << "s2: " << s2 << std::endl;

    std::string s3 = "Hello, world!";
    std::string &s4 = s3;
    s3.clear();  // has the same effect as s4.clear()
    std::cout << "s3: " << s3 << std::endl << "s4: " << s4 << std::endl;
}
