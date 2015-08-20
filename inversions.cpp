/*
ALG_3rd.pdf page 62 2-4(d)
2-4 Inversions
Let A[1..n] be an array of n distinct numbers. If i < j and A[i] > A[j], then the
pair (i, j ) is called an inversion of A.
a. List the five inversions of the array <2, 3, 8, 6, 1>.
b. What array with elements from the set {1, 2, .. ,n} has the most inversions?
How many does it have?
c. What is the relationship between the running time of insertion sort and the
number of inversions in the input array? Justify your answer.
d. Give an algorithm that determines the number of inversions in any permutation
on n elements in O(nlogn) worst-case time. (Hint: Modify merge sort.)
*/
/*
E1 vector size
E2 Index error a[iL+iR+p] -> a[iL+iR]
E3 Access wrong array L vs R
*/

#include <iostream>
#include <vector>

using namespace std;

int merge(vector<int>&a, int p, int q, int r){
	int tot = 0;
	vector<int>L, R;
	for (int i = p; i<q; i++)
		L.push_back(a[i]);
	for (int i = q; i<r; i++)
		R.push_back(a[i]);
	int iL = 0, iR = 0;
	while (iL<L.size() && iR<R.size()){
		if (L[iL] <= R[iR]){
			a[iL + iR + p] = L[iL];
			iL++;
		}
		else{
			a[iL + iR + p] = R[iR];
			tot += L.size() - iL;
			iR++;
		}
	}
	while (iL<L.size()){
		a[iL + iR + p] = L[iL];
		iL++;
	}
	while (iR<R.size()){
		a[iL + iR + p] = R[iR];
		tot += L.size() - iL;
		iR++;
	}
	return tot;
}

int count(vector<int>&a, int s, int len){
	int tot = 0;
	if (len == 1){
		return 0;
	}
	tot += count(a, s, len / 2);
	tot += count(a, s + len / 2, len - len / 2);
	tot += merge(a, s, s + len / 2, s + len);
	return tot;
}

int main(){
	int number[] = { 1,9,8,7,6,5,4,3 };
	vector<int>a;
	for (int i = 0; i<sizeof(number) / sizeof(int); i++)
		a.push_back(number[i]);
	cout << count(a, 0, a.size());
	return 0;
}
