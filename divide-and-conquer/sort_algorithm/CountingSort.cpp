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

vector<int> cnt(123456, 0);

/*
function   : 对数组进行计数排序
param nums : 要排序的数组引用
return     : ---
*/
void CountingSort(vector<int>& nums, double& sum_cop, double& sum_mov)
{
    int cop = 0;
    int mov = 0;
    int max = nums[0];
    for (int i = 0; i < nums.size(); i++) {
        max = nums[i] > max ? nums[i] : max;
    }
    for (auto i : nums) { cnt[i]++; cop += 1; mov += 1; } cop += 1;
    int j = 0;
    for (int i = 0; i < 123456; i++) {
        cop += 1;
        while (cnt[i] > 0) {
            cnt[i]--;
            cop += 1; mov += 1;
            nums[j] = i; j++; mov += 1;
        } cop += 1;
    } cop += 1;
    sum_cop += cop;
    sum_mov += mov;
}