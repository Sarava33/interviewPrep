/*
Search in Rotated Sorted Array 
You are given an array of length n which was originally sorted in ascending order. It has now been 
rotated between 1 and n times. For example, the array nums = [1,2,3,4,5,6] might become:

[3,4,5,6,1,2] if it was rotated 4 times.
[1,2,3,4,5,6] if it was rotated 6 times.
Given the rotated sorted array nums and an integer target, return the index of target within nums, or -1 
if it is not present.

You may assume all elements in the sorted rotated array nums are unique,

A solution that runs in O(n) time is trivial, can you write an algorithm that runs in O(log n) time?

Example 1:

Input: nums = [3,4,5,6,1,2], target = 1

Output: 4
Example 2:

Input: nums = [3,5,6,0,1,2], target = 4

Output: -1

*/

#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while(l <= r){
            int m = (l + r) / 2;
            if(nums[m] == target)
                return m;
            // check if in left sorted side
            if(nums[m] >= nums[l]){
                //check if target is outside that range
                if(target > nums[m] || target < nums[l])
                    l = m + 1; // searh right
                else
                    r = m - 1;
            }
            else {
                if(target < nums[m] || target > nums[r])
                    r = m - 1;
                else
                    l = m + 1;
            }
        }
        return -1;
    }
};
