#include <vector>
#include <iostream>

////////////////////////
// 7 
// Reverse Integer
// https://leetcode.com/problems/reverse-integer/description/
// Medium
////////////////////////
// Runtime : 3ms Beats 28.07%
// Memory  : 8.76MB Beats 6.48%
////////////////////////


class Solution {
public:
    int reverse(int x) {

        // If the number is negative make it positive temporarily
        bool negative = false;  
        if (x < 0) {
            // Guarentees lower limit on int size is handled
            if (x < -2147483647) return 0;
            x *= -1;
            negative = true;
        }
        // Creates the example array
        // Builds the array backwards 123 -> {3,2,1}
        std::vector<int> arr;
        while (x > 0) {
            arr.push_back( x % 10 ); // Gets the last digit of the integer
            x = x / 10; // Removes the last digit
        }

        // long long allows more data to be stored than a regular int
        int size = arr.size(); // Size of the input array built
        long long max = 2147483647; // Max integer size
        long long flipped = 0; // Stores the flipped integer
        long long multiplier = 1; // For placing the integer in the proper place

        // Iterates through all digits of the array backwards
        for (int i=(arr.size()-1); i >= 0 ; --i) {
            //  // Checks for numbers that would exceed 32 bit integers
            // Adds the new flipped integer properly
            flipped += (arr[i] * multiplier);

            // Multiplies the new integer to place it as the correct digit
            multiplier *= 10;
        }

        if (flipped > max) return 0;

        // If the number was originally negative
        if (negative) { flipped *= -1; }

        int final = (int)flipped;

        return final;
    }
};

////////////////////////
//////////// END 
////////////////////////

int main() {
    Solution sol;
    std::cout << "123 : " << std::endl;
    std::cout << sol.reverse(123) << std::endl;

    std::cout << "-123 : " << std::endl;
    std::cout << sol.reverse(-123) << std::endl;

    std::cout << "-2147483412 : " << std::endl;
    std::cout << sol.reverse(-2147483412) << std::endl;

    std::cout << "-2147483648 : " << std::endl;
    std::cout << sol.reverse(-2147483648) << std::endl;
}