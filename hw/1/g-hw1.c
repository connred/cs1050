/* 
Connor Redmond
cdrm9t
14307279
*/
#include <stdio.h>
#include <math.h>

void displayMenu();
int errorCheck(int);
int errorCheckUnits(int);
int charge(int);
float getRate(int, int);

int main(void) {
		displayMenu();
}

void displayMenu()
{
	float total;
	int numBills;
	int run = 1;
	while (run ==1)
	{
		printf("***** ELECTRICITY BILL CALULATOR *****\n\n");
		printf("1. Residential\n");
		printf("2. Commercial\n");
		printf("3. Industrial\n");
		printf("\nChoose the type of connection: ");
		int type;
		scanf("%d", &type);
		type = errorCheck(type);
		int units;
		printf("\nEnter the number of units (in kWh):");
		scanf("%d", &units);
		units = errorCheckUnits(units);
		int charge1 = charge(type);
		float rate = getRate(units, type);
		
		printf("Total energy charge for the customer is: $%.2f\n", rate);
		printf("Connection Charge for this customer is $ %d\n", charge1);
		printf("Total bill due from this connection is $%.2f\n", rate + charge1);
		numBills += 1;
		total += rate + charge1;
		printf("\nDo you want to continue and calculate another bill? If yes enter 1, else 0\n");
		scanf("%d", &run);
		

	}
	printf("You calculated the bill %d times and the total amount of the bills due is $%.2f", numBills,total);
	
	// BONUS CODE
	printf("\n\n***BONUS SECTION***\nEnter a number:");
	int bonus;
	scanf("%d",&bonus);
	int i;
	int producta = 1;
	int producte = 1;
	int producto = 1;
	printf("\nThe numbers are: ");
	for(i=0;i<bonus;i++)
	{
		printf("%d ", i + 1);
		producta *= (i+1);
		/*if ((i+1) % 2 == 0){
			producte *= (i+1);
		} else {
			producto *= (i=1);
		}*/
	}
	for(i=0; i<bonus;i++)
	{
		if((i+1) % 2 == 0)
		{
			producte *= (i+1);
		}
	}
	for(i=0; i<bonus;i++)
		{
			if((i+1) % 2 != 0)
			{
				producto *= (i+1);
			}
		}
	printf("\nThe product of all numbers from 1 to %d is %d", bonus,producta);
	printf("\nThe product of all even numbers is %d",producte);
	printf("\nThe product of all odd numbers is %d",producto);
	// END BONUS
}

int errorCheck(int type)
{
	// must be 1 2 or 3
	if (type == 1 || type == 2 || type == 3)
	{
		return type;
	} else {
		int run = 0;
		while (run == 0)
		{
			printf("Invalid Choice! Please enter a valid choice:\n");
			scanf("%d", &type);
			if (type == 1 || type == 2 || type == 3)
			{
				return type;
				run = 1;
			} else {
				continue;
			}
		}
	}
	return 0;
}

int errorCheckUnits(int units)
{
	if (units > 0)
	{
		return units;
	} else {
		int run = 0;
		while (run == 0)
		{
			printf("Invalid input!");
			printf("\nEnter the number of units (in kWh):");

			scanf("%d", &units);
			if (units > 0)
			{
				return units;
				run = 1;
			} else {
				continue;
			}
		}
	}
	return 0;

}
int charge(int type){
    if (type == 1){
		type = 25;
		return type;
	}
	if (type == 2)
	{
		type = 90;
		return type;
	}
	if (type == 3)
	{
		type = 850;
		return type;
	} else {
		return 0;
	}	
	
}	
float getRate(int units, int type)
{
	if (type == 1)
	{
		//if (between blah blah then return the correct rate
		if (units > 0 && units <= 200)
		{
			return units*.075;
		}
		if (units > 200 && units <=700)
		{
			return units*.10;
		}
		if (units > 700 && units <= 1250)
		{
			return units*.135;
		}
		if (units > 1250)
		{
			return units*.15;
		} else {
			return 0;
		}
	}
	if (type == 2)
	{
		if (units > 0 && units <= 300)
		{
			return units*.105;
		}
		if (units > 300 && units <=1000)
		{
			return units*.14;
		}
		if (units > 1000 && units <= 2000)
		{
			return units*.175;
		}
		if (units > 2000)
		{
			return units*.20;
		} else {
			return 0;
		}
	}
	if (type == 3)
	{
		if (units > 0 && units <= 500)
		{
			return units*.365;
		}
		if (units > 500 && units <=2000)
		{
			return units*.4;
		}
		if (units > 2000 && units <= 3000)
		{
			return units*.455;
		}
		if (units > 3000)
		{
			return units*.5;
			
		} else {
			return 0;	
		}


	}
	return 0;
}
