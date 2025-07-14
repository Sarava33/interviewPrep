/*
Car Fleet 
There are n cars traveling to the same destination on a one-lane highway.

You are given two arrays of integers position and speed, both of length n.

position[i] is the position of the ith car (in miles)
speed[i] is the speed of the ith car (in miles per hour)
The destination is at position target miles.

A car can not pass another car ahead of it. It can only catch up to another car and then drive at the same speed as the car ahead of it.

A car fleet is a non-empty set of cars driving at the same position and same speed. A single car is also considered a car fleet.

If a car catches up to a car fleet the moment the fleet reaches the destination, then the car is considered to be part of the fleet.

Return the number of different car fleets that will arrive at the destination.

Example 1:

Input: target = 10, position = [1,4], speed = [3,2]

Output: 1
Explanation: The cars starting at 1 (speed 3) and 4 (speed 2) become a fleet, meeting each other at 10, the destination.

Example 2:

Input: target = 10, position = [4,1,0,7], speed = [2,2,1,1]

Output: 3
Explanation: The cars starting at 4 and 7 become a fleet at position 10. The cars starting at 1 and 0 never catch up to the car ahead of them. Thus, there are 3 car fleets that will arrive at the destination.
*/

#include<stack>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // combine the position and speed for each car
        vector<pair<int, int>> cars;
        for(int i = 0 ; i < position.size(); i++){
            cars.push_back({position[i], speed[i]});
        }
        // sort in reverse because everything depends on how fast the last car gets to
        // the target, no overtaking allowed
        sort(cars.rbegin(), cars.rend());
        // stack but in the form of vector
        vector<double> stk;
        // For every car we need to calculate the time to get to destination
        for(auto& p : cars){
            stk.push_back(double(((double)target - p.first) / p.second));
            // check if the time added for the cars is lesser than the first car
            // if so then they become a fleet
            if(stk.size() >= 2 && stk.back() <= stk[stk.size() - 2])
                stk.pop_back();
        }
        // Return number of fleets
        return stk.size();
    }
};
