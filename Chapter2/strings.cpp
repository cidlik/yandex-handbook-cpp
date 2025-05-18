#include <iostream>
#include <string>

// Stdout:
// Some string functions
// string
// functions
// 4
// 11
// 5
// 18446744073709551615
// Some std::string functions
// Special std::string functions
// Special string functions

int main() {
    std::string s = "Some string";

    // приписывание символов и строк
    s += ' ';
    s += "functions";
    std::cout << s << "\n";

    // выделение подстроки
    // подстрока "string" из 6 символов начиная с 5-й позиции
    std::string sub1 = s.substr(5, 6);
    // подстрока "functions" с 12-й позиции и до конца
    std::string sub2 = s.substr(12);
    std::cout << sub1 << std::endl;
    std::cout << sub2 << std::endl;

    // поиск символа или подстроки
    size_t pos1 = s.find(' ');
    size_t pos2 = s.find(' ', pos1 + 1);
    size_t pos3 = s.find("str");
    size_t pos4 = s.find("#");
    std::cout << pos1 << std::endl;
    std::cout << pos2 << std::endl;
    std::cout << pos3 << std::endl;
    std::cout << pos4 << std::endl;

    // вставка подстроки
    s.insert(5, "std::");
    std::cout << s << "\n";

    // замена указанного диапазона на новую подстроку
    s.replace(0, 4, "Special");
    std::cout << s << "\n";

    // удаление подстроки
    s.erase(8, 5);
    std::cout << s << "\n";
}
