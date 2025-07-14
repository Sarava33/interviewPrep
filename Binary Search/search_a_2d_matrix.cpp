/*
Search a 2D Matrix 
You are given an m x n 2-D integer array matrix and an integer target.

Each row in matrix is sorted in non-decreasing order.
The first integer of every row is greater than the last integer of the previous row.
Return true if target exists within matrix or false otherwise.

Can you write a solution that runs in O(log(m * n)) time?

Example 1:

Input: matrix = [[1,2,4,8],[10,11,12,13],[14,20,30,40]], target = 10

Output: true
Example 2:

Input: matrix = [[1,2,4,8],[10,11,12,13],[14,20,30,40]], target = 15

Output: false
*/

#include<vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int top = 0, bot = rows - 1;
        while(top <= bot){
            int row = (top + bot) / 2;
            if(target > matrix[row][cols - 1])
                top = row + 1;
            else if( target < matrix[row][0])
                bot = row - 1;
            else
                break;
        }

        if(top > bot)
            return false;
        
        int row = (top + bot) / 2, l = 0, r = cols - 1;
        while(l <= r){
            int m = (l + r) / 2;
            if(target == matrix[row][m])
                return true;
            else if(target > matrix[row][m])
                l = m + 1;
            else 
                r = m - 1;
        }
        return false;
    }
};


