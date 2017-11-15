#include <string>
#include <vector>

using namespace std;

bool has_sum(vector<int>& vec, int sum);

bool has_sum(vector<int>& vec, int sum) {
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 1; j < vec.size(); j++) {
            if (i != j && vec.at(i) + vec.at(j) == sum) {
                return true;
            }
        }
    }

    return false;
}
