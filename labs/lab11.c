

#include <stdio.h>
#include <stdlib.h>
#define MAX 22

void get_size(int *);
int check_size(int);
void get_group(int *);
int check_group(int);
void load_data(char *, int );
void classify(char *, int);
void frequency(char *, int, int);


struct addrs
{
	char county[20];
	int zip;
	char city[20];
};



struct addrs Info[MAX];


int main(int argc, char *argv[]) {
	if ( argc == 2){

	}  else {
		printf("Insufficient arguments! load the correct number of input arguments");
		exit(1);
	}
	int size;
	get_size(&size);
	char *filename = argv[1];
	load_data(filename, size);
	classify(filename, size);
	int group;
	get_group(&group);
	frequency(filename, size, group);
	if (argc == 3)
	{
		char *bonusfile = argv[2];
		load_sructdata(bonusfile, size);
		print_data(size);
	}
}
void get_size(int *s)
{
	printf("Enter the size of the input: ");
	scanf("%d", s);
	while (check_size(*s) != 1) {
		printf("===============================================");
		printf("\nInvalid size entered! Minimum is 4 and Maximum is 40!");
		printf("\n===============================================");
		printf("\nPlease enter again:");
		scanf("%d", s);
	}
}
int check_size(int s)
{
	if (s >= 4 && s <= 40){
		return 1;
	} else {
		return 0;
	}
}
void load_data(char *filename, int size)
{
	
	FILE *f;
	f = fopen(filename, "r");
	printf("===============================================");
	printf("\ns/no\tCounty\tZipCode\tCity");
	for(int i = 0; i<size; i++)
	{
		fscanf(f, "%s %d %s", Info[i].county, &Info[i].zip, Info[i].city);
		printf("\n%d\t%s\t%d\t%s", i + 1,Info[i].county,Info[i].zip,Info[i].city);
	}
	printf("\n===============================================");

}
void get_group(int *g)
{
	printf("\nEnter the group number: ");
	scanf("%d", g);
	while (check_group(*g) != 1) {
		printf("===============================================");
		printf("\nInvalid group entered! Must be 1, 2, or 3");
		printf("===============================================");
		printf("\nPlease enter again:");
		scanf("%d", g);
	}

}
int check_group(int num)
{
	if (num >= 1 && num <= 3)
	{
		return 1;
	} else {
		return 0;
	}	
}
void classify(char *fp, int size)
{
	printf("===============================================");
	printf("\ns/no\tCounty\tZipCode\tCity\tGroup");
	int g1 = 0;
	int g2 = 0;
	int g3 = 0;
	for(int i = 0; i<size; i++)
	{
		int group = 0;
		//fscanf(f, "%s %d %s", Info[i].county, &Info[i].zip, Info[i].city);
		if (Info[i].zip >= 63000 && Info[i].zip <= 63999)
		{
			group = 1;
			g1 += 1;
		} else if(Info[i].zip >= 64000 && Info[i].zip <= 64999){
			group = 2;
			g2 += 1;
		} else if(Info[i].zip >= 65000 && Info[i].zip <= 66000){
			group = 3;
			g3 += 1;
		}
		printf("\n%d\t%s\t%d\t%s\t%d", i + 1,Info[i].county,Info[i].zip,Info[i].city,group);
	}
	printf("\n===============================================");
	printf("\nNumber of information in Group 1 : %d", g1);
	printf("\nNumber of information in Group 2 : %d", g2);
	printf("\nNumber of information in Group 3 : %d", g3);
	printf("\n===============================================");
}
void frequency(char *filename, int size, int group)
{
	int lowb =0;
	int highb =0;
	if( group == 1)
	{
		lowb = 63000;
		highb = 63999;
	} else if ( group == 2)
	{
		lowb = 64000;
		highb = 64999;
	} else if ( group == 3)
	{
		lowb = 65000;
		highb = 66000;
	}
	printf("\n===============================================");
	printf("\n Cities in group %d...", group);

	for (int i = 0; i< size;++i)
	{
	}
	int count = 1;
	char* c1;
	char* c2;
	char* c3;
	for ( int i  = 0; i < size ; ++i)
	{
		if (Info[i].zip >= lowb && Info[i].zip <= highb)
		{
				printf("\n[%d]\t%s",count,Info[i].city);
				count += 1;
		}
	}
	printf("\n===============================================");
	int three =0 ;
	int c =  0;
	while(three != 3)
	{
		if (Info[c].zip >= lowb && Info[c].zip <= highb)
		{
			if (Info[c].city != Info[c+1].city)
			{
				if (three == 0)
				{
					c1 = Info[c].city;
				}
				if (three == 1)
				{
					c2 = Info[c].city;
				}
				if (three == 2)
				{
					c3 = Info[c].city;
				}
				three += 1;
			} 
		}
		c +=1;
	}
	int c1n = 0;
	int c2n = 0;
	int c3n = 0;
	for(int i = 0; i < size; ++i)
	{
		if(Info[i].city == c1)
		{
 			c1n +=1;
		}	
		if(Info[i].city == c2)
		{
 			c2n +=1;
		}	
		if(Info[i].city == c3)
		{
 			c3n +=1;
		}	
	}
	printf("\n FREQUENCY TABLE.........");
	printf("\n\ns/no\tCity\tFrequency");	
	printf("\n1\t%s\t%d", c1,c1n);
	printf("\n1\t%s\t%d", c2,c2n);
	printf("\n1\t%s\t%d", c3,c3n);

}
