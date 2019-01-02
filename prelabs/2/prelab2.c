#include <stdio.h>
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
    while(n1 || n2 == 0){
        printf("Cannot divide by zero!");
        printf("Enter a new number:");
        if (n1 == 0){
            scanf("%d", &n1);
        }
        if(n2 == 0){
            scanf("%d",&n2);
        }
    }
    float d = n1 / n2;
    printf("%d divided by %d is %.2f",n1,n2,d);
    
}
/*
 int (integer values) uses %d
 float (floating point values) uses %f
 char (single character values) uses %c
 character strings (arrays of characters, discussed later) use %s
 */
