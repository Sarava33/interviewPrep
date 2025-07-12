/*
Permutation in String 
You are given two strings s1 and s2.

Return true if s2 contains a permutation of s1, or false otherwise. That means if a permutation of s1 exists as a substring of s2, then return true.

Both strings only contain lowercase letters.

Example 1:

Input: s1 = "abc", s2 = "lecabee"

Output: true
Explanation: The substring "cab" is a permutation of "abc" and is present in "lecabee".

Example 2:

Input: s1 = "abc", s2 = "lecaabee"

Output: false
*/

#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq1 (26,0);
        vector<int> freq2 (26,0);
        int l = 0, r = 0;
        
        for(char c : s1)
            freq1[c - 'a']++;
        
        while(r < s2.size()){
            freq2[s2[r] - 'a']++;
            
            if(r - l + 1 == s1.size()){
                if(freq1 == freq2)
                    return true;
            }

            if(r - l + 1 < s1.size()){
                r++; 
            }
            else{
                freq2[s2[l] - 'a']--;
                l++;
                r++;
            }
        }
        return false;
    }
};
