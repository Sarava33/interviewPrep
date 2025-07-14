/*
Daily Temperatures 
You are given an array of integers temperatures where temperatures[i] represents the daily temperatures on the ith day.

Return an array result where result[i] is the number of days after the ith day before a warmer temperature appears on a future day. If there is no day in the future where a warmer temperature will appear for the ith day, set result[i] to 0 instead.

Example 1:

Input: temperatures = [30,38,30,36,35,40,28]

Output: [1,4,1,2,1,0,0]
Example 2:

Input: temperatures = [22,21,20]

Output: [0,0,0]
*/

#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res (n, 0);
        stack<int> stk;
        for(int t = 0; t < n; t++){
            while(!stk.empty() && temperatures[t] > temperatures[stk.top()]){
                int val = stk.top();
                stk.pop();
                res[val] = t - val;
            }
            stk.push(t);
        }
        return res;
    }
};
