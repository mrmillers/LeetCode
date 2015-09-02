/*
Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.

For example,
123 -> "One Hundred Twenty Three"
12345 -> "Twelve Thousand Three Hundred Forty Five"
1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"

E0 C++ static const Syntax. E1 Typo. E2 space. 
*/
class Solution {
public:
    string numberToWords(int num) {
        string s;
        if (num == 0){
            return units[0];
        }
        int baseCnt = 0;
        while (num!=0){
            if (s.length()>0 && num % 1000 !=0){
                s = " " + s;
            }
            s = chunkToWords(num % 1000) + (num % 1000 == 0 ?"": base[baseCnt]) + s;
            num /= 1000;
            baseCnt ++;
        }
        return s;
    }
private:
    static const char *const units[];
    static const char *const tens[];
    static const char *const base[];
    string chunkToWords(int num) {
        string s;
        if (num / 100 != 0){
            s = s + units[num / 100] + " Hundred" + (num % 100 == 0 ? "" : " ");
        }
        if (num % 100 > 0){
            if (num % 100 < 20){
                s = s + units[num % 100];
            }else {
                s = s + tens[num % 100 / 10] + ((num % 10 == 0)?"":string(" ") + units[num % 10]);
            }
        }
        return s;
    }
};

const char * const Solution::units[] = {"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine", "Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
const char * const Solution::tens[] = {"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
const char * const Solution::base[] = {""," Thousand"," Million"," Billion"};