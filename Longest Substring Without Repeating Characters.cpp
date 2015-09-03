/*
Longest Substring Without Repeating Characters Total Accepted: 89347 Total Submissions: 442324 My Submissions Question Solution 
Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
E0 wrong Algorithm. E1 index bondery(special case: len==1). 
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> index;
        int max = 0;
        int start = -1;
        for (int i=0;i<s.length();i++){
            auto itr = index.find(s[i]);
            if (itr != index.end()){
                start = start>itr->second?start:itr->second;
                int len = i - start;
                max = len>max?len:max;
            }else {
                max = i - start > max? i-start:max;
            }
            index[s[i]] = i;
        }
        
        return max;
    }
};