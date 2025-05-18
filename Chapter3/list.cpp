#include <iostream>
#include <list>

// Stdout
// [1; 2] [3; 4] [5; 6] 
// [0; 0] [1; 2] [3; 4] [5; 6] [7; 8] 
// [0; 0] [1; 2] [-1; -1] [3; 4] [5; 6] [7; 8] 

struct Point
{
    int x = 0;
    int y = 0;
};

void print_points(std::list<Point> &points) {
    for (auto &point: points) {
        std::cout << "[" << point.x << "; " << point.y << "] ";
    }
    std::cout << std::endl;
}

int main() {
    std::list <Point> points = {Point{1, 2}, Point{3, 4}, Point{5, 6}};
    print_points(points);

    points.push_back(Point{7, 8});
    points.push_front(Point{0, 0});
    print_points(points);

    points.insert(std::next(points.begin(), 2), Point{-1, -1});
    print_points(points);
}
