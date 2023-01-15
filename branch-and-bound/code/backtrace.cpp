#include "myAlgorithms.h"

// 回溯法帮助递归函数
void backtraceHelper(int& maxValue, int& maxWeight, std::vector<int>& values, std::vector<int>& weights, int& n, int i, int tempValue, int tempWeight) {
	if (i == n) { // 考虑完所有物品，更新maxValue后返回
		maxValue = tempValue > maxValue ? tempValue : maxValue;
		return;
	}
	int num = 0;
	while (true) { // 每次循环选择num个i号物品
		if (tempWeight + weights[i] * num <= maxWeight) { // 如何可以装下num个i号物品
			tempValue += values[i] * num; // 装入
			tempWeight += weights[i] * num; // 装入
			backtraceHelper(maxValue, maxWeight, values, weights, n, i + 1, tempValue, tempWeight);
			tempValue -= values[i] * num; // 取出
			tempWeight -= weights[i] * num; // 取出
		} else { // 选择num个i物品会超重，结束循环
			maxValue = tempValue > maxValue ? tempValue : maxValue;
			break;
		}
		++num;
	}
	return;
}

// 回溯法解决整数背包问题，maxWeight为最大重量，values为物品价值，weights为物品重量，n为物品数量
int backtrace(int& maxWeight, std::vector<int>& values, std::vector<int>& weights, int& n) {
	int maxValue = 0; // maxValue记录最大价值
	backtraceHelper(maxValue, maxWeight, values, weights, n, 0, 0, 0);
	return maxValue;
}