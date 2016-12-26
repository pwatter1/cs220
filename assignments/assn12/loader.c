#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int main(int argc, char *argv[])
{		
	FILE *fp;
	unsigned int val1, val2;
	int i, begin, size = 0;
	unsigned char *raw_bytes, operator;
	typedef int (*Calc_fptr)(unsigned char, int, int);
	Calc_fptr calculator;

	/* too many arguments */
	if(argc != 5){
		printf("Usage %s <filename> <uint> <operation> <uint>\n", argv[0]);
		exit(1);
	}

	fp = fopen(argv[1], "rb");
	if(fp == NULL){ printf("Failed Opening File\n"); exit(1);}

	/* determine size of array */
	begin = ftell(fp);
	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	fseek(fp, begin, SEEK_SET);
	
	raw_bytes = malloc(size);
	
	fread(raw_bytes, size, 1, fp);
	
	val1 = atoi(argv[2]);
	val2 = atoi(argv[4]);
	operator = *argv[3];

	calculator = (Calc_fptr) raw_bytes;
	printf("%u %c %u = %u\n", val1, operator, val2, calculator(operator, val1, val2));
	
	return 0;
}
