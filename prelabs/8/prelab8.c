/* 
Connor Redmond - CDRM9T - 14307279
Section G
*/
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
	
	printf("Enter a value for the Maclaurin series expansion(x):");
	scanf("%d", &x);
	while(1)
	{
		if(errorCheck(x) != 1)
		{
			printf("\nX must be larger than 0 and less than 10. Please Enter again:");
			scanf("%d",&x);	
		} else {
			break;
		}
	}
	printf("Enter a value for the Maclaurin series to run(n):");
	scanf("%d", &n);
	while(1)
	{
		if(errorCheck(n) != 1)
		{
			printf("\nN must be larger than 0 and less than 10. Please Enter again:");
			scanf("%d",&n);	
		} else {
			break;
		}
	}
	float y[n];
	float *yPtr = y;
	maclaurinSeries(yPtr, n, x);
	
	//factorial(xPtr, limit);
	printArray(yPtr, n);
	
	puts("\n--------BONUS-------\n");
	reverseArray(yPtr, n);
	
}
void maclaurinSeries(float *yPtr, int n,int  x)
{
	float sum = 0;
	int i;
	int count = 0;
	for(i = 0;count <= n; i+=2)
	{
		if (count % 2 == 0)
		{
			sum += (float)pow(x, (i))/factorial(i);
		} else {
			sum -= (float)pow(x, (i))/factorial(i);
		}
		yPtr[count] = sum;
		count += 1;
	}

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
void reverseArray(float *yPtr, int n)
{
	for(int i = n; i >= 0; --i)
	{
		printf("%f ", yPtr[i]);
	}
}