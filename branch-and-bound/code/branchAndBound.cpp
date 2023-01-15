#include "myAlgorithms.h"
#include <map>

// 分支限界法帮助递归函数
void branchAndBoundHelper(int& maxValue, int& maxWeight, std::vector<int>& values, std::vector<int>& weights, int& n, int i, int tempValue, int tempWeight) {
	if (i == n) { // 考虑完所有物品，更新maxValue后返回
		maxValue = tempValue > maxValue ? tempValue : maxValue;
		return;
	}
	// 计算可能的最大价值进行分支限界
	double potential = tempValue + (maxWeight - tempWeight) * ((double)values[i] / (double)weights[i]);
	if (potential < maxValue) return;
	int num = 0;
	while (true) { // 每次循环选择num个i号物品
		if (tempWeight + weights[i] * num <= maxWeight) { // 如何可以装下num个i号物品
			tempValue += values[i] * num; // 装入
			tempWeight += weights[i] * num; // 装入
			branchAndBoundHelper(maxValue, maxWeight, values, weights, n, i + 1, tempValue, tempWeight);
			tempValue -= values[i] * num; // 取出
			tempWeight -= weights[i] * num; // 取出
		}
		else { // 选择num个i物品会超重，结束循环
			maxValue = tempValue > maxValue ? tempValue : maxValue;
			break;
		}
		++num;
	}
	return;
}

// 分支限界法解决整数背包问题，maxWeight为最大重量，values为物品价值，weights为物品重量，n为物品数量
int branchAndBound(int& maxWeight, std::vector<int>& values, std::vector<int>& weights, int& n) {
	// 根据性价比排序
	for (int i = 0; i < n; i++) {
		double maxVM = 0;
		int maxIndex = i;
		for (int j = i; j < n; j++) {
			double VM = (double)values[j] / (double)weights[j];
			if (VM > maxVM) {
				maxVM = VM;
				maxIndex = j;
			}
		}
		std::swap(values[i], values[maxIndex]);
		std::swap(weights[i], weights[maxIndex]);
	}

	int maxValue = 0;
	branchAndBoundHelper(maxValue, maxWeight, values, weights, n, 0, 0, 0);
	return maxValue;
}