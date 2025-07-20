/*
Median of Two Sorted Arrays 
You are given two integer arrays nums1 and nums2 of size m and n respectively, where each is sorted in ascending order. Return the median value among all elements of the two arrays.

Your solution must run in 
O(log(m+n)) time.

Example 1:

Input: nums1 = [1,2], nums2 = [3]

Output: 2.0
Explanation: Among [1, 2, 3] the median is 2.

Example 2:

Input: nums1 = [1,3], nums2 = [2,4]

Output: 2.5
*/

#include<vector>
using namespace std;

// O(n+m)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0, m = nums1.size(), n = nums2.size();
        vector<int> nums;
        while(true){
            if((j == n && i < m) || (i < m && j < n && nums1[i] <= nums2[j])){
                nums.push_back(nums1[i]);
                i++;
            }
            else if((i == m && j < n) || (i < m && j < n && nums2[j] <= nums1[i])){
                nums.push_back(nums2[j]);
                j++;
            }
            if(i == m && j == n)
                break;
        }
        int tot = m + n;
        if(tot % 2 == 1)
            return (double) nums[tot/2];
        
        return (double) (nums[tot/2] + nums[tot/2 - 1])/2;
    }
};

// log(m + n)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& A = nums1;
        vector<int>& B = nums2;
        int total = A.size() + B.size();
        int half = (total + 1) / 2;

        if (B.size() < A.size()) {
            swap(A, B);
        }

        int l = 0;
        int r = A.size();
        while (l <= r) {
            int i = (l + r) / 2;
            int j = half - i;

            int Aleft = i > 0 ? A[i - 1] : INT_MIN;
            int Aright = i < A.size() ? A[i] : INT_MAX;
            int Bleft = j > 0 ? B[j - 1] : INT_MIN;
            int Bright = j < B.size() ? B[j] : INT_MAX;

            if (Aleft <= Bright && Bleft <= Aright) {
                if (total % 2 != 0) {
                    return max(Aleft, Bleft);
                }
                return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
            } else if (Aleft > Bright) {
                r = i - 1;
            } else {
                l = i + 1;
            }
        }
        return -1;
    }
};