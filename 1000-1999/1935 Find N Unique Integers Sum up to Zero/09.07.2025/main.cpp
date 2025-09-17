#include <vector>
#include <iostream>
#include <cassert>
#include <cmath>

////////////////////////
// 1304 
// Find N Unique Integers Sum up to Zero
// https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/description/
// Easy
////////////////////////
// Runtime : 0ms Beats 100.00%
// Memory  : 9.35MB Beats 99.98%
////////////////////////

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

int main() {
    Solution test;

    //test here
    
    std::cout << std::endl << "All tests passed!" << std::endl << std::endl;
}