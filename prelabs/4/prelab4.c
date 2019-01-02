/*
Connor Redmond
cdrm9t
14307279
section g
*/

#include <stdio.h>
int courseNumCheck(int);
float getScore(void);
int getUnit(void);
int scoreErrorCheck(float);
int unitErrorCheck(int);
float getScorePoint(float);
void printComment(float);
int computeSCU(float,int);

int main(void) {
	int courseNum;
	printf("===================================\nSTUDENT ASP CALCULATOR\n===================================");
	printf("\nEnter the number of Courses:");
	scanf("%d", &courseNum);
	while (courseNumCheck(courseNum) == 0){
		printf("Error! Please enter a Number of courses greater than 1:");
		scanf("%d", &courseNum);
	}
	float total;
	float totaltop = 0;
	float totalbottom = 0;
	float test;
	float currentScore;
	float currentPoint;
	int currentUnit;
	for(int i = 0; i < courseNum;i++)
	{
		printf("\nEnter the Student Score for Course %d (Percent): ", i+1);
		currentScore = getScore();
		while(scoreErrorCheck(currentScore) == 0){
			printf("Error! Please enter a valid course score:");
			currentScore = getScore();
		}
		currentPoint = getScorePoint(currentScore);
		printf("Enter the Number of Units for Course %d:", i+1);
		currentUnit = getUnit();
		while(unitErrorCheck(currentUnit) == 0){
			printf("Error! Please enter a course unit greater than Zero:");
			currentUnit = getUnit();
		}
		printf("MULTIPLICATION OF SCP AND CU: %d \n", computeSCU(currentPoint, currentUnit));
		//printf("Point = %.2f", currentPoint);
		totalbottom += currentUnit;

		test = currentPoint * currentUnit;
		totaltop += test;

	}
	//printf("%f", totaltop);
	//printf("%f", totalbottom);
	
	total  = totaltop / totalbottom;
	printf("\n\nThe Student ASP: %.2f", total);
	printComment(total);
	
}

int courseNumCheck(int courseNum)
{
	if (courseNum > 1){
		return 1;
	} else {
		return 0;
	}
}

float getScore(void)
{
	float score;
	scanf("%f", &score);
	return score;
}
int getUnit(void)
{
	int unit;
	scanf("%d", &unit);
	return unit;
}
int scoreErrorCheck(float currentScore){
	if (currentScore > 0 && currentScore <= 100){
		return 1;
	} else {
		return 0;
	}
}
int unitErrorCheck(int currentUnit){
	if (currentUnit > 0){
		return 1;
	} else {
		return 0;
	}
}
float getScorePoint(float currentScore)
{
	if (currentScore <= 100 && currentScore >= 90){
		return 4.00;
	}
	if (currentScore <= 89 && currentScore >= 80){
		return 3.00;
	}
	if (currentScore <= 79 && currentScore >= 70){
		return 2.0;
	}
	if (currentScore <= 69 && currentScore >= 60){
		return 1.00;
	}
	if (currentScore < 60){
		return 0.00;
	} else {
		return 0;
	}
}
void printComment(float total)
{
	printf("\n===================================\nCOMMENT:");
	if (total <=4 && total >= 3.8){
		printf("Outstanding!!");
	}
	if (total <=3.79 && total >= 3.5){
		printf("Excellent!!");
	}
	if (total <=3.49 && total >= 3.0){
		printf("Good !!");
	}
	if (total <=2.99 && total >= 2.5){
		printf("Satisfactory !!");
	}
	if (total <=2.49 && total >= 2.0){
		printf("Not Satisfactory !!");
	}
	if (total <=1.99 && total >= 0){
		printf("Do Better Next Semester.");
	}
	printf("\n===================================");
	
}
int computeSCU(float currentPoint, int currentUnit){
	return currentPoint * currentUnit;
}