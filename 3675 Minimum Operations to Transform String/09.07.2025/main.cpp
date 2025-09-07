#include <vector>
#include <iostream>
#include <cassert>

////////////////////////
// # 
// Name
// Link
// Difficulty
////////////////////////
// Runtime : Xms Beats X%
// Memory  : XMB Beats X%
////////////////////////

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
    //test here
}