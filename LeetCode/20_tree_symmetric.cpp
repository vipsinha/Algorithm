/*

101. Symmetric Tree

Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100
 

Follow up: Could you solve it both recursively and iteratively?

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
    bool isSymmetric(TreeNode* root) { return isMirror(root, root); }

    bool isMirror(TreeNode* left, TreeNode* right) {
        if (!left && !right)
            return true;
        if (!left || !right)
            return left == right;
        if (left->val != right->val)
            return false;
        return isMirror(left->left, right->right) &&
               isMirror(left->right, right->left);
    }
};

int main(){

    Solution sol;
    //vector<int> nums = {0,0,1};
    //sol.isSymmetric(nums);
    return 0;
}