#include <iostream>
#include <string>
#include <vector>

using namespace std;

int ctoi(char ch) {
    return ch - '0';
}

int divisible_by_3(const string& bin_str);

// To check if a binary number is divisible by 3,
// Add up each digit while alternating the sign,
// And then check if the resulting sum is divisible by 3
int divisible_by_3(const string& bin_str) {
    if (bin_str.size() == 0) {
        return 0;
    }

    int alt_sum = 0;

    for (int i = 0; i < bin_str.size() - 1; i += 2) {
        alt_sum += ctoi(bin_str.at(i));
        alt_sum -= ctoi(bin_str.at(i + 1));
    }

    if (bin_str.size() % 2 != 0) {
        alt_sum += ctoi(bin_str.back());
    }

    if (alt_sum % 3 == 0) {
        return 1;
    } else {
        return 0;
    }
}
