#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <string>
#include <cstring>

using namespace std;

void InsertSort(vector<int>&, double &sum_cop, double &sum_mov);
void BubbleSort(vector<int>&, double& sum_cop, double& sum_mov);
void SelectSort(vector<int>&, double& sum_cop, double& sum_mov);
void ShellSort(vector<int>&, double& sum_cop, double& sum_mov);
void MergeSort(vector<int>&, double& sum_cop, double& sum_mov);
void QuickSort(vector<int>&, double& sum_cop, double& sum_mov);
void HeapSort(vector<int>&, double& sum_cop, double& sum_mov);
void CountingSort(vector<int>&, double& sum_cop, double& sum_mov);

void QuickSort1(vector<int>&, double& sum_cop, double& sum_mov);
void QuickSort2(vector<int>&, double& sum_cop, double& sum_mov);