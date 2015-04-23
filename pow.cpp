/*https://leetcode.com/problems/powx-n/
Implement pow(x, n).
*/
/*
E1 Overflow: Negetive maximum is one larger than positive maximum. Don't take nagetive directly.
*/
class Solution {
public:
    double pow(double x, int n) {
        if (x==0)
            return 0;
        if (n==0)
            return 1;
        if (n<0){
            return 1.0/((pow(x,-(n+1)))*x);
        }
        double half = pow(x,n/2);
        return half * half * (n%2?x:1);
    }
};
int main(){
	Solution s;
	s.pow(1,-2147483648);
	return 0;
}
