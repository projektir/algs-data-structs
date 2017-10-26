#include <iostream>

#include "list.hpp"

using ads::List;

int main() {
    List list;
    list.insert(3);
    list.insert(5);
    list.insert(15);

    std::cout << list << std::endl;

    int blar;
    std::cin >> blar;
    std::cin >> blar;

    return 0;
}
