/*
Pacific Atlantic Water Flow 
You are given a rectangular island heights where heights[r][c] represents the height above sea level 
of the cell at coordinate (r, c).

The islands borders the Pacific Ocean from the top and left sides, and borders the Atlantic Ocean from the bottom and right sides.

Water can flow in four directions (up, down, left, or right) from a cell to a neighboring cell with height equal or 
lower. Water can also flow into the ocean from cells adjacent to the ocean.

Find all cells where water can flow from that cell to both the Pacific and Atlantic oceans. Return it as a 2D list where each 
element is a list [r, c] representing the row and column of the cell. You may return the answer in any order.

Example 1:

Input: heights = [
  [4,2,7,3,4],
  [7,4,6,4,7],
  [6,3,5,3,6]
]

Output: [[0,2],[0,4],[1,0],[1,1],[1,2],[1,3],[1,4],[2,0]]
Example 2:

Input: heights = [[1],[1]]

Output: [[0,0],[0,1]]
*/

#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    int ROWS, COLS;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        set<pair<int, int>> pac;
        set<pair<int, int>> atl;
        
        ROWS = heights.size(), COLS = heights[0].size();

        // search the first and last row
        for(int r = 0; r < ROWS; r++){
            dfs(r, 0, pac, heights[r][0], heights);
            dfs(r, COLS - 1, atl, heights[r][COLS - 1], heights);
        }

        // search first and last col
        for(int c = 0; c < COLS; c++){
            dfs(0, c, pac, heights[0][c], heights);
            dfs(ROWS - 1, c, atl, heights[ROWS - 1][c], heights);
        }

        for(int r = 0; r < ROWS; r++){
            for(int c = 0; c < COLS; c++){
                if(pac.count({r, c}) && atl.count({r, c}))
                    res.push_back({r, c});
            }
        }
        return res;
    }

    void dfs(int r, int c, set<pair<int, int>>& visited, int prevH, vector<vector<int>>& heights){
        if(r < 0 || r >= ROWS || c < 0 || c >= COLS || visited.count({r, c}) || prevH > heights[r][c])
            return;
        
        visited.insert({r, c});

        dfs(r + 1, c, visited, heights[r][c], heights);
        dfs(r - 1, c, visited, heights[r][c], heights);
        dfs(r, c + 1, visited, heights[r][c], heights);
        dfs(r, c - 1, visited, heights[r][c], heights);
    }
};
