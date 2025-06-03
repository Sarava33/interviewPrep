/*Valid Anagram

Given two strings s and t, return true if the two strings are anagrams of each other, otherwise return false.

An anagram is a string that contains the exact same characters as another string, but the order 
of the characters can be different.

Example 1:

Input: s = "racecar", t = "carrace"

Output: true
Example 2:

Input: s = "jar", t = "jam"

Output: false
*/

#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        vector<int> anagram(26,0);
        for(char c : s)
            anagram[c - 'a']++;
        for(char c : t)
            anagram[c - 'a']--;    
        for(int i : anagram){
            if(i > 0)
                return false;
        }
    return true;
    }
};
