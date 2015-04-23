/*https://leetcode.com/problems/maximum-gap/
Reference: http://cgm.cs.mcgill.ca/~godfried/teaching/dm-reading-assignments/Maximum-Gap-Problem.pdf

Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
*/
/*
E1 Array index exceed

*/
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size()<2) return 0;
        int max= nums[0];
        int min= nums[0];
        int* bucketMin = new int[nums.size() - 1];
		int* bucketMax = new int[nums.size() - 1];
		
		for (int i=1;i<nums.size();i++){
        	max = max < nums[i]?nums[i]:max;
        	min = min > nums[i]?nums[i]:min;
        	bucketMin[i-1] = -1;
        	bucketMax[i-1] = -1;
		}
		if (max == min) return 0;
		double bucketGap = (max - min) / (nums.size() - 1.0);
		for (int i=0;i<nums.size();i++){
			if (nums[i]!=max && nums[i]!=min){
				int bucketIndex = floor((nums[i]-min) / bucketGap);
				if (bucketMin[bucketIndex] == -1 || bucketMin[bucketIndex] > nums[i])
					bucketMin[bucketIndex] = nums[i];
				if (bucketMax[bucketIndex] == -1 || bucketMax[bucketIndex] < nums[i])
					bucketMax[bucketIndex] = nums[i];
			}
		}
		int gap = floor(bucketGap);
		for (int i=0;i<nums.size() - 1;i++){
			if (bucketMin[i]!=-1){
				gap = gap > bucketMin[i] - min? gap : bucketMin[i] - min;
				min = bucketMax[i];
			}
		}
		gap = max-min>gap?max-min:gap;
		
		delete[]bucketMin;
		delete[]bucketMax;
		return gap;
    }
};

int main(){
	Solution s;
	int x[] = {15252,16764,27963,7817,26155,20757,3478,22602,20404,6739,16790,10588,16521,6644,20880,15632,27078,25463,20124,15728,30042,16604,17223,4388,23646,32683,23688,12439,30630,3895,7926,22101,32406,21540,31799,3768,26679,21799,23740};
	vector<int> v;
	for (int i=0;i<(sizeof(x)/sizeof(int));i++){
		v.push_back(x[i]);
	}
	cout<<s.maximumGap(v);
	
	
}
