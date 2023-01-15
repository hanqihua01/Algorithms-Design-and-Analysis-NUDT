#include "knapSack.h"
#include <iostream>
#include <ctime>

int main() {
	int num_kinds = 300;
	int num_repeat = 1000;
	int max_w = 10;
	int max_v = 10;
	int b = 150;
	double sum_time = 0;
	int sum_c = 0;
	int sum_v = 0;
	for (int i = 0; i < num_repeat; i++) {
		vector<int> W(num_kinds, 0);
		vector<int> V(num_kinds, 0);
		for (int j = 0; j < num_kinds; j++) {
			W[j] = rand() % max_w + 1;
			V[j] = rand() % max_v + 1;
		}
		clock_t start_time, end_time;
		int c = 0, v = 0;
		start_time = clock();
		knapSack1(W, V, b, c, v);
		end_time = clock();
		sum_time += (double)(end_time - start_time) / CLOCKS_PER_SEC;
		sum_c += c;
		sum_v += v;
	}
	cout << "The average time is: " << sum_time / num_repeat << endl;
	cout << "The average times of comparing is: " << sum_c / num_repeat << endl;
	cout << "The average times of visiting is: " << sum_v / num_repeat << endl;
}