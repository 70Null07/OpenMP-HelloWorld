#include <iostream>
#include <locale>
#include <omp.h>

using namespace std;

int main()
{
	int inp_threads;
	setlocale(LC_ALL, "RUS");
	cout << "Максимально допустимое число потоков - " << omp_get_max_threads() << "\nВведите требуемое число потоков: " << endl;
	cin >> inp_threads;
	omp_set_num_threads(inp_threads);
#pragma omp parallel
	{
		cout << "(cout) Hello World! От потока " << omp_get_thread_num() << endl;
		printf("(printf) Hello World!От потока %d \n", omp_get_thread_num());
	}
	return 0;
}