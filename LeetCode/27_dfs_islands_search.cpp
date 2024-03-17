/*

200. Number of Islands
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.

*/

// https://leetcode.com/problems/number-of-islands/solutions/4631794/simplest-possible-solution-beginners/


#include <iostream>
#include <string>
#include <map>
#include <list>

using namespace std;


class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& grid){
        //MARKING THE LAND AS 0 FOR VISITED (INSTEAD OF USING EXTRA VISITED ARRAY)
        grid[i][j]=0;
        int n=grid.size();
        int m=grid[0].size();

        //TRAVERSING ACROSS ALL 4 NEIGHBOURS 
        if(i-1 >= 0 && grid[i-1][j] == '1') dfs(i-1,j,grid);
        if(i+1 < n && grid[i+1][j] == '1')  dfs(i+1,j,grid);
        if(j-1 >= 0 && grid[i][j-1] == '1') dfs(i,j-1,grid);
        if(j+1 < m && grid[i][j+1] == '1') dfs(i,j+1,grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        //CALCULATE ROWS AND COLUMNS
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;

        //TO FIND THE STARTING POINTS ON AN ISLAND
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j] == '1'){
                    ans++;
                    dfs(i,j,grid);
                }
            }
        }
       return ans; 
    }
};


int main(){
    Solution sol;
    //sol.rob();
    return 0;
}