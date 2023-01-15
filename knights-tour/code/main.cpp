#include "horseHamilton.h"
#include <iostream>
#include <iomanip>

// 判断参数是否符合要求
bool isStandard(int m, int n, int sx, int sy) {
	if (m < 6 || n < 6) return false;
	if ((m % 2) || (n % 2)) return false;
	if (std::abs(m - n) > 2) return false;
	if (sx < 1 || sx > m || sy < 1 || sy > n) return false;
	return true;
}

// 计算m*n的位数用于格式化输出
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
	std::cout << "棋盘宽度m和长度n, 满足:" << std::endl;
	std::cout << "1. m >= 6, n >= 6;" << std::endl;
	std::cout << "2. m 和 n 均为偶数;" << std::endl;
	std::cout << "3. |m - n| <= 2." << std::endl;
	std::cout << "起始点横坐标sx和起始点纵坐标sy, 满足:" << std::endl;
	std::cout << "1. 1 <= sx <= m;" << std::endl;
	std::cout << "2. 1 <= sy <= n;" << std::endl;
	while (true) {
		std::cout << "请输入m: "; std::cin >> m;
		std::cout << "请输入n: "; std::cin >> n;
		std::cout << "请输入sx: "; std::cin >> sx;
		std::cout << "请输入sy: "; std::cin >> sy;
		if (isStandard(m, n, sx, sy)) {
			std::cout << "输入符合标准!" << std::endl;
			std::cout << "-----------------------" << std::endl;
			break;
		}
		else {
			std::cout << "输入不符合规范, 请重新输入!" << std::endl;
		}
	}

	double start_time = clock();

	// 获取符合标准m和n后，调用horseHamilton()函数，将返回结果保存于二维数组中
	std::vector<std::vector<int>> route = horseHamilton(m, n, sx, sy);
	// 计算m*n的位数用于格式化输出
	int digit = countDigit(m, n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << std::setw(digit + 1) << route[i][j];
		}
		std::cout << std::endl;
	}

	double end_time = clock();
	double time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

	std::cout << "算法执行时间为: " << time << std::endl;
}