/*https://leetcode.com/problems/bitwise-and-of-numbers-range/
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

For example, given the range [5, 7], you should return 4.
*/


/*
E1 Signed integer overflow. Using unsigned integers when deal with bitwise operations.
E2 Take '&' as '|'. 
*/
#include <iostream>
using namespace std; 
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
    	unsigned int mm = m,nn = n;
        unsigned int ret = 0;
        unsigned int len = n-m+1;
        for (unsigned pos = 0;pos<31;pos++){
            unsigned int cur_loop = 1 << (pos + 1);
            unsigned int cur_bit = 1;
            if (len / cur_loop > 0) 
                cur_bit = 0;
            else if (mm % cur_loop < cur_loop / 2 || nn % cur_loop < mm%cur_loop || nn % cur_loop < cur_loop / 2) 
                cur_bit = 0;
            
            ret |= cur_bit << pos;
            
        }
        return ret;
    }
};
int main(){
    Solution s;
    cout << s.rangeBitwiseAnd(0,0);
    return 0;    
}
