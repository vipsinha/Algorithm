/*

387. First Unique Character in a String

Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

 

Example 1:

Input: s = "leetcode"
Output: 0
Example 2:

Input: s = "loveleetcode"
Output: 2
Example 3:

Input: s = "aabb"
Output: -1
 

Constraints:

1 <= s.length <= 105
s consists of only lowercase English letters.

*/

#include <iostream>
#include <string>
#include <map>
#include <stack>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        std::map<char, int> m_map{};

        for (auto const& ch : s) {
            m_map[ch]++;
        }

        for(int i=0; i<s.size(); i++){
            if(m_map[s[i]] == 1) {
                return i;
            }
        }

        return -1;
    }
};

int main(){

    Solution sol;
    std::cout << sol.firstUniqChar("loveleetcode");
    return 0;
}