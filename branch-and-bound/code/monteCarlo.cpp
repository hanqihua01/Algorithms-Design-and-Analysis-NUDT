#include "myAlgorithms.h"
#include <iostream>

int estimateBranchs(std::vector<int>& weights, int& maxWeight, int& n) {
	int num = 1; // 节点数量
	int branch = 1; // 当前层分支数量
	int weight = 0; // 当前已选物品总重量
	for (int i = 0; i < n; i++) {
		// 计算当前物品可选范围
		int temp = (maxWeight - weight) / weights[i];
		temp += 1;
		branch *= temp;
		num += branch;
		weight += (rand() % temp) * weights[i];
	}
	return num;
}

int monteCarlo(std::vector<int> weights, int maxWeight, int times, int n) {
	int sum = 0;
	for (int i = 0; i < times; i++) {
		sum += estimateBranchs(weights, maxWeight, n);
	}
	return sum / times;
}