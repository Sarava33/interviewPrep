/*
Encode and Decode Strings

Design an algorithm to encode a list of strings to a single string. The encoded string is then decoded back to the original list of strings.

Please implement encode and decode

Example 1:

Input: ["neet","code","love","you"]

Output:["neet","code","love","you"]
Example 2:

Input: ["we","say",":","yes"]

Output: ["we","say",":","yes"]
*/

#include<vector>
#include<string>
using namespace std;

class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(const string& s : strs)
            res += to_string(s.size()) + "#" + s;
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while(i < s.size()){
            int j = i;
            while(s[j] != '#')
                j++;
            int len = stoi(s.substr(i, j - i));
            i = j + 1;
            j = i + len;
            res.push_back(s.substr(i, len));
            i = j;
        }
        return res;
    }
};
