#include "backTracing.h"
#include <iostream>
int m, n;
int best = INT_MAX;
vector<int> len;
vector<int> tasks;
vector<vector<int>> machines;
vector<vector<int>> machines_result;

void search(int dep) {
	if (dep == n) {
		int max = 0;
		for (int i = 0; i < m; i++) {
			if (len[i] > max) max = len[i];
		}
		if (max < best) {
			best = max;
			machines_result.assign(machines.begin(), machines.end());
		}
		return;
	}
	for (int i = 0; i < m; i++) {
		len[i] += tasks[dep];
		machines[i].push_back(tasks[dep]);
		if (len[i] < best) search(dep + 1);
		len[i] -= tasks[dep];
		machines[i].pop_back();
	}
}

int backTracing(vector<vector<int>>& machines_par, vector<int> tasks_par, int m_par, int n_par) {
	m = m_par;
	n = n_par;
	best = INT_MAX;
	len.assign(m, 0);
	tasks.assign(tasks_par.begin(), tasks_par.end());
	machines.assign(m, vector<int>());
	machines_result.assign(m, vector<int>());
	search(0);
	machines_par.assign(machines_result.begin(), machines_result.end());
	return best;
}