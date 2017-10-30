#include "lcs.hpp"

int lcs_rec(const std::string str1, const std::string str2) {
    if (str1.size() == 0 || str2.size() == 0) {
        return 0;
    }

    if (str1.back() == str2.back()) {
        return 1 + lcs_rec(str1.substr(0, str1.size() - 1),
                       str2.substr(0, str2.size() - 1));
    } else {
        return std::max(lcs_rec(str2, str1.substr(0, str1.size() - 1)),
                        lcs_rec(str1, str2.substr(0, str2.size() - 1)));
    }
}

int lcs_mem(const std::string str1, const std::string str2) {
    std::vector<std::vector<int>> LCS(str1.size() + 1, std::vector<int>(str2.size() + 1));

    for (int i = 0; i <= str1.size(); i++) {
        for (int j = 0; j <= str2.size(); j++) {
            if (i == 0 || j == 0) {
                LCS[i][j] = 0;
            } else if (str1.at(i - 1) == str2.at(j - 1)) {
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
            } else {
                LCS[i][j] = std::max(
                    LCS[i - 1][j],
                    LCS[i][j - 1]
                );
            }
        }
    }

    return LCS[str1.size()][str2.size()];
}
