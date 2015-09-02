/*
Valid Anagram Total Accepted: 18694 Total Submissions: 54957 My Submissions Question Solution 
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

E0 scope of 'int i'.
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        int alph[26] = {0};
        if (s.length()!=t.length()){
            return false;
        }
        for (int i=0;i<s.length();i++){
            alph[s[i]-'a'] ++;
            alph[t[i]-'a'] --;
        }
        for (int i=0;i<26;i++){
            if (alph[i]!=0)
                return false;
        }
        return true;
    }
};