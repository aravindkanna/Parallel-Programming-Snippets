#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "omp.h"

using namespace std;

int main()
{
	//omp_set_num_threads(20);
	#pragma omp parallel num_threads(20)
	{
		int id = omp_get_thread_num();
		printf("hello(%d)", id);
		printf("world(%d)\n", id);
	}
	return 0;
}