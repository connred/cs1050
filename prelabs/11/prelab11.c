#include <stdio.h>
#include <stdlib.h>
#define MAX 22

void get_size(int *);
int check_size(int);
void load_sructdata(char *filename, int size);
void print_data(int size);

struct student
{
	char name[20];
	int id;
	int grade;
};


struct student Info[MAX];



int main(int argc, char *argv[]) {
	if ( argc != 2){
		printf("Insufficient arguments! load the correct number of input arguments");
		exit(1);
	}
	int size;
	get_size(&size);
	char *filename = argv[1];
	load_sructdata(filename, size);
	print_data(size);
}
void get_size(int *s)
{
	printf("Enter the size of the input: ");
	scanf("%d", s);
	while (check_size(*s) != 1) {
		printf("===============================================");
		printf("\nInvalid size entered! Minimum is 1 and Maximum is 22!");
		printf("===============================================");
		printf("\nPlease enter again:");
		scanf("%d", s);
		printf("===============================================");
	}
}
int check_size(int s)
{
	if (s >= 1 && s <= 22){
		return 1;
	} else {
		return 0;
	}
}
void load_sructdata(char *filename, int size)
{
	FILE *f;
	f = fopen(filename, "r");
	for(int i = 0; i<size; i++)
	{
		fscanf(f, "%s %d %d", Info[i].name, &Info[i].id, &Info[i].grade);
	}
}
void print_data(int size)
{
	printf("s/no\tName\tId\tGrade");
	for(int i = 0; i < size; i++)
	{
		printf("\n%d\t%s\t%d\t%d", i + 1,Info[i].name,Info[i].id,Info[i].grade);
	}
}