/*
Connor Redmond
Cdrm9t
14307279
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int check_error(int);
void initialize_array(int[],int);
void print_array(int[],int);
float average(int[],int);
float std_dev(int[],int);
int max(int[],int);

int main(void) {
	int array1[50]={0};
	int size;
	printf("Enter the size of the input:");
	scanf("%d",&size);
	while(check_error(size) != 1)
	{
		printf("Invalid input enter the size of the input again:");
		scanf("%d",&size);
	}
	initialize_array(array1, size);
	print_array(array1, size);
	printf("\nThe average of the array is %.2f", average(array1, size));
	printf("\nThe standard deviation of the array is %.2f", std_dev(array1,size));
	//printf("\n\n****BONUS****\nThe index of the biggest element is %d", max(array1, size));
	return 0;
}

int check_error(int size)
{
	if ( size >= 1 && size <= 50){
		return 1;
	} else {
		return 0;
	}
}
void initialize_array(int array1[], int size)
{
	srand(time(NULL));
	int i;
	for(i = 0; i<size;i++)
	{
		array1[i] = (rand()%9) + 1;
	}
	
	
}

void print_array(int array1[], int size)
{
	int i;
	for(i = 0; i<size;i++){printf("%d ", array1[i]);}
}
float average(int array1[],int size)
{
	float average;
	int i;
	for(i = 0; i<size;i++)
	{
		average += (i +1);
	}
	return (average/size);
}
float std_dev(int array1[],int size)
{
	float std;
	int i;
	float sum;
	for(i = 0; i<size;i++)
	{
		sum += array1[i];
	}
	float num = (average(array1, size) / 10);
	for(i = 0; i<size;i++)
	{
		std += pow(array1[i] - num, 2);
	}
	return sqrt(std/10);
}
int max(int array1[],int size)
{
	int i;
	int max = 0;
	for(i=0; i<size;i++)
	{
		if (array1[i] > max){
			max = array1[i];
		}
	}
	for(i=0;i<size;i++){
		if(array1[i] == max){
			return i;
		}
	}
	return 0;
}