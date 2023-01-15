#pragma once
#include <vector>

// 回溯法解决整数背包问题，maxWeight为最大重量，values为物品价值，weights为物品重量，n为物品数量
int backtrace(int& maxWeight, std::vector<int>& values, std::vector<int>& weights, int& n);
// 分支限界法解决整数背包问题，maxWeight为最大重量，values为物品价值，weights为物品重量，n为物品数量
int branchAndBound(int& maxWeight, std::vector<int>& values, std::vector<int>& weights, int& n);
// 蒙特卡罗法
int monteCarlo(std::vector<int> weights, int maxWeight, int times, int n);