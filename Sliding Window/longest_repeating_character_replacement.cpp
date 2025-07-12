/*
Longest Repeating Character Replacement 
You are given a string s consisting of only uppercase english characters and an integer k. You can choose up to k characters of the string and replace them with any other uppercase English character.

After performing at most k replacements, return the length of the longest substring which contains only one distinct character.

Example 1:

Input: s = "XYYX", k = 2

Output: 4
Explanation: Either replace the 'X's with 'Y's, or replace the 'Y's with 'X's.

Example 2:

Input: s = "AAABABB", k = 1

Output: 5
*/
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        int l = 0;
        unordered_map<char, int> mp;
        int maxF = 0;
        
        for(int r = 0; r < s.size(); r++){
            mp[s[r]]++;
            maxF = max(maxF, mp[s[r]]);
            while(r - l + 1 - maxF > k){
                mp[s[l]]--;
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
