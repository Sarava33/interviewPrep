/*
Valid Palindrome
 
Given a string s, return true if it is a palindrome, otherwise return false.

A palindrome is a string that reads the same forward and backward. It is also case-insensitive and ignores all non-alphanumeric characters.

Note: Alphanumeric characters consist of letters (A-Z, a-z) and numbers (0-9).

Example 1:

Input: s = "Was it a car or a cat I saw?"

Output: true
Explanation: After considering only alphanumerical characters we have "wasitacaroracatisaw", which is a palindrome.

Example 2:

Input: s = "tab a cat"

Output: false
*/

#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while(l < r){
            while(!isalnum(s[l]) && l < r)
                l++;
            while(!isalnum(s[r]) && l < r)
                r--;
            if(tolower(s[l]) != tolower(s[r]))
                return false;
            l++;
            r--;
        }
        return true;
    }
};
