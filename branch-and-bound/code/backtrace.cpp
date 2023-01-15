#include "myAlgorithms.h"

// ���ݷ������ݹ麯��
void backtraceHelper(int& maxValue, int& maxWeight, std::vector<int>& values, std::vector<int>& weights, int& n, int i, int tempValue, int tempWeight) {
	if (i == n) { // ������������Ʒ������maxValue�󷵻�
		maxValue = tempValue > maxValue ? tempValue : maxValue;
		return;
	}
	int num = 0;
	while (true) { // ÿ��ѭ��ѡ��num��i����Ʒ
		if (tempWeight + weights[i] * num <= maxWeight) { // ��ο���װ��num��i����Ʒ
			tempValue += values[i] * num; // װ��
			tempWeight += weights[i] * num; // װ��
			backtraceHelper(maxValue, maxWeight, values, weights, n, i + 1, tempValue, tempWeight);
			tempValue -= values[i] * num; // ȡ��
			tempWeight -= weights[i] * num; // ȡ��
		} else { // ѡ��num��i��Ʒ�ᳬ�أ�����ѭ��
			maxValue = tempValue > maxValue ? tempValue : maxValue;
			break;
		}
		++num;
	}
	return;
}

// ���ݷ���������������⣬maxWeightΪ���������valuesΪ��Ʒ��ֵ��weightsΪ��Ʒ������nΪ��Ʒ����
int backtrace(int& maxWeight, std::vector<int>& values, std::vector<int>& weights, int& n) {
	int maxValue = 0; // maxValue��¼����ֵ
	backtraceHelper(maxValue, maxWeight, values, weights, n, 0, 0, 0);
	return maxValue;
}