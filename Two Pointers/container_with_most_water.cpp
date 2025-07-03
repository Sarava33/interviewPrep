/*
Container With Most Water
 
You are given an integer array heights where heights[i] represents the height of the 
i th bar.

You may choose any two bars to form a container. Return the maximum amount of water a container can store.

Example 1:

Input: height = [1,7,2,5,4,7,3,6]

Output: 36
Example 2:

Input: height = [2,2,2]

Output: 4
*/

#include<vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int res = 0;
        int l = 0, r = heights.size() - 1;
        while(l < r){
            int area = min(heights[l], heights[r]) * (r - l);
            res = max(res, area);
            if(heights[l] < heights[r])
                l++;
            else
                r--;
        }
        return res;
    }
};
