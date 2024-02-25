/*

136. Single Number

Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

*/

#include <iostream>
#include <string>
#include <map>
#include <stack>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        std::map<int, int> m_map{};
        int digit;

        for (auto const& num : nums) {
            m_map[num]++;
        }

        for (const auto& pair : m_map) {
            if(pair.second == 1)
                digit = pair.first;
        }

        return digit;
    }
};

int main(){

    Solution sol;
    vector<int> nums={4,1,2,1,2};
    std::cout << sol.singleNumber(nums);
    return 0;
}