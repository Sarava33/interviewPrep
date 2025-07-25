/*
Jump Game II 
You are given an array of integers nums, where nums[i] represents the maximum length of a 
jump towards the right from index i. For example, if you are at nums[i], you can jump to any index i + j where:

j <= nums[i]
i + j < nums.length
You are initially positioned at nums[0].

Return the minimum number of jumps to reach the last position in the array (index nums.length - 1). 
You may assume there is always a valid answer.

Example 1:

Input: nums = [2,4,1,1,1,1]

Output: 2
Explanation: Jump from index 0 to index 1, then jump from index 1 to the last index.

Example 2:

Input: nums = [2,1,2,1,0]

Output: 2
*/

#include<vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0, l = 0, r = 0;

        while(r < nums.size() - 1){
            int furthest = 0;
            for(int i = l; i <= r; i++){
                furthest = max(furthest, i + nums[i]);
            }
            l = r + 1;
            r = furthest;
            res++;
        }
        return res;
    }
};
