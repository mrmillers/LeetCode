/*
Single Number III Total Accepted: 2434 Total Submissions: 6881 My Submissions Question Solution 
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?

E0 x & -x.
*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int all = 0,a = 0,b = 0;
        for (int x : nums){
            all ^= x;
        }
        all = all & - all;
        for (int x : nums){
            if (x & all) 
                a ^= x;
            else
                b ^= x;
        }
        vector<int> ret;
        ret.push_back(a);
        ret.push_back(b);
        return ret;
    }
};