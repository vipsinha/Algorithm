/*

20. Valid Parentheses
Easy
Topics
Companies
Hint
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/

#include <iostream>
#include <string>
#include <map>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        std::stack<char> st;
        for (auto const& ch : s) {
            if (st.empty()) {
                st.push(ch);
            } else if ((st.top() == '(' && ch == ')') ||
                       (st.top() == '[' && ch == ']') ||
                       (st.top() == '{' && ch == '}')) {
                st.pop();
            } else {
                st.push(ch);
            }
        }

        if (st.empty())
            return true;
        else
            return false;
    }
};

int main(){

    Solution sol;
    std::cout << sol.isValid("]");
    return 0;
}