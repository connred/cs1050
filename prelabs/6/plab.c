#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20

int check_error(int arrs);
void initialize_2darray(int array[][MAX], int arrs);
void print_2darray(int array[][MAX], int arrs);
int findZeros(int array[][MAX], int arrs);
int findEvenOdd(int [][MAX], int);

int main(void) {
	int array[][MAX] = {};
	int arrs;
	printf("Enter size of the 2-D array:");
	scanf("%d", &arrs);
	while(check_error(arrs) ==0)
	{
		printf("Enter a value between 1-20 only:");
		scanf("%d", &arrs);
	}
	initialize_2darray(array, arrs);
	print_2darray(array, arrs);
	int a = findZeros(array,arrs);
	int b = findEvenOdd(array, arrs);
	int c = (arrs * arrs) - b;
	printf("\nThe number of zeros in 2-D Array: %d", a);
	printf("\nThe number of even numbers: %d", b);
	printf("\nThe number of odd numbers: %d", c);
}
int check_error(int arrs)
{
	if(arrs >= 1 && arrs <= 20){
		return 1;
	}
	if (arrs < 1 || arrs >20)
	{
		return 0;
	}
}
void initialize_2darray(int array[][MAX], int arrs)
{
	int i;
	int j;
	srand(time(NULL));
	for(i = 0; i < arrs; i++)
	{
		for(j = 0; j < arrs; j++)
		{
			array[i][j] = (rand()%10);
		}
	}
}
void print_2darray(int array[][MAX], int arrs)
{
	int i;
	int j;
	printf("\nTHE 2-D ARRAY is:\n");
	for(i = 0; i < arrs; i++)
	{
		for(j = 0; j < arrs; j++)
		{
			printf("%3d", array[i][j]);
		}
		printf("\n");
	}
}
int findZeros(int array[][MAX], int arrs)
{
	int i;
	int j;
	int number =0;
	for(i = 0; i < arrs; i++)
	{
		for(j = 0; j < arrs; j++)
		{
			if (array[i][j] == 0)
			{
				number+=1;
			}
		}
	}
	return number;

}
int findEvenOdd(int array[][MAX], int arrs)
{
	int i;
	int j;
	int number =0;
	for(i = 0; i < arrs; i++)
	{
		for(j = 0; j < arrs; j++)
		{
			if (array[i][j] % 2 == 0)
			{
				number+=1;
			}
		}
	}
	return number;

}

