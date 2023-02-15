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

void quicksort2(vector<int>& A, int p, int r, double& cop, double& mov) {
    if (p < r) {
        int pre = p - 1;
        int cur = p;
        int max = r;
        while (true) {
            while (A[cur] > A[max]) cur += 1;
            pre += 1;
            swap(A[pre], A[cur]);
            if (cur >= max) break;
            cur += 1;
        }
        quicksort2(A, p, pre - 1, cop, mov);
        quicksort2(A, pre + 1, r, cop, mov);
    }
}

/*
function   : 对数组进行快速排序
param nums : 要排序的数组引用
return     : ---
*/
void QuickSort2(vector<int>& nums, double& sum_cop, double& sum_mov)
{
    quicksort2(nums, 0, nums.size() - 1, sum_cop, sum_mov);
}