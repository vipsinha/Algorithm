/*

2. Add Two Numbers

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.

*/



#include <iostream>
#include <string>
#include <map>
#include <stack>

using namespace std;
/**
 * Definition for singly-linked list.
**/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head = new ListNode(0);
        ListNode* traverse = head;

        while ((l1 != nullptr) or (l2 != nullptr) or (carry != 0)) {
            int data1 = l1 != nullptr ? l1->val : 0;
            int data2 = l2 != nullptr ? l2->val : 0;

            int sum = data1 + data2 + carry;
            int data = sum % 10;
            carry = sum / 10;

            ListNode* newNode = new ListNode(data);
            traverse->next = newNode;
            traverse = traverse->next;

            l1 = l1 != nullptr ? l1->next : nullptr;
            l2 = l2 != nullptr ? l2->next : nullptr;
        }

        return head->next;
    }
};

int main(){

    Solution sol;
    //vector<int> nums = {0,0,1};
    //sol.isSymmetric(nums);
    return 0;
}