#include <iostream>
#include <string>

// Stdout
// start: x = 1 y = 2
// : x = 0 y = 0
// end: x = 42 y = -34
// Pi: x = 3.14 y = 0
// ======================
// double size = 8
// std::string size = 32
// bool size = 1
// Point size = 56

struct Point {
    double x = 0.0f;
    double y = 0.0f;
    std::string name;
    bool test = false;
};

void print_point(Point &p) {
    std::cout << p.name << ": x = " << p.x << " y = " << p.y << std::endl;
}

int main() {
    Point p1 = {1.0f, 2.0f, "start"};
    print_point(p1);

    Point p2;
    print_point(p2);
    p2.x += 42;
    p2.y -= 34;
    p2.name = "end";
    print_point(p2);

#if __cplusplus >= 202002L  // https://stackoverflow.com/a/7132549
    Point p3 = {.x = 3.14f, .name = "Pi"};
    print_point(p3);
#endif

    std::cout << "======================\n";
    std::cout << "double size = " << sizeof(double) << std::endl;
    std::cout << "std::string size = " << sizeof(std::string) << std::endl;
    std::cout << "bool size = " << sizeof(bool) << std::endl;
    std::cout << "Point size = " << sizeof(Point) << std::endl;
}
