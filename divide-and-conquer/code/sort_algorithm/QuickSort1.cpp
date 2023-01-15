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

void quicksort1(vector<int>& A, int p, int r, double& sum_cop, double& sum_mov) {
    if (p < r) {
        int i = p;
        int j = r;
        while (true) {
            while (A[j] > A[i]) j = j - 1;
            swap(A[i], A[j]);
            while (i < j && A[i] <= A[j]) i = i + 1;
            swap(A[i], A[j]);
            if (i >= j) break;
        }
        quicksort1(A, p, j - 1, sum_cop, sum_mov);
        quicksort1(A, j + 1, r, sum_cop, sum_mov);
    }
}

/*
function   : 对数组进行快速排序
param nums : 要排序的数组引用
return     : ---
*/
void QuickSort1(vector<int>& nums, double& sum_cop, double& sum_mov)
{
    quicksort1(nums, 0, nums.size() - 1, sum_cop, sum_mov);
}