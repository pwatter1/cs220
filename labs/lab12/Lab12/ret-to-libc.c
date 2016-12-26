#include <stdio.h>
#include <stdlib.h>

extern unsigned long *get_current_ebp();

void ret2libc(int temp)
{
	char *cmd = "/bin/bash";	

	unsigned long *current_ebp = grab_current_ebp();

	current_ebp[2] = current_ebp[1];
	current_ebp[1] = (unsigned long) &system;
	current_ebp[3] = (unsigned long) cmd;
}

void ret2libc_generic(char *cmd)
{
	unsigned long *current_ebp = grab_current_ebp();

	current_ebp[3] = current_ebp[2];	
	current_ebp[2] = current_ebp[1];
	current_ebp[1] = (unsigned long)&system;	
}

int main()
{	
	ret2libc_generic("ls");
	/* ret2libc(0); */
	printf("Done!\n");
	return 0;
}
