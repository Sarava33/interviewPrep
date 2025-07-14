/*
Generate Parentheses 
You are given an integer n. Return all well-formed parentheses strings that you can generate with n pairs of parentheses.

Example 1:

Input: n = 1

Output: ["()"]
Example 2:

Input: n = 3

Output: ["((()))","(()())","(())()","()(())","()()()"]
*/

#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    
    vector<string> res;
    string stk;
    
    void backtrack(int openN, int closeN, int n){
        if(openN == n && closeN == openN){
            res.push_back(stk);
            return;
        }

        if(openN < n){
            stk += '(';
            backtrack(openN + 1, closeN, n);
            stk.pop_back();
        }

        if(closeN < openN){
            stk += ')';
            backtrack(openN, closeN + 1, n);
            stk.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        backtrack(0, 0, n);
        return res;
    }
};
