#include <iostream>
#include <string>
#include <vector>
#include <string>

// Don't do this in a real program
using namespace std;

void swap(int& x, int& y) {
    auto temp = x;
    x = y;
    y = temp;
}

vector<string> split(const string& str, const string& delimiter) {
    string copy = str;
    vector<string> parts;

    size_t index = copy.find(delimiter);
    while (index != string::npos) {
        auto part = copy.substr(0, index);
        if (!part.empty()) {
            parts.push_back(part);
        }
        
        copy = copy.substr(index + delimiter.size(), copy.size() - index + delimiter.size());
        index = copy.find(delimiter);
    }

    if (!copy.empty()) {
        parts.push_back(copy);
    }

    return parts;
}

vector<int> insertion_sort(vector<int> vec) {
    for (int i = 1; i < vec.size(); i++) {
        for (int j = i; j > 0 && vec[j - 1] > vec[j]; j--) {
            swap(vec[j], vec[j - 1]);
        }
    }

    return vec;
}

vector<int> selection_sort(vector<int> vec) {
    for (int i = 0; i < vec.size() - 1; i++) {
        auto min_index = i;

        for (int j = i + 1; j < vec.size(); j++) {
            if (vec[j] < vec[min_index]) {
                min_index = j;
            }
        }

        swap(vec[min_index], vec[i]);
    }

    return vec;
}

int main() {
    string line;

    vector<int> sorted;
    
    getline(cin, line);
    auto str_numbers = split(line, " ");
    vector<int> numbers;

    for (auto iter = str_numbers.begin(); iter != str_numbers.end(); iter++) {
        numbers.push_back(stoi(*iter));
    }

    //sorted = insertion_sort(numbers);
    sorted = selection_sort(numbers);

    return 0;
}
