#include "myAlgorithms.h"
#include <iostream>

int main() {
	int n = 4;
	int maxWeight = 10;
	std::vector<int> values = { 1, 3, 5, 9 };
	std::vector<int> weights = { 2, 3, 4, 7 };

	int maxValue_backtrace = backtrace(maxWeight, values, weights, n);
	int maxValue_branchAndBound = branchAndBound(maxWeight, values, weights, n);
	std::cout << "���ݷ���" << maxValue_backtrace << std::endl;
	std::cout << "��֧�޽編��" << maxValue_branchAndBound << std::endl;
	
	// n: ÿ�����������е���Ʒ����
	n = 10;
	// maxWeight: ����������
	maxWeight = 50;
	// itemWeight: ÿ����Ʒ���������
	int itemWeight = 10;
	// amount: ������������
	int amount = 10;
	for (int a = 0; a < amount; a++) {
		std::vector<int> randomWeights;
		for (int i = 0; i < n; i++) {
			int random = rand() % itemWeight + 1;
			randomWeights.push_back(random);
		}
		 int branchs = monteCarlo(randomWeights, maxWeight, 100, n);
		 std::cout << "��������" << (a + 1) << "�ķ�֧������: " << branchs <<  std::endl;
	}
}