#include "knapSack.h"

int knapSack1(vector<int> W, vector<int> V, int b, int& c, int &v) {
	int compr = 0; int visit = 0;
	int n = W.size();
	vector<vector<int>> F(n + 1, vector<int>(b + 1, 0));
	for (int i = 1; i <= n; i++) {
		compr++;
		int wi = W[i - 1]; int vi = V[i - 1]; visit += 2;
		for (int j = 1; j < wi; j++) {
			compr++;
			F[i][j] = F[i - 1][j]; visit++;
		} compr++;
		for (int j = wi; j <= b; j++) {
			compr++;
			int temp = 0;
			for (int k = 0; k <= j / wi; k++) {
				compr++;
				int tempV = F[i - 1][j - k * wi] + k * vi; visit++;
				if (tempV > temp)
					temp = tempV;
			} compr++;
			F[i][j] = temp;
		} compr++;
	} compr++;
	c = compr;
	v = visit;
	return F[n][b];
}