#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <string>
#include <cstring>
#include <utility>
#include "algorithm" 

using namespace std;
/*
function   : 对数组进行归并排序
param nums : 要排序的数组引用
return     : ---
*/
void MergeSort(vector<int>& nums, double& sum_cop, double& sum_mov)
{
	int cop = 0;
	int mov = 0;
	int len = nums.size();
	vector<int> b(nums.size(), 0);
	for (int seg = 1; seg < len; seg += seg) {
		cop += 1;
		for (int start = 0; start < len; start += seg + seg) {
			cop += 1;
			int low = start, mid = min(start + seg, len), high = min(start + seg + seg, len);
			int k = low;
			int start1 = low, end1 = mid;
			int start2 = mid, end2 = high;
			while (start1 < end1 && start2 < end2) {
				cop += 2;
				b[k++] = nums[start1] < nums[start2] ? nums[start1++] : nums[start2++];
				cop += 1;
				mov += 1;
			} cop += 2;
			while (start1 < end1) {
				cop += 1;
				b[k++] = nums[start1++];
				mov += 1;
			} cop += 1;
			while (start2 < end2) {
				cop += 1;
				b[k++] = nums[start2++];
				mov += 1;
			} cop += 1;
		}
		cop += 1;
		nums.assign(b.begin(), b.end());
		mov += b.size();
	}
	cop += 1;
	sum_cop += cop;
	sum_mov += mov;
}