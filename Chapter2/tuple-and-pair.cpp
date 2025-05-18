#include <iostream>
#include <string>
#include <vector>
#include <utility>

int main() {
    std::pair<int, int> range1 = {1, 5}, range2;
    std::cout << "Range1: start = " << range1.first << " stop = " << range1.second << std::endl;
    std::cout << "Range2: start = " << range2.first << " stop = " << range2.second << std::endl;
    range2.swap(range1);
    std::cout << "Range1: start = " << range1.first << " stop = " << range1.second << std::endl;
    std::cout << "Range2: start = " << range2.first << " stop = " << range2.second << std::endl;

    std::cout << "=====================\n";
    std::tuple<std::string, int, bool> thing1 = {"foo", 4, false};
    std::cout << std::get<0>(thing1) << " " << std::get<1>(thing1) << " " << std::get<2>(thing1) << std::endl;
}
