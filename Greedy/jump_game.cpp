/*
Jump Game 
You are given an integer array nums where each element nums[i] indicates your maximum jump 
length at that position.

Return true if you can reach the last index starting from index 0, or false otherwise.

Example 1:

Input: nums = [1,2,0,1,0]

Output: true
Explanation: First jump from index 0 to 1, then from index 1 to 3, and lastly from index 3 to 4.

Example 2:

Input: nums = [1,2,1,0,1]

Output: false
*/

#include<vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal = nums.size() - 1;
        for(int i = nums.size() - 2; i >= 0; i--){
            if(i + nums[i] >= goal)
                goal = i;
        }
        return goal == 0;
    }
};
