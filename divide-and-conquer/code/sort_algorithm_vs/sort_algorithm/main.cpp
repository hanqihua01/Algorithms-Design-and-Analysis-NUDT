#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <string>
#include <cstring>
#include "algorithm.h"
#include "out.h"

using namespace std;

#define UP_BOUND 123456

int main()
{
    double sum_time = 0;
    double sum_cop = 0;
    double sum_mov = 0;
    int vector_size = 1500;
    int num_repeat = 100;
    for (int i = 0; i < num_repeat; i++)
    {
        vector<int> vec(vector_size);
        for (int j = 0; j < vector_size; j++)
            vec[j] = rand() % UP_BOUND;
        clock_t start_time, end_time;
        start_time = clock();
        ShellSort(vec, sum_cop, sum_mov);
        end_time = clock();
        sum_time += (double)(end_time - start_time) / CLOCKS_PER_SEC;
    }
    cout << "The average time is " << sum_time / num_repeat << " s." << endl;
    cout << "The average times of comparing is " << sum_cop / num_repeat << endl;
    cout << "The average times of moving is " << sum_mov / num_repeat << endl;
    return 0;
}