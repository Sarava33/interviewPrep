/*
Longest Consecutive Sequence
 
Given an array of integers nums, return the length of the longest consecutive sequence of elements that can be formed.

A consecutive sequence is a sequence of elements in which each element is exactly 1 greater than the previous element. The elements do not have to be consecutive in the original array.

You must write an algorithm that runs in O(n) time.

Example 1:

Input: nums = [2,20,4,10,3,4,5]

Output: 4
Explanation: The longest consecutive sequence is [2, 3, 4, 5].

Example 2:

Input: nums = [0,3,2,5,4,6,1,1]

Output: 7
*/

#include<unordered_set>
#include<vector>
using namespace std;
// Put all numbers into a set, for every number, treat it as thought its the largest and check n -1 exists? then keep 
// decrementing till you find the lowest number in that seq and do the same for every number
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int res = 0;

        for(int n : nums){
            int seq = 1;
            while(numSet.count(n - 1)){
                n--;
                seq++;
            }
            res = max(res, seq);
        }
        return res;
    }
};
