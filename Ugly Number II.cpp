/*
Ugly Number II Total Accepted: 1995 Total Submissions: 9924 My Submissions Question Solution 
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number.

E0: int overflow. E1: count error.
*/

#include <set>
class Solution {
public:
    int nthUglyNumber(int n) {
        using namespace std;
        set<long> ugly;
        ugly.insert(1);
        n--;
        while (n--){
            auto it = ugly.begin();
            long uglyNumber = *it;
            ugly.erase(it);
            if (uglyNumber * 2 >0) ugly.insert(uglyNumber*2);
            if (uglyNumber * 3 >0) ugly.insert(uglyNumber*3);
            if (uglyNumber * 5 >0) ugly.insert(uglyNumber*5);
        }
        return *(ugly.begin());
        
    }
};