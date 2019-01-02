/*
Connor Redmond
cdrm9t
14307279
*/


#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define MAX 20

int check_error(int size);
void initialize_2darray(int array[][MAX], int size);
void print_2darray(int array[][MAX], int size);
int findZeros(int array[][MAX], int size);
int findEvenOdd(int [][MAX], int);
void printTranspose(int [][MAX], int);
void flattenArray(int [][MAX], int);
void to1Dsort(int [][MAX], int);

int main(void) {
	int size;
	int array[MAX][MAX] = {};
	printf("Enter size of the 2-D array:");
	scanf("%d", &size);
	while(check_error(size) !=1)
	{
		printf("Please enter a value between 1-20 only:");
		scanf("%d", &size);
	}
	initialize_2darray(array, size);
	print_2darray(array, size);
	printf("\nThe number of zeros in 2-D Array: %d", findZeros(array,size));
	printf("\nThe number of even numbers: %d", findEvenOdd(array, size));
	printf("\nThe number of odd numbers: %d", ((size * size) - findEvenOdd(array, size)));
	//printf("test");
	printTranspose(array, size);
	flattenArray(array, size);
	//bonus
	to1Dsort(array, size);
}
int check_error(int size)
{
	if(size >= 1 && size <= 20){
		return 1;
	} else {
		return 0;
	}
}
void initialize_2darray(int array[][MAX], int size)
{
	int i,a;
	srand(time(NULL));
	for(i = 0; i < size; i++)
	{
		for(a = 0; a < size; a++)
		{
			//printf("%d%d", i,a);
			array[i][a] = (rand()%10);
		}
	}
}
void print_2darray(int array[][MAX], int size)
{
	int i,a;
	printf("\nTHE FIRST 2-D ARRAY is:\n");
	for(i = 0; i < size; i++)
	{
		//printf("test3");
		for(a = 0; a < size; a++)
		{
			printf("%3d", array[i][a]);
		}
		printf("\n");
	}
}
int findZeros(int array[][MAX], int size)
{
	int i,a;
	int z =0;
	// loop thru
	for(i = 0; i < size; i++)
	{
		for(a = 0; a < size; a++)
		{
			// if zero add to z
			if (array[i][a] == 0)
			{
				z+=1;
			}
		}
	}
	return z;

}
int findEvenOdd(int array[][MAX], int size)
{
	int i,a;
	int z =0;
	//loop through
	for(i = 0; i < size; i++)
	{
		for(a = 0; a < size; a++)
		{
			// if even add to z
			if (array[i][a] % 2 == 0)
			{
				z+=1;
			}
		}
	}
	return z;

}
void printTranspose(int array[][MAX],int size)
{
	int i,a;
	int transpose[size][size];
	printf("\nThe transpose of the 2-D Array is\n");
	//creating tranposed array
	for(i = 0; i < size; i++)
	{
		for(a = 0; a < size; a++)
		{
			transpose[a][i] = array[i][a];
		}
	}
	//print transpose
	for(i = 0; i < size; i++)
	{
		for(a = 0; a < size; a++)
		{
			printf("%3d", transpose[i][a]);	
		}
		printf("\n");
	}
}
void flattenArray(int array[][MAX], int size)
{
	int i,a;
	int x = 0;
	int num = size * size;
	int flat[num];
	// put into 1D
	for(i = 0; i < size; i++)
	{
		for(a = 0; a < size; a++)
		{
			flat[x] = array[i][a];
			x += 1;
		}
	}
	printf("The flattened array is\n");
	//PRINT
	for(x = 0; x < num; x++)
	{
		printf("%3d", flat[x]);	
	}
}
//bonus
void to1Dsort(int array[][MAX], int size)
{
	int i,a;
	int x = 0;
	int num = size * size;
	int flat[num];
	int z;
	// put into 1D
	for(i = 0; i < size; i++)
	{
		for(a = 0; a < size; a++)
		{
			flat[x] = array[i][a];
			x += 1;
		}
	}
	//sort
	for(i = 0; i < num; i++)
	{
		for(a = i+1; a < num; a++)
		{
			if (flat[i] > flat[a])
			{
				z = flat[i];
				flat[i] = flat[a];
				flat[a] = z;
			}
		}
	}
	// print
	printf("\n\n**************BONUS**************\nThe sorted array is\n");
	for(i = 0; i < num; i++)
	{
		printf("%3d", flat[i]);
	}
}

