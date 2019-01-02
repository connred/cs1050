/*
Connor Redmond
CDRM9T
G-HW3
*/


#include <stdio.h>
#include <stdlib.h>

int get_record_count(char *);
int load_data(char *filename,int *account,float *balance, int size);
void print_data(int *,float *, int);
int highest_amount(float *, int);
int lowest_amount(float *, int);
float average_amount(float *, int);
int write_data(char *, int *,float *, int, int, int , float);

int main(int argc, char *argv[]) {
	if (argc != 3)
	{
		printf("Incorrect number of arguments");
		exit(1);
	}
	
	char *filename = argv[1];
	int size = get_record_count(filename);
	
	printf("%d record in the file.\n", size);
	
	int *account;
	account = malloc(sizeof(int) * (size));
	float *balance;
	balance = malloc(sizeof(float) * (size));
	
	load_data(filename, account, balance, size);
	if (load_data(filename, account, balance, size) == 1)
	{
		print_data(account, balance, size);
	} else {
		printf("\nUnable to open input file");
	}
	
	printf("\n\nThe highest amount of $%.2f in the account number %d", balance[highest_amount(balance, size)], account[highest_amount(balance, size)]);
	printf("\nThe lowest amount of $%.2f in the account number %d", balance[lowest_amount(balance, size)], account[lowest_amount(balance, size)]);
	float avg = average_amount(balance, size);
	printf("\nThe average amount of %.2f \n", avg);
	
	char *output = argv[2];
	if(write_data(output, account, balance, size, highest_amount(balance, size), lowest_amount(balance, size), average_amount(balance, size)) != 1){
		printf("\nUnable to open output file");
	}
	free(account);
	free(balance);
}
int get_record_count(char *filename)
{
	FILE* fp;
	fp =fopen(filename, "r");
	int count = 0;
	char buffer[BUFSIZ];
	while(fgets(buffer, sizeof buffer, fp))
	{
		count++;
	}
	return count;
}
int load_data(char *filename, int *account, float *balance, int size)
{
	FILE* fp = fopen(filename, "r");
	if (!fp)
	{
		return 0;
	}
	for(int i = 0; i < size; ++i)
	{
		fscanf(fp, "%d %f", &account[i], &balance[i]);
	}
	fclose(fp);
	return 1;
}
void print_data(int *account, float *balance, int size)
{
	printf("\nAccount No.\t Amount");
	for(int i = 0; i <size; ++i)
	{
		printf("\n%d\t\t%.2f", account[i],balance[i]);
	}
}
int highest_amount(float *balance, int size)
{
	float max = 0;
	int indx = 0;
	for(int i = 0; i < size; ++i)
	{
		if (balance[i] > max)
		{
			max = balance[i];
			indx = i;
		}
	}
	return indx;
}
int lowest_amount(float *balance, int size)
{
	float min = 1000000;
	int indx = 0;
	for(int i = 0; i < size; ++i)
	{
		if (balance[i] < min)
		{
			min = balance[i];
			indx = i;
		}
	}
	return indx;

}
float average_amount(float *balance, int size)
{
	float avg;
	for(int i = 0; i < size; ++i)
	{
		avg += balance[i];
	}
	avg = avg / size;
	return avg;
}
int write_data(char *output, int *account, float *balance, int size, int high, int low, float average)
{
	FILE* op = fopen(output, "w");
	if(!op){
		return 0;
	}
	fprintf(op, "%d records in the file.\n", size);
	fprintf(op, "Account No. \t Amount\n");
	for(int i = 0; i < size; ++i)
	{
		fprintf(op, "\n%d\t\t%.2f", account[i], balance[i]);
	}
	fprintf(op, "\nThe highest amount of $%.2f in the account number %d", balance[high], account[high]);
	fprintf(op, "\nThe highest amount of $%.2f in the account number %d", balance[low], account[low]);
	fprintf(op, "\nThe average amount of $%.2f", average);
	return 1;
}