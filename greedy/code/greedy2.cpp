#include "greedy.h"
#include <algorithm>

// Ì°ÐÄ²ßÂÔ£ºÄæ½µÌ°ÐÄ
int greedy2_solve(vector<vector<int>>& machines, vector<int> tasks, int m, int n) {
	sort(tasks.begin(), tasks.end(), greater<int>());
	return greedy1_solve(machines, tasks, m, n);
}