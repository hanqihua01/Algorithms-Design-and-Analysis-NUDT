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

int partition(vector<int>& A, int p, int r, double& sum_cop, double& sum_mov) {
    int cop = 0;
    int mov = 0;
    int x = A[p];
    int i = p;
    int j = r + 1;
    while (true) {
        do { j = j - 1; cop += 1; }
        while (A[j] > x);
        do { i = i + 1; cop += 2; }
        while (i < j && A[i] <= x);
        if (i < j) { swap(A[i], A[j]); mov += 1; }
        else return j;
    }
    sum_cop += cop;
    sum_mov += mov;
}

void quicksort(vector<int>& A, int p, int r, double& sum_cop, double& sum_mov) {
    int cop = 0;
    int mov = 0;
    if (p < r) {
        int q = partition(A, p, r, sum_cop, sum_mov);
        swap(A[p], A[q]); mov += 1;
        quicksort(A, p, q - 1, sum_cop, sum_mov);
        quicksort(A, q + 1, r, sum_cop, sum_mov);
    }
    cop += 1;
    sum_cop += cop;
    sum_mov += mov;
}

/*
function   : 对数组进行快速排序
param nums : 要排序的数组引用
return     : ---
*/
void QuickSort(vector<int>& nums, double& sum_cop, double& sum_mov)
{
	quicksort(nums, 0, nums.size() - 1, sum_cop, sum_mov);
}