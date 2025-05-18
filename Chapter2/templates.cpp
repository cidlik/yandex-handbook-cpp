#include <iostream>
#include <string>

// Stdout
// 12
// 3.75
// 5
// abcabcabcabc
// abcabc
// -1 3 2

template <typename T>
T mul(const T& a, const T& b) {
    return a * b;
}

#if 1  // both give the same result
template <typename T>
#else
template <class T>
#endif
std::string mul(const std::string& s, const T& b) {
    std::string result = "";
    for (int i = 0; i < static_cast<int>(b); i++) {
        result += s;
    }
    return result;
}

template <typename T1, typename T2, typename T3>
struct Triple {
    T1 first;
    T2 second;
    T3 third;
};

int main() {
    std::cout << mul(3, 4) << std::endl;
    std::cout << mul(2.5, 1.5) << std::endl;
    /**
     * otherwise it provides an error:
     *   error: no matching function for call to 'mul'
     *   ...
     *   candidate template ignored: deduced conflicting types for parameter 'T' ('double' vs. 'int')
     */
    std::cout << mul<double>(2.5, 2) << std::endl;
    std::cout << mul("abc", 4) << std::endl;
    std::cout << mul("abc", 2.5) << std::endl;

    Triple<int, int, int> point = {-1, 3, 2};
    std::cout << point.first << " " << point.second << " " << point.third << std::endl;
}
