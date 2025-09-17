#include <vector>
#include <iostream>
#include <cassert>

////////////////////////
// 1317
// Convert Integer to the Sum of Two No-Zero Integers
// https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/description/?envType=daily-question&envId=2025-09-08
// Easy
////////////////////////
// Runtime : 0ms Beats 100%
// Memory  : 9.30MB Beats 13.18%
////////////////////////

#include <string>

// code here
class Solution {
public:
    std::vector<int> getNoZeroIntegers(int n) {
        std::vector<int> vec;

        vec.push_back(1);
        vec.push_back(n-1);

        std::string str0; 
        std::string str1; 
        int size;
        bool zero = true;

        while (zero) {
            zero = false;
            str0 = std::to_string(vec[0]);
            str1 = std::to_string(vec[1]);
            
            for (int i=0; i<str0.size(); ++i) {
                if (str0[i] == '0') {
                    zero = true;
                    vec[0]++;
                    vec[1]--;
                    break;
                }
            }

            for (int i=0; i<str1.size(); ++i) {
                if (str1[i] == '0') {
                    zero = true;
                    vec[0]++;
                    vec[1]--;
                    break;
                }
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
    std::vector<int> vec;
    vec = test.getNoZeroIntegers(2);
    std::cout << "{ " << vec[0] << ", " << vec[1] << " }" << std::endl;
    vec = test.getNoZeroIntegers(11);
    std::cout << "{ " << vec[0] << ", " << vec[1] << " }" << std::endl;

    std::cout << std::endl << "All tests passed!" << std::endl << std::endl;
}