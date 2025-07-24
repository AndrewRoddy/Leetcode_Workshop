#include <iostream>
#include <vector>
#include <cassert>

////////////////////////
// 9 
// Palindrome Number
// https://leetcode.com/problems/palindrome-number/description/
// Easy 
////////////////////////
// Runtime : 10ms Beats 8.17%
// Memory  : 12.31MB Beats 5.10%
////////////////////////

class Solution {
public:
    bool isPalindrome(int x) {
        // No negative numbers are palindromes
        if (x < 0) return false;

        // Puts numbers in an array
        std::vector<int> num;
        while (x > 0) {
            num.push_back(x%10);
            x /=10;
        }

        int final=num.size()-1; // The last number we are looking at
        // Checks numbers from either end to guarentee numbers are palindromes
        for (int i=0; i<num.size(); ++i) {
            if (num[i] != num[final]) return false;
            final--;
        }

        return true;
    }
};

////////////////////////
// END 
////////////////////////

int main() {
    Solution sol;
    assert(sol.isPalindrome(121)  == true);
    assert(sol.isPalindrome(-121) == false);
    assert(sol.isPalindrome(10)   == false);
}