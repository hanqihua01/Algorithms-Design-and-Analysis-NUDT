#include "horseHamilton.h"
#include <iostream>
#include <iomanip>

// �жϲ����Ƿ����Ҫ��
bool isStandard(int m, int n, int sx, int sy) {
	if (m < 6 || n < 6) return false;
	if ((m % 2) || (n % 2)) return false;
	if (std::abs(m - n) > 2) return false;
	if (sx < 1 || sx > m || sy < 1 || sy > n) return false;
	return true;
}

// ����m*n��λ�����ڸ�ʽ�����
int countDigit(int m, int n) {
	int digit = 0;
	int product = m * n;
	while (product) {
		product /= 10;
		digit += 1;
	}
	return digit;
}

int main() {
	int m, n; int sx, sy;
	std::cout << "���̿��m�ͳ���n, ����:" << std::endl;
	std::cout << "1. m >= 6, n >= 6;" << std::endl;
	std::cout << "2. m �� n ��Ϊż��;" << std::endl;
	std::cout << "3. |m - n| <= 2." << std::endl;
	std::cout << "��ʼ�������sx����ʼ��������sy, ����:" << std::endl;
	std::cout << "1. 1 <= sx <= m;" << std::endl;
	std::cout << "2. 1 <= sy <= n;" << std::endl;
	while (true) {
		std::cout << "������m: "; std::cin >> m;
		std::cout << "������n: "; std::cin >> n;
		std::cout << "������sx: "; std::cin >> sx;
		std::cout << "������sy: "; std::cin >> sy;
		if (isStandard(m, n, sx, sy)) {
			std::cout << "������ϱ�׼!" << std::endl;
			std::cout << "-----------------------" << std::endl;
			break;
		}
		else {
			std::cout << "���벻���Ϲ淶, ����������!" << std::endl;
		}
	}

	double start_time = clock();

	// ��ȡ���ϱ�׼m��n�󣬵���horseHamilton()�����������ؽ�������ڶ�ά������
	std::vector<std::vector<int>> route = horseHamilton(m, n, sx, sy);
	// ����m*n��λ�����ڸ�ʽ�����
	int digit = countDigit(m, n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << std::setw(digit + 1) << route[i][j];
		}
		std::cout << std::endl;
	}

	double end_time = clock();
	double time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

	std::cout << "�㷨ִ��ʱ��Ϊ: " << time << std::endl;
}