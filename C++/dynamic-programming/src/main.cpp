#include <iostream>

#include "lcs.hpp"

int main() {
    std::string str1;
    std::cin >> str1;

    std::string str2;
    std::cin >> str2;

    std::cout << lcs_rec(str1, str2) << std::endl;
    std::cout << lcs_mem(str1, str2) << std::endl;

    int blar;
    std::cin >> blar;
    std::cin >> blar;

    return 0;
}
