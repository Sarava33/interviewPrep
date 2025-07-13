/*
Evaluate Reverse Polish Notation
 
You are given an array of strings tokens that represents a valid arithmetic expression in Reverse Polish Notation.

Return the integer that represents the evaluation of the expression.

The operands may be integers or the results of other operations.
The operators include '+', '-', '*', and '/'.
Assume that division between integers always truncates toward zero.
Example 1:

Input: tokens = ["1","2","+","3","*","4","-"]

Output: 5

Explanation: ((1 + 2) * 3) - 4 = 5
*/

#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(string s : tokens){
            if(s == "+"){
                int x = stk.top();
                stk.pop();
                int y = stk.top();
                stk.pop();
                stk.push(x + y);
            }
            else if(s == "-"){
                int x = stk.top();
                stk.pop();
                int y = stk.top();
                stk.pop();
                stk.push(y - x);
            }
            else if(s == "*"){
                int x = stk.top();
                stk.pop();
                int y = stk.top();
                stk.pop();
                stk.push(x * y);
            }
            else if(s == "/"){
                int x = stk.top();
                stk.pop();
                int y = stk.top();
                stk.pop();
                stk.push(y / x);
            }
            else
                stk.push(stoi(s));
        }
        return stk.top();
    }
};
