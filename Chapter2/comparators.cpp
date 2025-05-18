#include <iostream>
#include <vector>
#include <algorithm>

// Stdout:
// 2024.1.12
// 2025.1.12
// 2025.1.12
// 2025.1.13
// 2025.2.12
// ===========================
// 2024.1.12
// 2025.1.12
// 2025.1.12
// 2025.2.12
// 2025.1.13
// ===========================
// 2024.1.12
// 2025.1.12
// 2025.1.12
// 2025.1.13
// 2025.2.12

struct Date
{
    int year;
    int month;
    int day;
};

/**
 * lhs - left-hand side
 * rhs - right-hand side
 */
bool operator < (const Date& lhs, const Date& rhs) {
#if LONG_TERM_WAY
    if (rhs.year != lhs.year) {
        return rhs.year > lhs.year;
    }
    if (rhs.month != lhs.month) {
        return rhs.month > lhs.month;
    }
    return rhs.day > lhs.day;
#else
    return std::tie(lhs.year, lhs.month, lhs.day) < std::tie(rhs.year, rhs.month, rhs.day);
#endif
}


bool compareByDay(const Date& lhs, const Date& rhs) {
    return rhs.day > lhs.day;
}


int main() {
    std::vector<Date> dates = {
        {2025, 1, 12},
        {2024, 1, 12},
        {2025, 2, 12},
        {2025, 1, 13},
        {2025, 1, 12},
    };

    std::sort(dates.begin(), dates.end());
    for (const auto &date: dates) {
        std::cout << date.year << "." << date.month << "." << date.day << std::endl;
    }

    std::cout << "===========================\n";

    // via the callback
    std::sort(dates.begin(), dates.end(), compareByDay);
    for (const auto &date: dates) {
        std::cout << date.year << "." << date.month << "." << date.day << std::endl;
    }

    std::cout << "===========================\n";

    // over the lambda
    std::sort(dates.begin(), dates.end(), [](const Date& lhs, const Date& rhs){
        return rhs.month > lhs.month;
    });
    for (const auto &date: dates) {
        std::cout << date.year << "." << date.month << "." << date.day << std::endl;
    }
}
