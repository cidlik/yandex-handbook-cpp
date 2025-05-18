#include <iostream>
#include <vector>
#include <string>

// Stdout:
// HelloWorld
// 123

std::string concat(std::vector<std::string> &vec) {
    std::string result = "";
    for (const auto& row: vec) {
        result += row;
    }
    return result;
}

#if 1
std::string concat(std::vector<int> &vec) {
    std::string result = "";
    for (const auto& row: vec) {
        result += std::to_string(row);
    }
    return result;
}
#else
// error: functions that differ only in their return type cannot be overloaded
int concat(std::vector<int> &vec) {
    std::string result = "";
    for (const auto& row: vec) {
        result += std::to_string(row);
    }
    return std::stoi(result);
}
#endif

int main() {
    std::vector<std::string> sVec = {"Hello", "World"};
    std::vector<int> iVec = {1, 2, 3};

    std::cout << concat(sVec) << std::endl;
    std::cout << concat(iVec) << std::endl;
}
