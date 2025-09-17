#include <vector>
#include <iostream>
#include <cassert>

////////////////////////
// 2327
// Number of People Aware of a Secret
// https://leetcode.com/problems/number-of-people-aware-of-a-secret/description/
// Medium
////////////////////////
// Runtime : 0ms Beats 100.00%
// Memory  : 9.14MB Beats 94.95%
////////////////////////

#include <cmath>

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        std::vector<int> newers = {};
        newers.resize(n + 1);

        int knowers = 1;
        long long elgible = 0;
        int divisor = (int(std::pow(10, 9)) + 7);

        newers[1] = 1;

        // For every day
        for (int i = 2; i < n+1; ++i) {

            if (i - delay >= 0) {
                elgible += newers[i - delay];
            }

            if (i - forget >= 0) {
                elgible -= newers[i - forget];
            }

            newers[i] = elgible % divisor;
            knowers += newers[i];

            if (i - forget >= 0) {
                knowers -= newers[i - forget];
            }

            knowers = (knowers % divisor + divisor ) % divisor;
        }

        return knowers;
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