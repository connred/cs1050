/*
Connor Redmond
14207273
cdrm9t
Homework 2 - Section G
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Global constants
#define ROW 12                                                       
#define COL 6                                                        
#define MAX 25                                                      

int costMatrix[ROW][COL]= 
{
	{500,200,500,500,200,500},{500,200,500,500,200,500},{500,200,500,500,200,500},{500,200,500,500,200,500},{500,200,500,500,200,500},{500,200,500,500,200,500},{500,200,500,500,200,500},{500,200,500,500,200,500},{500,200,500,500,200,500},{500,200,500,500,200,500},{500,200,500,500,200,500},{500,200,500,500,200,500}
};
void displayMenu();
int loginMatch(int passcode,int adminPasscode);
void initialSeats(char flight[][COL],int count);
void printFlightMap(char flight[][COL]);
void flightMenu();
int getTotalRevenue(char flight1[][COL], char flight2[][COL], char flight3[][COL]);
void seatReservation(char flight[][COL]); 
void printMessage(char name[],char num[]);
//void getSafeString(char *string, int maxsize);
int main (void)
{
	srand(time(NULL));
	char flight_1[ROW][COL];
	char flight_2[ROW][COL];
	char flight_3[ROW][COL];
	char name[MAX];
	//char flight_number[MAX];
	char num1[] = "MIA1050";
	char num2[] = "BNA1050";
	char num3[] = "LAS1050";
	int count = (rand()%20+1);
	initialSeats(flight_1, count);
	initialSeats(flight_2, count);
	initialSeats(flight_3, count);
	
	const int adminPasscode = 105018;
	int passcode = 0;
	
	int mChoice;
	printf("******** WELCOME TO MIZZOU AIRLINE BOOKING SYSTEM********\n");
	while(1)
	{	
		while(1)
		{
			displayMenu();
			scanf("%d", &mChoice);
			if(mChoice == 1 || mChoice == 2 || mChoice == 3){
				break;
			} else {
				printf("Wrong option! Choose a right option\n");
			}
		}
		if (mChoice == 1)
		{
			while(1){
				printf("\nEnter the login passcode to log in as admin:");
				scanf("%d", &passcode);
				if (loginMatch(passcode, adminPasscode) == 1)
				{
					break;
				} else {
					printf("Invalid Passcode combination\n");
					continue;
				}
			}
			//print flights 
			printf("\nPrinting the Flight Map of flight Columbia to Miami....\n");
			printFlightMap(flight_1);
			printf("\nPrinting the Flight Map of flight Columbia to Nashville....\n");
			printFlightMap(flight_2);
			printf("\nPrinting the Flight Map of flight Columbia to Las Vegas....\n");
			printFlightMap(flight_3);
			
			//print total rev			
			printf("\nThe total earning from all the flights: $%d", getTotalRevenue(flight_1, flight_2, flight_3));

			printf("\nYou are logged out now!\n");
		}
		if (mChoice == 2)
		{
			int fChoice;
			while(1)
			{
				flightMenu();
				scanf("%d", &fChoice);
				if(fChoice == 1 || fChoice == 2 || fChoice == 3){	
					break;
				} else {
					continue;
				}
			}
			printf("Enter your first name:");
			scanf("%s", name);
			if (fChoice == 1)
			{
				seatReservation(flight_1);
				printMessage(name, num1);
			}
			if(fChoice == 2)
			{
				seatReservation(flight_2);
				printMessage(name, num2);
			}
			if(fChoice == 3)
			{
				seatReservation(flight_3);
				printMessage(name, num3);				
			}	
		}
		if(mChoice == 3)
		{
			printf("\nTerminating the Program\nThank you for using Mizzou Airline Booking System.\n");
			break;
		}

	}

}
void initialSeats(char flight[][COL], int count)
{
	for(int a = 0; a < count; ++a){
		int row = rand() % ROW;
		int col = rand() % COL;
		if (flight[row][col] != 'X'){
			flight[row][col] = 'X';
		} else {
			a -= 1;
		}
			
	};
	for(int i = 0; i < ROW; ++i)
	{
		for(int j = 0; j < COL; ++j)
		{
			if (flight[i][j] != 'X')
			{
				flight[i][j] = 'O';
			}
		}
	}
}
void displayMenu()
{
	printf("\n1.)Admin Log-In\n2.)Reserve a seat\n3.)Exit\nChoose an option:");
}
void printFlightMap(char flight[][COL])
{
	for(int i = 0; i < ROW; i++)
	{
		for(int a = 0; a < COL; a++)
		{
			printf("%3c", flight[i][a]);	
		}
		printf("\n");
	}

}
int loginMatch(int passcode, int adminPasscode)
{
	if(passcode == adminPasscode)
	{
		return 1;
	} else {
		return 0;
	}
}
int getTotalRevenue(char f1[][COL],char f2[][COL],char f3[][COL])
{
	int total = 0;
	int i,j;
	for(i = 0; i < ROW; ++i)
	{
		for(j = 0; j < COL; ++j)
		{
			if(f1[i][j] == 'X')
			{
				total += costMatrix[i][j];
			}
			if(f2[i][j] == 'X')
			{
				total += costMatrix[i][j];				
			}
			if(f3[i][j] == 'X')
			{
				total += costMatrix[i][j];				
			}
		}
	}
	return total;
}
void flightMenu()
{
	printf("\n1.)COU ---> MIA\n2.)COU ---> BNA\n3.)COU ---> LAS\nChoose an option:");
}

void seatReservation(char flight[][COL])
{
	int tR;
	int tC;
	printFlightMap(flight);
	while(1)
	{
		printf("\nWhich seat row do you want?:");
		scanf("%d", &tR);
		while(tR > 11 || tR < 0)
		{
			printf("\nSeat rows are between 0-11\nTry again. Which seat row do you want?:");
			scanf("%d",&tR);
		}
		printf("\nWhich seat column do you want?:");
		scanf("%d", &tC);
		while(tC > 5 || tC < 0)
		{
			printf("\nSeat columns are between 0-5\nTry again. Which seat column do you want?:");
			scanf("%d",&tC);
		}
		if(flight[tR][tC] != 'X')
		{
			flight[tR][tC] = 'X';
			printf("\nYour requested seat has been reserved.\n");
			printFlightMap(flight);
			break;
		} else {
			printf("Sorry!! Someone has reserved that seat. Try Again.");
			continue;
		}
	}

	
}

void printMessage(char name[], char num[])
{
	printf("\nCongrats %s!!, your flight %s is booked, enjoy your trip.\n\nEnjoy your break\n", name, num);
	

}


