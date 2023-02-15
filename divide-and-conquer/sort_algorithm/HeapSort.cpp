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

void max_heapify(vector<int>& nums, int start, int end, double &sum_cop, double &sum_mov) {
    int cop = 0;
    int mov = 0;
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) {
        cop += 1;
        if (son + 1 <= end && nums[son] < nums[son + 1]) { son++; cop += 2; }
        if (nums[dad] > nums[son]) { cop += 1;  return; }
        else {
            swap(nums[dad], nums[son]); mov += 1;
            dad = son;
            son = dad * 2 + 1;
        }
    }
    cop += 1;
    sum_cop += cop;
    sum_mov += mov;
}

/*
function   : 对数组进行堆排序
param nums : 要排序的数组引用
return     : ---
*/
void HeapSort(vector<int>& nums, double& sum_cop, double& sum_mov)
{
    int cop = 0;
    int mov = 0;
    int len = nums.size();
    for (int i = len / 2 - 1; i >= 0; i--) { max_heapify(nums, i, len - 1, sum_cop, sum_mov); cop += 1; } cop += 1;
    for (int i = len - 1; i > 0; i--) {
        cop += 1;
        swap(nums[0], nums[i]); mov += 1;
        max_heapify(nums, 0, i - 1, sum_cop, sum_mov);
    }
    cop += 1;
    sum_cop += cop;
    sum_mov += mov;
}