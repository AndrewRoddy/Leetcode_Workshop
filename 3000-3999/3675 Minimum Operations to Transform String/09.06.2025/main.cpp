#include <vector>
#include <iostream>
#include <cassert>

////////////////////////
// # 3675
// Minimum Operations to Transform String
// https://leetcode.com/problems/minimum-operations-to-transform-string/description/
// Medium
////////////////////////
// Runtime : 41ms Beats 42.10%
// Memory  : 59.79MB Beats 94.74%
////////////////////////

using std::string;

class Solution {
public:
    int minOperations(string s) {

    bool isA = true;
    char letter = 'a';
    char min = 'z';
        
    for (int i=0; i<s.size(); ++i) {
        if (s[i] != 'a') {
            if (s[i] <= min) {
                // std::cout << s[i] << std::endl;
                min = s[i];
                letter = s[i];
                isA = false;
            }
        }
    }

    // std::cout << "LETTER: " << letter << std::endl;

    if (isA==true) {return 0;}
    // std::cout << 'z'-'y' << std::endl;
    // std::cout << 'z'-'z' << std::endl;
    int returnNumber = ('z'-letter)+1;
    // std::cout << returnNumber << std::endl;
    return returnNumber;
          
    }
};

////////////////////////
// END 
////////////////////////

int main() {
    Solution test;
    assert(test.minOperations("yz") == 2);
    assert(test.minOperations("a") == 0);
    assert(test.minOperations("aaaaaa") == 0);
    assert(test.minOperations("aaaaaaaaaa") == 0);
    assert(test.minOperations("z") == 1);
    std::cout << "All tests passed!" << std::endl;
}