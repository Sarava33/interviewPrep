/*
Top K Frequent Elements
Given an integer array nums and an integer k, return the k most frequent elements within the array.

The test cases are generated such that the answer is always unique.

You may return the output in any order.

Example 1:

Input: nums = [1,2,2,3,3,3], k = 2

Output: [2,3]
Example 2:

Input: nums = [7,7], k = 1

Output: [7]
*/


#include<vector>
#include<string>
#include<unordered_map>
#include<queue>
using namespace std;

// Max-Heap time complexity O(nlogn) because logn to insert and delete from heap but doing it N times
// for all nums in array. Sam complexity as sort basically

class Solution_1 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        priority_queue<pair<int, int>> minH;
        unordered_map<int, int> mp;
        for(int n : nums)
            mp[n]++;
        
        for(auto& it : mp)
            minH.push({it.second, it.first}); // push count, num
        
        for(int i = 0; i < k; i++){
            pair<int, int> it;
            it = minH.top();
            res.push_back(it.second);
            minH.pop();
        }
        return res;
    }
};

// Min-Heap O(nlogk) k is size of top elements. Its a bit better as we discard everything other than top K vals

class Solution_2 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minH;
        unordered_map<int, int> mp;
        for(int n : nums)
            mp[n]++;
        
        for(auto& it : mp){
            minH.push({it.second, it.first}); // push count, num
            if(minH.size() > k)
                minH.pop();
        }
        
        for(int i = 0; i < k; i++){
            pair<int, int> it;
            it = minH.top();
            res.push_back(it.second);
            minH.pop();
        }
        return res;
    }
};

// Bucket Sort - O(n)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //bucket sort
        // count the total occurence of each element
        // flip the count to the index in a res array and the value to be at that pos
        // eg [1 1 1 3 3 2]
        /*
            map[1 -> 3]
               [3 -> 2]
               [2 -> 1]
            
            new array (nums.size + 1) the max frequency can only be the max size of the array
            [0 1 3 1 0 0 0]
             0 1 2 3 4 5 6 -> index also the freq of occurrence 

            iterate from the back check if any element has 6 occurrences, 5, and 4 etc
            let say k = 2 then at index 3, 1 has occured 3 times insert 1
            3 has occured twice at index 2 insert 3
        */

        unordered_map<int,int> count;
        for(int n : nums){
            count[n]++;
        }

        vector<vector<int>> freq(nums.size() + 1);
        for(auto& it : count)
            freq[it.second].push_back(it.first);
        
        vector<int> res;

        for(int i = freq.size() - 1; i > 0; i--){
            for(auto& n : freq[i]){
                res.push_back(n);

                if(res.size() == k)
                    return res;
            }
        }
        return res;
    }
};
