/*
Minimum Window Substring 
Given two strings s and t, return the shortest substring of s such that every character in t, including duplicates, is present in the substring. If such a substring does not exist, return an empty string "".

You may assume that the correct output is always unique.

Example 1:

Input: s = "OUZODYXAZV", t = "XYZ"

Output: "YXAZ"
Explanation: "YXAZ" is the shortest substring that includes "X", "Y", and "Z" from string t.

Example 2:

Input: s = "xyz", t = "xyz"

Output: "xyz"
Example 3:

Input: s = "x", t = "xy"

Output: ""
*/

#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> countT;
        unordered_map<char, int> window;

        for(char c : t){
            countT[c]++;
        }

        int have = 0, need = countT.size(), l = 0, reslen = INT_MAX;
        pair<int, int> res = {0, 0};

        for(int r = 0; r < s.size(); r++){
            window[s[r]]++;
            if(countT.count(s[r]) && window[s[r]] == countT[s[r]])
                have++;
            
            while(have == need){
                if(r - l + 1 < reslen){
                    reslen = r - l + 1;
                    res = {l, r};
                }
                window[s[l]]--;
                if(countT.count(s[l]) && window[s[l]] < countT[s[l]])
                    have--;
                l++;
            }
        }
        return reslen == INT_MAX ? "" : s.substr(res.first, reslen);
    }
};
