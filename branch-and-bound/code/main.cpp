#include "myAlgorithms.h"
#include <iostream>

int main() {
	int n = 4;
	int maxWeight = 10;
	std::vector<int> values = { 1, 3, 5, 9 };
	std::vector<int> weights = { 2, 3, 4, 7 };

	int maxValue_backtrace = backtrace(maxWeight, values, weights, n);
	int maxValue_branchAndBound = branchAndBound(maxWeight, values, weights, n);
	std::cout << "回溯法：" << maxValue_backtrace << std::endl;
	std::cout << "分支限界法：" << maxValue_branchAndBound << std::endl;
	
	// n: 每个测试样本中的物品数量
	n = 10;
	// maxWeight: 背包总重量
	maxWeight = 50;
	// itemWeight: 每个物品的最大重量
	int itemWeight = 10;
	// amount: 测试样本数量
	int amount = 10;
	for (int a = 0; a < amount; a++) {
		std::vector<int> randomWeights;
		for (int i = 0; i < n; i++) {
			int random = rand() % itemWeight + 1;
			randomWeights.push_back(random);
		}
		 int branchs = monteCarlo(randomWeights, maxWeight, 100, n);
		 std::cout << "测试样本" << (a + 1) << "的分支数估计: " << branchs <<  std::endl;
	}
}