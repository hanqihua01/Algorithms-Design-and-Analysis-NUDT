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
function   : 对数组进行插入排序
param nums : 要排序的数组引用
return     : ---
*/
void InsertSort(vector<int>& nums, double &sum_cop, double &sum_mov)
{
	int cop = 0;
	int mov = 0;
	for (int i = 1; i < nums.size(); i++)
	{
		cop += 1; // i < nums.size()
		int j = i, key = nums[j];
		while (j > 0 && nums[j - 1] > key)
		{
			cop += 2; // j > 0 && nums[j - 1] > key
			nums[j] = nums[j - 1];
			mov += 1; // nums[j] = nums[j - 1]
			j--;
		}
		cop += 2; // j > 0 && nums[j - 1] > key
		nums[j] = key;
	}
	cop += 1; // i < nums.size()
	sum_cop += cop;
	sum_mov += mov;
}