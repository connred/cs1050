#include <stdio.h>
#include <math.h>
int main(void)
{
  int n1 = 0;
  int n2 = 0;

  printf("Enter the first number:");
  scanf("%d", &n1);
  while (n1 < 0)
  {
    printf("Enter a non-negative number:");
    scanf("%d", &n1);
  }

  printf("Enter the second number:" );
  scanf("%d", &n2);
  while (n2 < 0)
  {
    printf("Enter a non-negative number:");
    scanf("%d", &n2);
  }
  int a = n1 + n2;
  int m = n1 * n2;

  printf("\nADDITION\n" );
  printf("The sum of %d and %d is %d\n",n1,n2,a);

  printf("\nMULTIPLICATION\n" );
  printf("The product of %d and %d is %d",n1,n2,m);
  
  printf("\nDIVISION\n");
  while(n1 == 0){
      printf("\nCannot divide by zero!\n");
      printf("Enter a new number:");
      scanf("%d", &n1);
  }
  while(n2 == 0){
      printf("Cannot divide by zero!\n");
      printf("Enter a new number:\n ");
      scanf("%d", &n2);
  }
  float d1 = n1;
  float d2 = n2;
  float d = d1 / d2;
  
  printf("\n%d divided by %d is %.2f\n",n1,n2,d);
  if (n1 > n2){
      printf("\n%d is the bigger number", n1);
  }
  if (n2 > n1){
      printf("\n%d is the bigger number", n2);
  }
  
  printf("\nSQUARE ROOT\n");
  float s = 1;
  printf("Enter a number for the square root operation:");
  scanf("%f",&s);
  while(s <= 0){
      printf("\nCannot take the square root of a negative number.\n");
      printf("Try again:");
      scanf("%f", &s);
      
  }
  printf("The sqaure root of %.0f is %.2f",s,sqrt(s));

}
/*
 int (integer values) uses %d
 float (floating point values) uses %f
 char (single character values) uses %c
 character strings (arrays of characters, discussed later) use %s
 */
