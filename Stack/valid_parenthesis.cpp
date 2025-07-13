/*
Valid Parentheses 
You are given a string s consisting of the following characters: '(', ')', '{', '}', '[' and ']'.

The input string s is valid if and only if:

Every open bracket is closed by the same type of close bracket.
Open brackets are closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
Return true if s is a valid string, and false otherwise.

Example 1:

Input: s = "[]"

Output: true
Example 2:

Input: s = "([{}])"

Output: true
Example 3:

Input: s = "[(])"

Output: false
*/

#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(char c : s){
            if(!stk.empty() && c == ')' && stk.top() == '(')
                stk.pop();
            else if(!stk.empty() && c == '}' && stk.top() == '{')
                stk.pop();
            else if(!stk.empty() && c == ']' && stk.top() == '[')
                stk.pop();
            else
                stk.push(c);
        }
        return stk.empty();
    }
};
