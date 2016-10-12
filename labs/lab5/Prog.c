/* Prog.c */
#include <stdio.h>


void bad(int dummy)
{
	/* change the values in function main's struct from bad through memory	*/
	
	
	char *name_ptr = malloc(dummy);
	name_ptr = (char *) &dummy + 0x24;
	*name_ptr = (char* )"Quick brown fox jumped over the lazy dog";
	int * age_ptr = malloc(dummy);
	/* change address with offset */
	age_ptr = (char *) &dummy + 0x2c;
	*age_ptr = (int *) 1000;
	
	//printf("---------------------\n");
}

int main(){
	struct{
		char *name;
		int age;
	} student = { .name="John",
			.age=22};
	bad(sizeof(student));
	printf("student.name = %s\nstudent.age = %d\n", student.name, student.age);
	return 0;
}

