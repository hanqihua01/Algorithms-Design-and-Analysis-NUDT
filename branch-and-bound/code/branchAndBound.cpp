#include "myAlgorithms.h"
#include <map>

// ��֧�޽編�����ݹ麯��
void branchAndBoundHelper(int& maxValue, int& maxWeight, std::vector<int>& values, std::vector<int>& weights, int& n, int i, int tempValue, int tempWeight) {
	if (i == n) { // ������������Ʒ������maxValue�󷵻�
		maxValue = tempValue > maxValue ? tempValue : maxValue;
		return;
	}
	// ������ܵ�����ֵ���з�֧�޽�
	double potential = tempValue + (maxWeight - tempWeight) * ((double)values[i] / (double)weights[i]);
	if (potential < maxValue) return;
	int num = 0;
	while (true) { // ÿ��ѭ��ѡ��num��i����Ʒ
		if (tempWeight + weights[i] * num <= maxWeight) { // ��ο���װ��num��i����Ʒ
			tempValue += values[i] * num; // װ��
			tempWeight += weights[i] * num; // װ��
			branchAndBoundHelper(maxValue, maxWeight, values, weights, n, i + 1, tempValue, tempWeight);
			tempValue -= values[i] * num; // ȡ��
			tempWeight -= weights[i] * num; // ȡ��
		}
		else { // ѡ��num��i��Ʒ�ᳬ�أ�����ѭ��
			maxValue = tempValue > maxValue ? tempValue : maxValue;
			break;
		}
		++num;
	}
	return;
}

// ��֧�޽編��������������⣬maxWeightΪ���������valuesΪ��Ʒ��ֵ��weightsΪ��Ʒ������nΪ��Ʒ����
int branchAndBound(int& maxWeight, std::vector<int>& values, std::vector<int>& weights, int& n) {
	// �����Լ۱�����
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