/*
Connor Redmond
cdrm9t
*/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
int getString(char *);
int checkString(char *, int);
void cipherString(char *, int, int);
int stringSum(char *, int);

int main(void) {
	char* string = NULL;
	int num = getString(string);
	string = malloc(sizeof(char) * num);
	free(string);

	printf("\nYou entered: %s which is size %d", string, num);
	srand(time(NULL));
	int num2 = (rand()%25);
	cipherString(string, num, num2);
	printf("\nThe ciphered string is %s what is the cipher key? :", string);
	int guess = 0;
	scanf("%d", &guess);
	while(1)
	{

		if (guess >= 1 && guess <= 25)
		{
			if(guess == num2)
			{
				cipherString(string, num, -guess);
				printf("The ciphered string shifted back %d is %s, that's correct!", guess, string);
				break;
			} else {
				cipherString(string, num, -guess);
				printf("The ciphered string shifted back %d is %s, that's incorrect!", guess, string);
				cipherString(string, num, guess);
				printf("\nThe ciphered string is %s what is the cipher key? :", string);
				scanf("%d", &guess);
			}
		}
	}
	printf("\nThe sun of the ascii in %s is %d", string, stringSum(string, num));
}

int getString(char *string)
{
	int size;
	printf("Enter the size of the string:");
	scanf("%d", &size);
	while(size > 20 || size < 1)
	{
		printf("Please enter again:");
		scanf("%d", &size);
	}
	string = malloc(sizeof(char) * size);
	printf("Please enter the string:");
	scanf("%s", string);
	free(string);
	while(1)
	{
		if(checkString(string, size) != 1)
		{
			printf("The string you entered is longer than the allowed size");
			printf("\nPlease Enter a valid string:");
			scanf("%s", string);
			free(string);
		} else {
			break;
		}
		checkString(string, size);

	}
	int i = 0;
	while(string[i])
	{
		string[i] = toupper(string[i]);
		i++;
	}
	int count = 0;
	while(string[count] != '\0')
	{
		count++;
	}
	printf(" %s", string);
	return count;
}
int checkString(char *string, int num)
{
	int i = 0;
	while(string[i])
	{
		if(isalpha(string[i]))
		{
			//do nothinv
		} else {
			printf("\nPlease enter a valid string:");
			scanf("%s", string);
		}
		i++;
	}
	int count = 0;
	while(string[count] != '\0')
	{
		count++;
	}
	if ( num >= count)
	{
		return 1;
	} else {
		return 0;
	}

	return 0;
}
void cipherString(char *string, int size, int key)
{
	int i,ch ;

	for(i = 0; string[i] != '\0'; ++i){
		ch = string[i];
		if (key > 0)
		{
			if(ch >= 65 && ch <= 90)
			{
				ch = ch + key;
				
				if(ch > 90){
					ch =  ch - 90 + 65 - 2;
				}
				if(ch < 65){
					ch = ch + 90 - 65 + 2;
				}
				
				string[i] = ch;
			}

		} else {
			if(ch >= 65 && ch <= 90){
				key *= -1;
				ch = ch - key;
				
				if(ch < 65){
					ch = ch + 90 - 65 + 2;
				}
				if(ch > 90){
					ch =  ch - 90 + 65 - 2;
				}
				
				string[i] = ch;
			}
		}
	}
}
int stringSum(char *string, int size)
{
	int i = 0 , sum = 0;
	while(string[i]!='\0')
	  {
		sum = sum + string[i];
		i++;
	  }
	return sum;
}