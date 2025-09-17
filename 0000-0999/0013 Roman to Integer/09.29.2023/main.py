########################
# 13
# Roman to Integer
# https://leetcode.com/problems/roman-to-integer/description/
# Easy 
########################
# Runtime : 35ms Beats 5.10%
# Memory  : 13.36MB Beats 13.18%
########################

def main():
    s = Solution()
    num = s.romanToInt("V")
    print(num)

class Solution:
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        nums = []
        numerals = {
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000,
            }
    
        for i in range(len(s)):
            nums.append(numerals[s[i]])

        fail = True
        while fail == True:
            fail = False
            for i in range(1, len(nums)):
                if nums[i] > nums[i-1]:
                    nums[i] = nums[i] - nums[i-1]
                    nums.remove(nums[i-1])
                    fail = True
                    break

        total = 0
        for i in range(len(nums)):
            total += nums[i]

            
        return total

if __name__ == "__main__":
    main()