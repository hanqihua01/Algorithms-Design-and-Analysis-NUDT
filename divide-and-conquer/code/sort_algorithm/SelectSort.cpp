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
function   : 对数组进行选择排序
param nums : 要排序的数组引用
return     : ---
*/
void SelectSort(vector<int>& nums, double& sum_cop, double& sum_mov)
{
	int cop = 0;
	int mov = 0;
	for (int i = 0; i < nums.size() - 1; i++) {
		cop += 1;
		int temp = i;
		for (int j = i + 1; j < nums.size(); j++) {
			cop += 1;
			if (nums[j] < nums[temp]) temp = j;
			cop += 1;
		}
		cop += 1;
		swap(nums[i], nums[temp]);
		mov += 1;
	}
	cop += 1;
	sum_cop += cop;
	sum_mov += mov;
}