/*

104. Maximum Depth of Binary Tree

Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 3
Example 2:

Input: root = [1,null,2]
Output: 2
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-100 <= Node.val <= 100

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
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int left_depth = maxDepth(root->left);
        int right_depth = maxDepth(root->right);

        return max(left_depth, right_depth) + 1;
    }
};

int main(){

    Solution sol;
    //vector<int> nums = {0,0,1};
    //sol.isSymmetric(nums);
    return 0;
}