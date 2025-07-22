#include <vector>
#include <iostream>

////////////////////////
//////////// LEETCODE 
////////////////////////

class Solution {
public:
    int reverse(int x) {

        // If the number is negative make it positive temporarily
        bool negative = false;  
        if (x < 0) {
            x *= -1;
            negative = true;
        }
        // Creates the example array
        std::vector<int> arr;
        while (x > 0) {

            arr.push_back( x % 10 ); // Gets the last digit of the integer
            x = x / 10; // Removes the last digit
        }

        int flipped = 0; // Stores the flipped integer
        int multiplier = 1; // For placing the integer in the proper place

        // Iterates through all digits of the array backwards
        for (int i=(arr.size()-1); i >= 0 ; --i) {
            // if (i == 9 && ) return 0; // Checks for numbers that would exceed 32 bit integers
            // Adds the new flipped integer properly
            flipped += (arr[i] * multiplier);

            // Multiplies the new integer to place it as the correct digit
            multiplier *= 10;
        }

        // If the number was originally negative
        if (negative) { flipped *= -1; }

        return flipped;
    }
};

////////////////////////
//////////// END 
////////////////////////

int main() {
    Solution sol;
    std::cout << "123 : " << sol.reverse(123) << std::endl;
    std::cout << "-123 : " << sol.reverse(-123) << std::endl;
    std::cout << "2,147,483,647 : " << sol.reverse() << std::endl;
}