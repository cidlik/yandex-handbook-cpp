#include <iostream>
#include <vector>

std::vector<int> get_vector(int len) {
    std::vector<int> data(len);
    int i = 0;
    for (auto &member: data) {
        member = i;
        i++;
    }
    return data;
}

int main() {
    std::vector<int> data = get_vector(5);
    for (auto member: data) {
        std::cout << member << std::endl;
    }

    data = get_vector(10);
    for (auto member: data) {
        std::cout << member << std::endl;
    }
}
