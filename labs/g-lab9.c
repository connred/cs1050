/*
Connor Redmond 
cdrm9t
14307279
*/


#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 50

void get_size(int*);
int check_size(int);
void initialize_pointerArray(int *,int);
void print_pointerArray(int *, int);
int find_max(int *, int);
int find_min(int *, int);
void bubble_sort(int *, int);
float find_median(int *, int);


int main(void) {
	int size;
	int *yPtr = &size;
	
	
	printf("Enter the size of the input:");

	get_size(yPtr);
	while(1)
		{
			if(check_size(size) != 1)
			{
				printf("\nInvalid input enter the size of the array again:");
				get_size(yPtr);
				
			} else {
				break;
			}
		}

	int array[MAX];
	int *xPtr = array;
	initialize_pointerArray(xPtr, size);
	puts("\nThe pointer is:");
	print_pointerArray(xPtr, size);
	
	printf("\n\nThe smallest value in the array is: %d", find_min(xPtr, size));

	printf("\nThe largest value in the array is: %d", find_max(xPtr, size));
	bubble_sort(xPtr, size);
	puts("\n\nThe sorted pointer is:");
	print_pointerArray(xPtr, size);
	printf("\n\nThe median of the pointer = %.2f", find_median(xPtr, size));
	
	
}
void get_size(int *yPtr)
{
	scanf("%d", yPtr);
}
int check_size(int size)
{
	if(size > 0 && size < 50)
	{
		return 1;
	} else {
		return 0;
	}

}
void initialize_pointerArray(int *xPtr, int size)
{
	int i;
	srand(time(NULL));
	for(i = 0; i < size; i++)
	{
		xPtr[i] = (rand()%10+1);
	}
}
void print_pointerArray(int *xPtr, int size)
{
	int i;
	for(i = 0; i < size; i++)
	{
		printf("%d ", xPtr[i]);	
	}
}
int find_max(int *xPtr, int size)
{
	int i;
	int max = 0;
	for(i=0; i<size;i++)
	{
		if (xPtr[i] > max){
			max = xPtr[i];
		}
	}
	return max;
}
int find_min(int *xPtr, int size)
{
	int i;
	int min = 11;
	for(i=0; i<size;i++)
	{
		if (xPtr[i] < min){
			min = xPtr[i];
		}
	}
	return min;
}
void bubble_sort(int *xPtr, int size)
{
	int c,d,t;
	for(c = 0; c < size -1; c++)
	{
		for(d = 0; d< size -c -1; d++)
		{
			if (xPtr[d] > xPtr[d+1])
			{
				t = xPtr[d];
				xPtr[d] = xPtr[d+1];
				xPtr[d+1] = t;
			}
		}
	}
}
float find_median(int *xPtr, int size)
{
	if (size %2 == 0)
	{
		return ((xPtr[size/2] + xPtr[size/2-1]) / 2.0);
	} else {
		return xPtr[size/2];
	}
}