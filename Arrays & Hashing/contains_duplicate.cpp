/*
Contains Duplicate

Given an integer array nums, return true if any value appears more than once in the array, 
otherwise return false.

Example 1:

Input: nums = [1, 2, 3, 3]

Output: true

Example 2:

Input: nums = [1, 2, 3, 4]

Output: false
*/

#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> dupe;
        for(int n : nums){
            if(dupe.count(n))
                return true;
            dupe.insert(n);
        }
        return false;
    }
};
