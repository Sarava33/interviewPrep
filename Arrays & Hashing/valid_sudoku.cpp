/*
Valid Sudoku

You are given a 9 x 9 Sudoku board board. A Sudoku board is valid if the following rules are followed:

Each row must contain the digits 1-9 without duplicates.
Each column must contain the digits 1-9 without duplicates.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without duplicates.
Return true if the Sudoku board is valid, otherwise return false

Note: A board does not need to be full or be solvable to be valid.

Example 1:

Input: board = 
[["1","2",".",".","3",".",".",".","."],
 ["4",".",".","5",".",".",".",".","."],
 [".","9","8",".",".",".",".",".","3"],
 ["5",".",".",".","6",".",".",".","4"],
 [".",".",".","8",".","3",".",".","5"],
 ["7",".",".",".","2",".",".",".","6"],
 [".",".",".",".",".",".","2",".","."],
 [".",".",".","4","1","9",".",".","8"],
 [".",".",".",".","8",".",".","7","9"]]

Output: true

Example 2:

Input: board = 
[["1","2",".",".","3",".",".",".","."],
 ["4",".",".","5",".",".",".",".","."],
 [".","9","1",".",".",".",".",".","3"],
 ["5",".",".",".","6",".",".",".","4"],
 [".",".",".","8",".","3",".",".","5"],
 ["7",".",".",".","2",".",".",".","6"],
 [".",".",".",".",".",".","2",".","."],
 [".",".",".","4","1","9",".",".","8"],
 [".",".",".",".","8",".",".","7","9"]]

Output: false
*/

#include<unordered_set>
#include<vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //Declare row col and box as set of 9 becuase we know sudoku is 9x9
        unordered_set<char> row[9];
        unordered_set<char> col[9];
        unordered_set<char> box[9];

        for(int r = 0; r < 9; r++){
            for(int c = 0; c < 9; c++){
                if(board[r][c] == '.')
                    continue;
                int pos = (r / 3) * 3 + (c / 3); //calculate box postion
                if(row[r].count(board[r][c]) || col[c].count(board[r][c]) || box[pos].count(board[r][c])){
                    return false;
                }
                row[r].insert(board[r][c]);
                col[c].insert(board[r][c]);
                box[pos].insert(board[r][c]);
            }
        }        
        return true;
    }
};
