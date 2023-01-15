#include <iostream>
#include <vector>
#include "greedy.h"
#include "backTracing.h"
using namespace std;

int main() {
	int m = 5; // The number of machines is m, and that of tasks is n.
	int repeat_times = 1;

	for (int n = 15; n <= 15; n++) {
		int sum1 = 0, sum2 = 0, sum3 = 0;

		for (int i = 0; i < repeat_times; i++) {
			//cout << "-------" << i + 1 << "-------" << endl;

			vector<int> tasks(n);
			for (int j = 0; j < n; j++) {
				tasks[j] = rand() % 100 + 1;
			}

			vector<vector<int>> machines1(m, vector<int>());
			int result1 = greedy1_solve(machines1, tasks, m, n); sum1 += result1;
			//cout << "Greedy1 Result: " << result1 << endl;
			//for (int i = 0; i < m; i++) {
			//	cout << "P" << i + 1 << ":";
			//	for (int j : machines1[i]) {
			//		cout << " " << j;
			//	}
			//	cout << endl;
			//}

			vector<vector<int>> machines2(m, vector<int>());
			int result2 = greedy2_solve(machines2, tasks, m, n); sum2 += result2;
			//cout << endl << "Greedy2 Result: " << result2 << endl;
			//for (int i = 0; i < m; i++) {
			//	cout << "P" << i + 1 << ":";
			//	for (int j : machines2[i]) {
			//		cout << " " << j;
			//	}
			//	cout << endl;
			//}

			vector<vector<int>> machines3(m, vector<int>());
			int result3 = backTracing(machines3, tasks, m, n); sum3 += result3;
			//cout << endl << "BackTracing Result: " << result3 << endl;
			//for (int i = 0; i < m; i++) {
			//	cout << "P" << i + 1 << ":";
			//	for (int j : machines3[i]) {
			//		cout << " " << j;
			//	}
			//	cout << endl;
			//}
		}
		cout << "n: " << n << endl;
		cout << sum1 / repeat_times << endl;
		cout << sum2 / repeat_times << endl;
		cout << sum3 / repeat_times << endl;
	}
}