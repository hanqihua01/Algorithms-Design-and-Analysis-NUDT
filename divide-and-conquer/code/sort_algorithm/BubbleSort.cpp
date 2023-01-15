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
function   : 对数组进行冒泡
param nums : 要排序的数组引用
return     : ---
*/
void BubbleSort(vector<int>& nums, double& sum_cop, double& sum_mov)
{
	int cop = 0;
	int mov = 0;
	for (int i = 1; i < nums.size(); i++) {
		cop += 1;
		for (int j = 0; j < nums.size() - i; j++) {
			cop += 1;
			if (nums[j] > nums[j + 1]) {
				swap(nums[j], nums[j + 1]);
				mov += 1;
			}
			cop += 1;
		}
		cop += 1;
	}
	cop += 1;
	sum_cop += cop;
	sum_mov += mov;
}