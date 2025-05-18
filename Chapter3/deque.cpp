#include <deque>
#include <iostream>

#include "common.h"

// Stdout:
// 4 5 6 
// 4 5 6 7 
// 3 4 5 6 7 
// 2 3 4 5 6 7 
// 1 1 1 2 3 4 5 6 7 
// 1 1 1 0 2 3 4 5 6 7 

int main() {
    std::deque<int> deque = {4, 5, 6};
    print(deque);

    deque.push_back(7);
    print(deque);
    deque.push_front(3);
    print(deque);

    deque.insert(deque.begin(), 2);
    print(deque);
    deque.insert(deque.begin(), 3, 1);
    print(deque);

    deque.insert(std::next(deque.begin(), 3), 0);
    print(deque);
}
