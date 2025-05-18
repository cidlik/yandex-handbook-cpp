#include <iostream>
#include <string>
#include <vector>

int main() {
    std::cout << "What's your name?\n";
    // It provides an error
    // "What's your name?\n" >> std::cout;

    std::string name;
    // std::cin >> name;  // read one word
    std::getline(std::cin, name);  // read whole line
    // It provides an error
    // name << std::cin;
    std::cout << "Hello, " << name << "!\n";

    // Use Ctrl+D to send EOF
    std::vector<std::string> lines;
    std::string tmp;
    for (std::string line; getline(std::cin, line);) {
        lines.push_back(line);
    }
    for (auto line: lines) {
        std::cout << line << std::endl;
    }
}
