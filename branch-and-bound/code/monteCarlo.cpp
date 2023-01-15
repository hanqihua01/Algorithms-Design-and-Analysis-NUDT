#include "myAlgorithms.h"
#include <iostream>

int estimateBranchs(std::vector<int>& weights, int& maxWeight, int& n) {
	int num = 1; // �ڵ�����
	int branch = 1; // ��ǰ���֧����
	int weight = 0; // ��ǰ��ѡ��Ʒ������
	for (int i = 0; i < n; i++) {
		// ���㵱ǰ��Ʒ��ѡ��Χ
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