#include <vector>
#include <iostream>
#include <cassert>

////////////////////////
// 3674
// Minimum Operations to Equalize Array 
// https://leetcode.com/problems/minimum-operations-to-equalize-array/description/
// Easy
////////////////////////
// Runtime : 0ms Beats 100%
// Memory  : 30.63MB Beats 91.67%
////////////////////////

class Solution {
public:
    int minOperations(std::vector<int>& nums) {
        bool equal = true;
        for (int i=1; i<nums.size(); ++i) {
            if (nums[i-1] != nums[i]) equal = false;    
        }
        if (equal==true) return 0;

        
        return 1;
    }
};

////////////////////////
// END 
////////////////////////

int main() {
    Solution test;
    std::vector<int> vec1 = {1,2};
    assert(test.minOperations(vec1) == 1);
    std::vector<int> vec2 = {5,5,5};
    assert(test.minOperations(vec2) == 0);
    std::cout << std::endl << "All tests passed!" << std::endl << std::endl;
}