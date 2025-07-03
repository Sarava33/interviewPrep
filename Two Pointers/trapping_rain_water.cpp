/*
Trapping Rain Water
 
You are given an array of non-negative integers height which represent an elevation map. Each value height[i] represents the height of a bar, which has a width of 1.

Return the maximum area of water that can be trapped between the bars.

Example 1:

Input: height = [0,2,0,3,1,0,1,3,2,1]

Output: 9
*/

#include<vector>
using namespace std;

class Solution {
public:
// min(L, R) - h[i];
    int trap(vector<int>& height) {
        int res = 0;
        int l = 0, r = height.size() - 1;
        int maxL = height[l], maxR = height[r];
        while(l < r){
            if(maxL < maxR){
                l++;
                maxL = max(maxL, height[l]);
                res += maxL - height[l];
            }
            else{
                r--;
                maxR = max(maxR, height[r]);
                res += maxR - height[r];
            }
        }
        return res;
    }
};
