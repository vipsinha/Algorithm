/*

94. Binary Tree Inorder Traversal

Given the root of a binary tree, return the inorder traversal of its nodes' values. 

Example 1:


Input: root = [1,null,2,3]
Output: [1,3,2]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
 

Follow up: Recursive solution is trivial, could you do it iteratively?

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        Traversal(root, result);
        return result;
    }

    void Traversal(TreeNode* root, vector<int>& result) {
        if (root != nullptr) {
            Traversal(root->left, result);
            result.push_back(root->val);
            Traversal(root->right, result);
        }
    }
};

int main(){

    Solution sol;
    //vector<int> nums = {0,0,1};
    //sol.inorderTraversal(nums);
    return 0;
}