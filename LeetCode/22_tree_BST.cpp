/*

108. Convert Sorted Array to Binary Search Tree

Given an integer array nums where the elements are sorted in ascending order, convert it to a 
height-balanced binary search tree.

 

Example 1:


Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Example 2:


Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in a strictly increasing order.

*/


#include <iostream>
#include <string>
#include <map>
#include <stack>

using namespace std;
/**
 * Definition for a binary tree node.
**/

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
    right(right) {}
 };

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return BST(nums, 0, nums.size() - 1);
    }
    TreeNode* BST(vector<int>& nums, int low, int high) {
        if (low <= high) {
            int mid = low + (high - low) / 2;
            TreeNode* node = new TreeNode(nums[mid]);
            node->left = BST(nums, low, mid - 1);
            node->right = BST(nums, mid + 1, high);

            return node;
        }
        return nullptr;
    }
 };
 
int main(){

    Solution sol;
    //vector<int> nums = {0,0,1};
    //sol.isSymmetric(nums);
    return 0;
}