/* Doubly Linked List Selection Sort */

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

Node *head; /* global*/
Node *real_head;

/*REMOVE MAIN FROM SORTER>C MUST BE IN DRIVER BEFORE SUBMIT */

Node *sort_nodes(Node *head)
{
	/* selection sort */
	Node *begin = head;
	Node *head_R;
	Node *current;
	Node *max;
	int q = find_length(head);
	int i;

	Node *temp;

	if(begin != NULL){
		max = begin;
		current = begin->next;
		while(current != NULL){
			if(max < current){ max = current;}
			current = current->next;
		}
		head_R = max;
	}
	
	for(;;){
		temp = head;
		for(i = 0; i < (q-1); i++){temp = temp->next;}
		q--;
		if(temp->prev != NULL){
			max = head;
			current = head->next;
			while(current != NULL){
				if(max < current){max = current;}
				current = current->next;
			}
		}		
		else{
			break;
		}
		printf("max: %p\n", max);
		remove_node(max);
		print_list(head);
		/*swap(head_R, max);*/
	}
	return head_R;
}

int find_length(Node *head)
{
	Node *current = head;
	int count = 0;
	while(current != NULL){
		count++;
		current = current->next;
	}
	return count;
}

Node *remove_node(Node *n)
{
	if(n == NULL){return NULL;}
	if(n->prev != NULL && n->next != NULL){
		n->prev->next = n->next;
	}
	if(n->next == NULL){
		n->prev->next = NULL;
	}
	if(n->prev == NULL){
		n->next->prev = NULL;
		head = n->next;
	}
	return n;
}

int swap(Node *head_R, Node *max)
{
	




	/*printf("ORIG---");
	print_list(head);

	Node *temp = head_R;
	while(temp->next != NULL){
		temp = temp->next;
	}
	printf("\n");
	printf("temp: %p\n", temp);

	temp->next = max;
	max->prev = temp;
	max->next = NULL;

	printf("NEW----");
	print_list(head_R);*/
	return 0;
}

Node *create()
{
	Node *temp = head;
	Node *new = (Node *) malloc(sizeof(Node));
	if(new == NULL){ return NULL;}
	new->next = NULL;

	while(temp->next != NULL) temp = temp->next;
	temp->next = new;
	new->prev = temp;
	return new;
}

void print_list(Node *head)
{
	Node *current = head;
	while(current != NULL){
		printf("%p --- ", current);
		current = current->next;
	}
	printf("\n");
}

int main()
{
	Node *tmp1_b, *tmp2_b, *tmp3_b, tmp4_b, tmp5_b, tmp6_b, tmp7_b;
	tmp1_b = malloc(sizeof(Node));
	tmp2_b = malloc(sizeof(Node));
	tmp3_b = malloc(sizeof(Node));

	tmp1_b->next = tmp2_b;
	tmp1_b->prev = NULL;

	tmp2_b->next = tmp3_b;
	tmp2_b->prev = tmp1_b;

	tmp3_b->next = &tmp5_b;
	tmp3_b->prev = tmp2_b;

	tmp4_b.next = &tmp7_b;
	tmp4_b.prev = &tmp6_b;

	tmp5_b.next = &tmp6_b;
	tmp5_b.prev = tmp3_b;

	tmp6_b.next = &tmp4_b;
	tmp6_b.prev = &tmp5_b;
	
	tmp7_b.next = NULL;
	tmp7_b.prev = &tmp4_b;
	print_list(tmp1_b);
	Node *new_head = sort_nodes(tmp1_b);
	print_list(new_head);		


	/*
	head = (Node *) malloc(sizeof(Node));
	create();
	Node test, test2;
	create();
	head->next->next->next = &test;
	test.prev = head->next->next;
	test.next = NULL;
	create();
	create();
	create();
	create();
	printf("\n");
	print_list(head);
	printf("-----------------------------------------------------------------\n");
	real_head = sort_nodes(head);
	/*print_list(real_head);*/
	return 0;
}
