#include <iostream>
#include <cstdio>
#include "omp.h"
#include <vector>

using namespace std;

static long num_steps = 100000;
double step;

/***
SEQUENTIAL CODE
===============
int main(){
	int i;
	double x, pi, sum = 0.0;

	//step size
	step = 1.0/num_steps;

	for(i=0;i<num_steps;i++){
		x = (i + 0.5)*step;
		sum = sum + 4.0/(1.0+x*x);
	}
	pi = step*sum;

	cout << pi << endl;
	return 0;
}
***/

//PARALLEL CODE
int main()
{
	double x=0, sum = 0.0, aux, pi;
	int i;
	step = 1.0/(double) num_steps;
	#pragma omp parallel private(i, x)
	{
		#pragma omp for reduction(+:sum) schedule(static)	
		for(i=0;i<num_steps;i++){
			x = (i+0.5)*step;
			sum = sum + 4.0/(1.0+x*x);				
		}
	pi = step*sum;

	}

	cout << pi << endl;
	return 0;
}