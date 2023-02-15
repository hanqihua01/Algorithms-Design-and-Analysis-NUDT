#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <string>
#include <cstring>
#include "algorithm" 

using namespace std;
/*
function   : 对数组进行希尔排序
param nums : 要排序的数组引用
return     : ---
*/
void ShellSort(vector<int>& nums, double& sum_cop, double& sum_mov)
{
	int cop = 0;
	int mov = 0;
	int len = nums.size();
	for (int gap = len >> 1; gap > 0; gap >>= 1) {
		cop += 1;
		for (int i = gap; i < len; i++) {
			cop += 1;
			int temp = nums[i]; int j;
			for (j = i - gap; j >= 0 && nums[j] > temp; j -= gap) {
				cop += 1;
				nums[j + gap] = nums[j];
				mov += 1;
			}
			cop += 1;
			nums[j + gap] = temp;
			mov += 1;
		}
		cop += 1;
	}
	cop += 1;
	sum_cop += cop;
	sum_mov += mov;
}