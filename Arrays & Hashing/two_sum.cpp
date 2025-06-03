/*
Two Sum

Given an array of integers nums and an integer target, return the indices i and j such that 
nums[i] + nums[j] == target and i != j.

You may assume that every input has exactly one pair of indices i and j that satisfy the condition.

Return the answer with the smaller index first.

Example 1:

Input: nums = [3,4,5,6], target = 7
Output: [0,1]
Explanation: nums[0] + nums[1] == 7, so we return [0, 1].

Example 2:

Input: nums = [4,5,6], target = 10
Output: [0,2]

Example 3:

Input: nums = [5,5], target = 10
Output: [0,1]
*/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            int diff = target - nums[i];
            if(mp.count(diff)){
                int j = mp[diff];
                res.push_back(j);
                res.push_back(i);
                return res;
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};
