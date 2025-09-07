#include <vector>
#include <iostream>
#include <cassert>

////////////////////////
// 1304
// Find N Unique Integers Sum up to Zero
// https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/description/?envType=daily-question&envId=2025-09-07
// Easy
////////////////////////
// Runtime : 0s Beats 100%
// Memory  : 9.35MB Beats 100%
////////////////////////

#include <cmath>

class Solution {
public:
    std::vector<int> sumZero(int n) {

        std::vector<int> vec;
        int start = std::round(n/3) * -1;
        int total = -1;

        for (int i=0; i<n; ++i) {
            vec.push_back(start+i);
        }

        while (total != 0) {
            total = 0;
            for (int i=0; i<vec.size(); ++i) {
                total += vec[i];
            }
            if (total > 0) {
                vec[0] -= total;
            } else if (total < 0) {
                vec[vec.size()-1] += total;
            }
        }

        return vec;
    }
};

////////////////////////
// END 
////////////////////////

bool isZero(std::vector<int> vec) {
    int total = 0;
    for (int i=0; i<vec.size(); ++i) {
        total += vec[i];
    }   
    if (total == 0) return true;
    return false;
}

int main() {
    Solution test;
    
    assert(isZero(test.sumZero(5)));

    assert(isZero(test.sumZero(3)));

    assert(isZero(test.sumZero(1)));

    std::cout << std::endl << "All tests passed!" << std::endl << std::endl;
}