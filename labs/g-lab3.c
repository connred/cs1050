#include <stdio.h>
#include <math.h>

int main(void) {
	int run = 0;
	while (run == 0)
	{
		int run2 = 0;
		int option = 0;
		while (run2 == 0){
			printf("Right Triangle Calculation Type\n\n");
			printf("(2) Two triangle legs\n(1)One leg one hypotenuse\nPlease make a selection:\n");
			scanf("%d", &option);
			if (option == 1 || option == 2){
				run2 = 1;
				
			} else {
				printf("Incorrect choice, please make a choice again\n");
			}
		}
		if (option == 2)
		{
			float leg1 = 0;
			float leg2 = 0;
			printf("Enter a length for the first leg:");
			scanf("%f", &leg1);
			while (leg1 <= 0 || leg1 > 100){
				printf("Incorrect value, length should be between 1-100\nEnter a length for the first leg:");
				scanf("%f",&leg1);
			}
			printf("\nEnter a length for the second leg:");
			scanf("%f", &leg2);
			while (leg2 <= 0 || leg2 > 100){
				printf("Incorrect value, length should be between 1-100\nEnter a length for the second leg:");
				scanf("%f",&leg2);
			}
			float s = pow(leg1, 2) + pow(leg2, 2);
			printf("\nCalculation: %.0f + %.0f = c^2\n", pow(leg1,2), pow(leg2,2));
			printf("Hypotenuse length = %.2f\n", sqrt(s));
		}
		if (option == 1)
		{
			float hyp = 0;
			float leg = 0;

			printf("Enter a length for the first leg:");
			scanf("%f", &leg);
			while (leg <= 0 || leg > 100){
				printf("Incorrect value, length should be between 1-100\nEnter a length for the first leg:");
				scanf("%f",&leg);
			}
			printf("Enter a length for the hypotenuse:");
			scanf("%f", &hyp);
			while (hyp <= 0 || hyp > 100){
				printf("Incorrect value, length should be between 1-100\nEnter a length for the hypotenuse:");
				scanf("%f",&hyp);
			}
			while ( hyp <= leg)
			{
				printf("Incorrect Value, hypotenuse length cannot be less than or equal to leg length\nEnter a length for the hypotenuse:");
				scanf("%f",&hyp);
			}
			float s = pow(hyp, 2) - pow(leg,2);
			printf("\nCalculation: %.0f + b^2 = %.0f\n", pow(leg,2), pow(hyp,2));
			printf("Missing leg length = %.2f\n", sqrt(s));
			// print and make answer
		}
		printf("Do you wish to calculate again?\n Press 1 for no, 0 for yes:\n");
		scanf("%d", &run);	
	}
	float number;
	int power;
	float answer = 1;
	printf("********* Bonus Part *********\nEnter a Number:");
	scanf("%f",&number);
	printf("\nEnter an exponent:");
	scanf("%d",&power);
	int i;
	for (i = 0; i<power; ++i)
	{
		answer *= number;
	}
	printf("pow(%f, %d) = %f", number, power, answer);

	
}