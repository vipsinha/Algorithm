/*

28. Find the Index of the First Occurrence in a String
Solved
Easy
Topics
Companies
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.
 

Constraints:

1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters.
*/

#include <iostream>
#include <string>
#include <map>
#include <stack>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {

        for (auto i = 0; i < haystack.length(); i++) {
            if (haystack.substr(i, needle.length()) == needle) {
                return i;
            }
        }
        return -1;
    }
};

int main(){

    Solution sol;
    string needle = "a";
    string haystack = "a;";
    sol.strStr(haystack, needle);
    return 0;
}