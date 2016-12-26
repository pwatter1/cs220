#include <stdio.h>
#include <stdlib.h>
#include "node.h"

Node *max, *current, *header, *temp, *tail;

Node *sort_nodes(Node *head){
	int i, p = 0, q = 1;
	if(head == NULL){return NULL;}
	Node *begin = head;
	header = find_max(head);
	trade(begin, max);
	while(p != -1){
		temp = header;
		for (i = 0; i < q; i++){temp = temp->next;}
		q = q + 1;
		if(temp != NULL){
			find_max(temp);
		}else{p = -1; continue;}
		trade(temp, max);
	}return header;
}

Node *find_max(Node *begin){
	if(begin != NULL){
		max = begin;
		current = begin->next;
		while(current != NULL){
			if(max < current){max = current;}
			tail = current;
			current = current->next;
		}
	}return max;
}

/* https://ptspts.blogspot.com/2010/01/how-to-swap-two-nodes-in-doubly-linked.html */
void trade(Node *what, Node *where){
	Node *temp = what->next;
	what->next = where->next;
	where->next = temp;

	if(what->next){what->next->prev = what;}
	if(where->next){where->next->prev = where;}

	temp = what->prev;
	what->prev = where->prev;
	where->prev = temp;

	if(what->prev){what->prev->next = what;}
	if(where->prev){where->prev->next = where;}
}


