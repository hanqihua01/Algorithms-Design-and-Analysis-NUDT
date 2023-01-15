#include "greedy.h"

// 贪心策略：负载均衡
int greedy1_solve(vector<vector<int>>& machines, vector<int> tasks, int m, int n) {
	vector<int> len(m, 0);
	for (int j : tasks) {
		int min = 0;
		for (int i = 1; i < m; i++) {
			if (len[i] < len[min]) min = i;
		}
		machines[min].push_back(j);
		len[min] += j;
	}
	int max = 0;
	for (int i = 1; i < m; i++) {
		if (len[i] > len[max]) max = i;
	}
	return len[max];
}