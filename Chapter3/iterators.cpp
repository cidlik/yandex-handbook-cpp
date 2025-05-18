#include <iostream>
#include <list>
#include <string>

struct Human
{
    std::string name;
    int age;
    std::string sex;
};


void print_people(std::list<Human> &people) {
// both approaches are equal
#if 1
    for (std::list<Human>::iterator it = people.begin(); it != people.end(); ++it)
#else
    for (auto it = people.begin(); it != people.end(); ++it)
#endif
    {
        std::string pronoun = it->sex == "male" ? "he" : "she";
        std::cout << "This is " << it->name << " and " << pronoun << "'s " << it->age << std::endl;
    }
}


int main() {
    std::list<Human> people = {
        Human{"Oleg", 42, "male"},
        Human{"Natasha", 35, "female"},
        Human{"Vasya", 18, "male"},
        Human{"Alina", 23, "female"},
    };
    print_people(people);

    std::cout << "=========================" << std::endl;

// this's wrong approach, because
#if 1
    for (auto it = people.begin(); it != people.end(); ++it) {
        if (it->age > 30) {
            it = people.erase(it);
        }
    }
#else
    for (auto it = people.begin(); it != people.end();) {
        if (it->age > 30) {
            it = people.erase(it);
        } else {
            ++it;
        }
    }
#endif
    print_people(people);
}
