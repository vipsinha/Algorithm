/*

62. Unique Paths

There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

 

Example 1:


Input: m = 3, n = 7
Output: 28
Example 2:

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
 

Constraints:

1 <= m, n <= 100

*/


#include <iostream>
#include <string>
#include <map>
#include <list>

using namespace std;

class Solution {
    int dp[101][101];
    int r, c;

public:
    int uniquePaths(int m, int n) {
        r = m;
        c = n;
        memset(dp, -1, sizeof(dp));
        return dfs(0, 0);
    }

    int dfs(int s_r, int s_c) {
        int res = 0;

        // marking as invalid
        if (s_r == r - 1 and s_c == c - 1)
            return 1;
        if (dp[s_r][s_c] != -1)
            return dp[s_r][s_c];

        // traversing
        if (s_r + 1 < r)
            res += dfs(s_r + 1, s_c);
        if (s_c + 1 < c)
            res += dfs(s_r, s_c + 1);

        return dp[s_r][s_c] = res;
    }
};


int main(){
    Solution sol;
    //sol.rob();
    return 0;
}