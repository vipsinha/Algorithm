/*

Code
Testcase
Testcase
Test Result
14. Longest Common Prefix
Easy
Topics
Companies
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.
*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        std::string ret = strs[0];
        
        for (auto const& str : strs) {

            while(str.find(ret) != 0) {

                // if string is not found, reduce the length of the 
                // orignal string. Then search with the smaller string
                ret = ret.substr(0, ret.length() - 1);
            }
        }
        return ret;
    }
};

int main(){

    Solution sol;
    //std::cout << sol.romanToInt("MMMCDXC");
    return 0;
}