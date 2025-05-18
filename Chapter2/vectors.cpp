// Docs: https://en.cppreference.com/w/cpp/container/vector

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

// Stdout:
// iVector: 1 2 3 4 
// iVector after push: 1 2 3 4 5 
// Value with 4 index = 5; reference to element = 5
// iVector after pop: 1 2 3 4 
// Value with 4 index = 5; reference to element = 
// std::out_of_range was handled

// ===========================
// sVector1:  
// sVector2: test test test test test 

// ===========================
// iVector size = 4
// iVector capacity = 8
// is sVector1 empty = 0
// is sVector3 empty = 1
// iVector first = 1; last = 4
// Iterate over indexes: 1 2 3 4 

// ===========================
// size = 1; cap = 1
// size = 2; cap = 2
// size = 3; cap = 4
// size = 4; cap = 4
// size = 5; cap = 8
// size = 4; cap = 8
// size = 3; cap = 8

// ===========================
// before sort: 3 1 5 6 4 3 2 
// after sort: 1 2 3 3 4 5 6 
// after reverse sort: 6 5 4 3 3 2 1 
// sort in C++20: 1 2 3 3 4 5 6 

// ===========================
// 0 0 
// 0 0 
// 0 0 

void printDelimeter() {
    std::cout << "\n===========================\n";
}

void printVector(std::vector<int> vector, std::string name)
{
    std::cout << name << ": ";
    for (auto e: vector) {
        std::cout << e << " ";
    }
    std::cout << std::endl;
}

void printVector(std::vector<std::string> vector, std::string name)
{
    std::cout << name << ": ";
    for (auto e: vector) {
        std::cout << e << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> iVector = {1, 2, 3, 4};
    printVector(iVector, "iVector");
    iVector.push_back(5);
    printVector(iVector, "iVector after push");
    std::cout << "Value with 4 index = " << iVector[4] << "; reference to element = "
        << iVector.at(4) << std::endl;
    iVector.pop_back();
    printVector(iVector, "iVector after pop");
    try {
        std::cout << "Value with 4 index = " << iVector[4] << "; reference to element = "
            << iVector.at(4) << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "\nstd::out_of_range was handled" << std::endl;
    }

    printDelimeter();
    std::vector<std::string> sVector1(1);
    printVector(sVector1, "sVector1");
    std::vector<std::string> sVector2(5, "test");
    printVector(sVector2, "sVector2");
    std::vector<std::string> sVector3;

    printDelimeter();
    std::cout << "iVector size = " << iVector.size() << std::endl;
    std::cout << "iVector capacity = " << iVector.capacity() << std::endl;
    std::cout << "is sVector1 empty = " << sVector1.empty() << std::endl;
    std::cout << "is sVector3 empty = " << sVector3.empty() << std::endl;
    std::cout << "iVector first = " << iVector.front()
        << "; last = " << iVector.back() << std::endl;

    std::cout << "Iterate over indexes: ";
    for (size_t i = 0; i != iVector.size(); ++i) {
        std::cout << iVector[i] << " ";
    }
    std::cout << std::endl;

    printDelimeter();
    std::vector<int> dynVector;
    dynVector.push_back(1);
    std::cout << "size = " << dynVector.size() << "; cap = " << dynVector.capacity() << std::endl;
    dynVector.push_back(1);
    std::cout << "size = " << dynVector.size() << "; cap = " << dynVector.capacity() << std::endl;
    dynVector.push_back(1);
    std::cout << "size = " << dynVector.size() << "; cap = " << dynVector.capacity() << std::endl;
    dynVector.push_back(1);
    std::cout << "size = " << dynVector.size() << "; cap = " << dynVector.capacity() << std::endl;
    dynVector.push_back(1);
    std::cout << "size = " << dynVector.size() << "; cap = " << dynVector.capacity() << std::endl;
    dynVector.pop_back();
    std::cout << "size = " << dynVector.size() << "; cap = " << dynVector.capacity() << std::endl;
    dynVector.pop_back();
    std::cout << "size = " << dynVector.size() << "; cap = " << dynVector.capacity() << std::endl;

    printDelimeter();
    std::vector<int> unsortedVector = {3, 1, 5, 6, 4, 3, 2};
    printVector(unsortedVector, "before sort");
    std::sort(unsortedVector.begin(), unsortedVector.end());
    printVector(unsortedVector, "after sort");
    std::sort(unsortedVector.rbegin(), unsortedVector.rend());
    printVector(unsortedVector, "after reverse sort");
#if __cplusplus >= 202002L  // https://stackoverflow.com/a/7132549
        std::ranges::sort(unsortedVector);
        printVector(unsortedVector, "sort in C++20");
#endif

    printDelimeter();
    std::vector<std::vector<int>> Vec2D(3, std::vector<int>(2, 0));
    for (const auto &row: Vec2D) {
        for (auto val: row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}
