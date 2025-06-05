/*
Group Anagrams

Given an array of strings strs, group all anagrams together into sublists. You may return the output in any order.

An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different.

Example 1:

Input: strs = ["act","pots","tops","cat","stop","hat"]

Output: [["hat"],["act", "cat"],["stop", "pots", "tops"]]
Example 2:

Input: strs = ["x"]

Output: [["x"]]
Example 3:

Input: strs = [""]

Output: [[""]]
*/

// Two solutions, first one is using sorting and sorted word as the key to a hash table, O(nlogn)

#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution_1 {
public:
    vector<vector<string>> groupAnagrams_1(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;
        for(auto& word : strs){
            string sortedWord = word;
            sort(sortedWord.begin(), sortedWord.end());
            mp[sortedWord].push_back(word);
        }
        
        for(auto& i : mp){
            res.push_back(i.second);
        }
    return res;
    }
};

// Second solution, build a freq char map with array, then build a key to use as distinct key in map
//O(n) O(26)

class Solution_2 {
public:
    vector<vector<string>> groupAnagrams_2(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;
        for(auto& word : strs){
            vector<int> freq(26, 0);
            for(char c : word)
                freq[c - 'a']++;
            string key = "";
            for(int i : freq)
                key += to_string(i) + "*";
            mp[key].push_back(word);
        }
        for(auto& i : mp)
            res.push_back(i.second);

        return res;
    }
};
