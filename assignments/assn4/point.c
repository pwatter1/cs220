#include <stdio.h>
#include <stdlib.h>
#include "point.h"

int contains_loop(struct Point *y)
{	
	if(y == NULL) return 0;
	
	/* create structs equal and one step ahead */
	/* will move through list at differing speeds to *
	 * see if ever there are two identical values */

	struct Point *slow=y, *fast= y->next;
	if(!fast) return 0;	
	
	/* the two intercepting eachother indicates loop */
	/* fast will obtain more values with which to compare */
	/* if NULL, return 0, no loop. Reached end of the list before a match was found */

	while(slow != fast){
		/* one step */
		slow = slow->next;
		if(!slow) return 0;
		/* two steps*/
		fast = fast->next;
		if(!fast) return 0;
		fast = fast->next;
		if(!fast) return 0;
	}

	/* return 1 if loop exists */
	return 1;
}


struct Point* transform_points(struct Point *points, struct Point *origin)
{	  
        struct Point *new_list = NULL, *prev=NULL;

	/* Iterate through points until NULL which signals end of linked list */
	while(points != NULL){
		if(points == NULL) return;
		struct Point *temp = (struct Point *) malloc(sizeof(struct Point));

		/* assign the new node's x,y & z floating */
		temp->x = (origin->x + points->x);
		temp->y = (origin->y + points->y);
		temp->z = (origin->z + points->z);

		/* unable to assign, dependent on which point */
		temp->next = NULL;
		
		if(new_list == NULL){
			/* first point */
			new_list = temp;
			prev = temp;
		}else{
			/* links new_list's points when temp is reassigned */
			prev->next = temp;
			prev = temp;
		}
		points = points->next;
	}
	
	return new_list;

}

