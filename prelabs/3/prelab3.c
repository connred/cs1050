#include <stdio.h>
#include <math.h>

int main(void)
{
	int sel = 0;
	int selb = 0;
	int l;
	int r;
	while(selb != 1)
	{
		printf("\nArea calculation\n(1) Sqaure\n(2) Cube\n(3) Circle\nPlease make a selection:");
		scanf("%d", &sel);
		if(sel == 1)
		{
			selb = 1;
		}
		if(sel == 2)
		{
			selb = 1;
		}
		if(sel == 3)
		{
			selb = 1;
		}
		if(selb != 1)
			{
				printf("Incorrect Choice\n");
			}
	}
	while(sel == 1)
	{
		printf("\nEnter a positive number:");
		scanf("%d", &l);
		if(l <= 0)
		{
			printf("Number can't be negative or zero");
		} else {
			int area = l * l;
			printf("\nLength of the side of square is %d\n", l);
			printf("Area of the square is %d", area);
			sel = 0;
		}		
	}
	while(sel == 2)
	{
		printf("\nEnter a positive number:");
		scanf("%d", &l);
		if(l <= 0)
		{
			printf("Number can't be negative or zero");
		} else {
			int areac = l * l * 6;
			printf("\nLength of the side of cube is %d\n", l);
			printf("Area of the cube is %d", areac);
			sel = 0;
		}		
	}
	while(sel == 3)
	{
		printf("\nEnter a positive number:");
		scanf("%d", &r);
		if(r <= 0)
		{
			printf("Number can't be negative or zero");
		} else {
			float arear = r * r * 3.14159;
			printf("\nRadius of circle is %d\n", r);
			printf("Area of the circle is %.2f", arear);
			sel = 0;
		}		
	}

}
