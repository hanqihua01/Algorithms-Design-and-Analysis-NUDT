#pragma once
#include <vector>

// ���ݷ���������������⣬maxWeightΪ���������valuesΪ��Ʒ��ֵ��weightsΪ��Ʒ������nΪ��Ʒ����
int backtrace(int& maxWeight, std::vector<int>& values, std::vector<int>& weights, int& n);
// ��֧�޽編��������������⣬maxWeightΪ���������valuesΪ��Ʒ��ֵ��weightsΪ��Ʒ������nΪ��Ʒ����
int branchAndBound(int& maxWeight, std::vector<int>& values, std::vector<int>& weights, int& n);
// ���ؿ��޷�
int monteCarlo(std::vector<int> weights, int maxWeight, int times, int n);