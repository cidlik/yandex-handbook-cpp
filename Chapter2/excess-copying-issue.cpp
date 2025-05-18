#include <chrono>
#include <iostream>
#include <string>
#include <vector>

// Stdout
// Result = 10000000000
// Wrong way duration: 1257778us
// Result = 10000000000
// Correct way duration: 216us

#define STRING_NUM 100000
#define STRING_LEN 100000

int main() {
    std::vector<std::string> data(STRING_NUM);
    for (size_t i = 0; i != data.size(); ++i) {
        data[i].resize(STRING_LEN, 'A');
    }

    auto start_time = std::chrono::system_clock::now();
    size_t size = 0;
    for (auto row: data) {
        size += row.size();
    }
    std::cout << "Result = " << size << std::endl;
    auto duration = std::chrono::system_clock::now();
    std::cout \
        << "Wrong way duration: " \
        << std::chrono::duration_cast<std::chrono::microseconds>(duration - start_time) \
        << std::endl;

    start_time = std::chrono::system_clock::now();
    size = 0;
    for (const auto &row: data) {
        size += row.size();
    }
    std::cout << "Result = " << size << std::endl;
    duration = std::chrono::system_clock::now();
    std::cout \
        << "Correct way duration: " \
        << std::chrono::duration_cast<std::chrono::microseconds>(duration - start_time) \
        << std::endl;
}
