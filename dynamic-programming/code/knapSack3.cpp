#include "knapSack.h"

int knapSack3(vector<int> W, vector<int> V, int b, int& c, int& v) {
	int compr = 0; int visit = 0;
	int n = W.size();
	vector<int> F(b + 1, 0);
	for (int i = 1; i <= n; i++) {
		compr++;
		int wi = W[i - 1]; int vi = V[i - 1]; visit += 2;
		for (int j = wi; j <= b; j++) {
			compr++;
			int tempV1 = F[j]; visit++;
			int tempV2 = F[j - wi] + vi; visit++;
			if (tempV1 < tempV2) F[j] = tempV2;
			else F[j] = tempV1;
		} compr++;
	} compr++;
	c = compr;
	v = visit;
	return F[b];
}