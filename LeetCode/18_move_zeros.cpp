/*
283. Move Zeroes

Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
 

Constraints:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
 

Follow up: Could you minimize the total number of operations done?

*/


#include <iostream>
#include <string>
#include <map>
#include <stack>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int original_size = nums.size();
        int count = std::count(nums.begin(), nums.end(), 0);
        for (auto i = 0; i < count; i++) {
            nums.erase(std::find(nums.begin(), nums.end(), 0));
            nums.push_back(0);
        }
    }
};

int main(){

    Solution sol;
    vector<int> nums = {0,0,1};
    sol.moveZeroes(nums);
    return 0;
}