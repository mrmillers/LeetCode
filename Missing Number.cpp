/*
Missing Number Total Accepted: 8295 Total Submissions: 26463 My Submissions Question Solution 
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for (int i=0;i<nums.size();i++){
            sum += i;
            sum -= nums[i];
        }
        sum += nums.size();
        return sum;
    }
};