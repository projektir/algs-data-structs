#include <iostream>
#include <string>
#include <vector>

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
        auto strings = split(line, " ");
        strings.erase(strings.begin() + 3);
        int blar = 3;
    }

    return 0;
}
