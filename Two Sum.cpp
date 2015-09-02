
/*
Two Sum Total Accepted: 128998 Total Submissions: 725749 My Submissions Question Solution 
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

E0 Map. E1 Template name vs Variable name.
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> numbers;
        vector<int> ret;
        for (int i=0;i<nums.size();i++){
            auto itr = numbers.find(target - nums[i]);
            if (itr!=numbers.end()){
                ret.push_back(itr->second);
                ret.push_back(i+1);
                break;
            }
            numbers[nums[i]] = i+1;
        }
        return ret;
    }
};