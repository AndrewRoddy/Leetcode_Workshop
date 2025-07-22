// Runtime | 103ms   | Beats 16.96%
// Memory  | 12.79MB | Beats 96.88%

#include <iostream>
#include <vector>        // For std::vector
#include <unordered_map> // For std::unordered_map

using std::vector; using std::unordered_map;
using std::cout; using std::endl;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> working = {};
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 1; j < nums.size(); j++) {
                if ((nums[i] + nums[j]) == target){
                    working.push_back(i); 
                    working.push_back(j); 
                    return working;
                }
            }
        }
        return {};
    };
};

int main() {
    Solution solve;
    
    vector<int> nums = {2,7,11,15};
    int target = 9;

    vector<int> out = solve.twoSum(nums, target);

    cout << out[0] << " " << out[1] << endl;
}