/*

300. Longest Increasing Subsequence

Given an integer array nums, return the length of the longest strictly increasing 
subsequence
.

 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1
 

Constraints:

1 <= nums.length <= 2500
-104 <= nums[i] <= 104
 

*/


#include <iostream>
#include <string>
#include <map>
#include <list>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        std::vector<int> vec_size(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    vec_size[i] = std::max(vec_size[i], vec_size[j] + 1);
                }
            }
        }

        return *std::max_element(vec_size.begin(), vec_size.end());
    }
};

int main(){
    Solution sol;
    //sol.rob();
    return 0;
}