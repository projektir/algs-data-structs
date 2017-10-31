#include <iostream>
#include <string>
#include <vector>
#include <regex>

void regex_test(const std::string& source) {
    //"(2,3), (4, 5), (9,10)"
    //std::regex re("\\([0-9],[0-0]\\)");

    //std::string s1("{1,2,3}{4,5,6}{7,8,9}");
    //std::regex e(R"~((\d+),(\d+),(\d+))~");

    // Match numbers
    std::regex re("\d+");
    std::sregex_iterator iter(source.begin(), source.end(), re);
    std::sregex_iterator end;

    std::vector<int> ints;

    while (iter != end)
    {
        for (int i = 1; i < iter->size(); i++) {
            ints.push_back(std::stoi((*iter)[i]));
        }       

        iter++;
    }
}

std::vector<std::string> split(const std::string& source, const std::string& delimiter) {
    auto source_copy = source;
    std::vector<std::string> strings;

    auto index = source_copy.find(delimiter);
    while (index != std::string::npos) {
        auto part = source_copy.substr(0, index);
        if (!part.empty()) {
            strings.push_back(part);
        }

        source_copy = source_copy.substr(index + delimiter.size(),
            source_copy.size() - index + delimiter.size());
        index = source_copy.find(delimiter);
    }

    if (!source_copy.empty()) {
        strings.push_back(source_copy);
    }

    return strings;
}

int main() {
    std::string line;
    
    while (std::getline(std::cin, line)) {
        auto strings = split(line, ", ");
        //strings.erase(strings.begin() + 3);

        regex_test(line);

        int blar = 3;
    }

    return 0;
}
