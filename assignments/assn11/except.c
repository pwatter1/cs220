#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <setjmp.h>
#include <string.h>

#define ARRAY_SIZE 15

/*globals */
jmp_buf buf;
int g = 10;
struct var_state {
	void *address;
	unsigned int size;
	char *data;
	struct var_state *next;
};
struct var_state *var_state_head = NULL;

void save_state(void *addr, unsigned int size)
{
	struct var_state* var = (struct var_state*) malloc(sizeof(struct var_state));
	var->address = addr;
	var->size = size;
	var->data = (char *) malloc(sizeof(size));
	memcpy(var->data, addr, size);	

	if(var_state_head == NULL)
	{
		var_state_head = var;
		var->next = NULL;
	}else
	{
		var->next = var_state_head;
		var_state_head = var;
	}
}

void print_state()
{
	struct var_state *temp = var_state_head;
	while(temp != NULL)
	{
		printf("%p---", temp->address);
		temp = temp->next;	
	}		
	printf("\n"); printf("end of list\n");
}

void restore_state()
{
	struct var_state *temp = var_state_head;	
	while(temp != NULL)
	{
		memcpy(temp->address, temp->data, temp->size);
		free(temp);
		free(temp->data);
		temp = temp->next;
	}
}

void sig_handler(int a)
{
	switch(a) {
		case SIGSEGV:
			printf("Inside state...Segfault\n");
			longjmp(buf, SIGSEGV);
			break;
		default:break;
	}
}

void f()
{
	int x, y; char *p; x = 11; 
	p = (char *) malloc(ARRAY_SIZE);
	p[0] = p[1] = 'x';

	signal(SIGSEGV, sig_handler);

	/* save state */
	save_state(&x, sizeof(x));
	save_state(&g, sizeof(g));
	save_state(&p, ARRAY_SIZE);

	y = setjmp(buf);	
	
	if(y != 0)
	{
		g = 30;
		x = 100;
		p = 0;
		p[0] = p[1] = p[2] = 'x';
	}else
	{
		restore_state();
		printf("%d, %d, %c, %c\n", g, x, p[0], p[1]);
	}
	free(p);
}

int main(){ f(); }
	
