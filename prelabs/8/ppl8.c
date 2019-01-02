#include <stdio.h>
#include <math.h>
int errorCheck(int);
int factorial(int);
void printArray(float *, int);
void maclaurinSeries(float *, int, int);
void reverseArray(float *, int);
int main(void) {
	int x;
	int n;
	
	printf("(x):");
	scanf("%d", &x);
	while(1)
	{
	  //ask for x and error check it	
	}
	printf("(n):");
	scanf("%d", &n);
	while(1)
	{
			//ask for n and error check it
	}
	float y[n]; // init array
	float *yPtr = y; // set pointer
	//maclaurinSeries(yPtr, n, x);
	//printArray(yPtr, n);
	
}

int errorCheck(int num)
{
	if(num > 0 && num < 10)
	{
		return 1;
	} else {
		return 0;
	}

}
int factorial(int limit)
{
	int i;
	int fac = 1;
	for(i = 1; i <= limit; ++i)
	{
		fac *= i;
	}
	return fac;
}
void printArray(float *yPtr, int n)
{
	for(int i = 0; i <= n; ++i)
	{
		printf("%f ", yPtr[i]);
	}
}
void maclaurinSeries(float *yPtr, int n,int  x)
{

}
void reverseArray(float *yPtr, int n)
{

}