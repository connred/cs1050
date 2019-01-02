#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20

int check_error(int num);
void initialize_2Darray(int array[][MAX], int num);
void print_2Darray(int array[][MAX], int num);
int findZeros(int array[][MAX], int num);
int findEvenOdd(int [][MAX], int);
void printTranspose(int[][MAX], int);
void flattenArray(int[][MAX], int);


int main(void) 
{
int array[MAX][MAX] = {};
int num;
printf("Enter size of the 2D array: ");
scanf("%d", &num);

while(check_error(num) !=1)
{
printf("Please enter a number between 1 and 20: ");
scanf("%d", &num);
}

initialize_2Darray(array, num);
print_2Darray(array, num);
printTranspose(array, num);
flattenArray(array, num);

int x = findZeros(array, num);
int y = findEvenOdd(array, num);


printf("Zeros in your 2D rray: %d\n", x);
printf("Even numbers in your 2D array: %d\n", y);
printf("Odd numbers in your 2D array: %d", ((num * num) - findEvenOdd(array, num)));


}

int check_error(int num)
{

if(num <1 || num >20)
{
return 0;
}

return 1;
}

void initialize_2Darray(int array[][MAX], int num)
{
int a;
int b;

srand(time(NULL));

for(a = 0; a < num; a++)
{
for(b = 0; b < num; b++)
{
array[a][b] = (rand()%10);
}
}
}

void print_2Darray(int array[][MAX], int num)
{
int a;
int b;
printf("\nYour 2D array is:\n");
for(a = 0; a < num; a++)
{
for(b = 0; b < num; b++)
{
printf("%3d", array[a][b]);
}
printf("\n");
}
}

int findZeros(int array[][MAX], int num)
{
int a;
int b;
int c =0;
for(a = 0; a < num; a++)
{
for(b = 0; b < num; b++)
{
if (array[a][b] == 0)
{
c+=1;
}
}
}
return c;

}

int findEvenOdd(int array[][MAX], int num)
{
int a;
int b;
int c =0;

for(a = 0; a < num; a++)
{
for(b = 0; b < num; b++)
{
if (array[a][b] % 2 == 0)
{
c+=1;
}
}
}
return c;

}


void printTranspose(int array[][MAX],int num)
{
int a, b;
int c[num][num];

printf("Transposed 2D array: \n");

for(a = 0; a < num; a++)
{

for(b = 0; b < num; b++)
{
c[b][a] = array[a][b];

}

}

for(a = 0; a < num; a++)
{
for(b = 0; b < num; b++)
{
printf("%d", c[a][b]);
}

printf("\n");
}


}


void flattenArray(int array[][MAX], int num)
{
int e,f,g;
int total = 0;
int h = num * num;
int x[h];

for(e = 0; e < num; e++)
{
for(f = 0; f < num; f++)
{
x[total] = array[e][f];
total += 1;
}
}

printf("Flattened 2D array: \n");

for(h = 0; h < num*num; h++)
{
printf("%3d", x[h]);
}
}