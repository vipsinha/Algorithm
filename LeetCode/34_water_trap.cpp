/*

42. Trapping Rain Water

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105

*/

// https://www.youtube.com/watch?v=ZI2z5pq0TqA
// https://leetcode.com/problems/trapping-rain-water/solutions/4839456/c-no-dp-beats-94-explained/

#include <iostream>
#include <string>
#include <map>
#include <list>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int storage = 0;
        int length = height.size();
        std::vector<int> left(length, 0);
        std::vector<int> right(length, 0);

        left[0] = height[0];
        for (int i = 1; i < length; i++) {
            left[i] = max(left[i - 1], height[i]);
        }

        right[length - 1] = height[length - 1];
        for (int i = length - 2; i >= 0; i--) {
            right[i] = max(right[i + 1], height[i]);
        }

        for (int i = 0; i < length; i++) {
            int var = min(left[i], right[i]);
            if (var > height[i])
                storage += var - height[i];
        }
        return storage;
    }
};


int main(){
    Solution sol;
    //sol.rob();
    return 0;
}