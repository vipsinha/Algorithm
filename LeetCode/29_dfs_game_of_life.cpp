/*

289. Game of Life

According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously. Given the current state of the m x n grid board, return the next state.

 

Example 1:


Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
Example 2:


Input: board = [[1,1],[1,0]]
Output: [[1,1],[1,1]]
 

Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 25
board[i][j] is 0 or 1.

*/


#include <iostream>
#include <string>
#include <map>
#include <list>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int r = board.size();
        int c = board[0].size();

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                dfs(board, i, j);
            }
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (board[i][j] == 2)
                    board[i][j] = 1;
                else if (board[i][j] == 3)
                    board[i][j] = 0;
            }
        }
    }

    // to be live (1) = state 2
    // to be dead (0) = state 3
    void dfs(vector<vector<int>>& board, int r, int c) {
        int a1 = isInside(board, r - 1, c);
        int a2 = isInside(board, r + 1, c);
        int a3 = isInside(board, r - 1, c - 1);
        int a4 = isInside(board, r - 1, c + 1);
        int a5 = isInside(board, r + 1, c - 1);
        int a6 = isInside(board, r + 1, c + 1);
        int a7 = isInside(board, r, c + 1);
        int a8 = isInside(board, r, c - 1);

        int sum = a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8;

        if (board[r][c] == 0) {
            if (sum == 3)
                // to be live
                board[r][c] = 2;
        } else if (board[r][c] == 1) {
            if ((sum < 2) or (sum > 3))
                // to be dead
                board[r][c] = 3;
        }
    }

    int isInside(vector<vector<int>>& board, int r, int c) {
        if ((r < 0) or (c < 0) or (r >= board.size()) or (c >= board[0].size()))
            return 0;

        // 1 is live and 3 is about to live
        return ((board[r][c] == 1) or (board[r][c] == 3));
    }
};


int main(){
    Solution sol;
    //sol.rob();
    return 0;
}