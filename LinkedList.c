
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "LinkedList.h"

//
// Initialize a linked list
//
void llist_init(LinkedList * list)
{
	list->head = NULL;
}

//
// It prints the elements in the list in the form:
// 4, 6, 2, 3, 8,7
//
void llist_print(LinkedList * list) {

	ListNode * e;

	if (list->head == NULL) {
		printf("{EMPTY}\n");
		return;
	}

	printf("{");

	e = list->head;
	while (e != NULL) {
		printf("%d", e->value);
		e = e->next;
		if (e!=NULL) {
			printf(", ");
		}
	}
	printf("}\n");
}
//REMOVE ITH, ADD, READ, SAVE
//
// Appends a new node with this value at the beginning of the list
//
void llist_add(LinkedList * list, int value) {
	// Create new node
	ListNode * n = (ListNode *) malloc(sizeof(ListNode));
	n->value = value;

	// Add at the beginning of the list
	n->next = list->head;
	list->head = n;
}

//
// Returns true if the value exists in the list.
//
int llist_exists(LinkedList * list, int value) {
	int i = 0;
	ListNode * x = (ListNode *) malloc(sizeof(ListNode));
	x = list-> head;
	for (; (x != NULL) ; ) {
		if (! (x->value != value) ) 
			return 1;
		x = x-> next;
	}	
	return i;
}

//
// It removes the entry with that value in the list.
//
int llist_remove(LinkedList * list, int value) {
	int r = 1;
	//int counter = 0;

	ListNode* l = list-> head;
	for (; l -> next != NULL;) {
		if ( l -> next  -> value == value) {
			free( l-> next );
			l-> next  = l ->  next -> next;
			return r;

		}
	l = l-> next;
	}

	/*	ListNode* temp = NULL; 
		for (;( l != NULL); ) {
		if ( ! (l->value != value ) )
		break;
		temp = l;
		l = l -> next;
	//	counter++;
	}
	if (! (temp == NULL))
	temp = l;

	if (l== NULL )
	return r - 1;

*/
	return r -1;
}

int llist_remove_ith(LinkedList * list, int ith) {

	int counter;
	ListNode * l = list->head;
	ListNode * l2 ;
	ListNode * l3;
	counter = 0;                                             
	for (; (l != NULL) ; )  {
		if(ith == counter) {

			if(l2 != NULL && l->next != NULL) {
				l2->next = l->next;
			}
			//free(l->value);
			//free(l->next);
			free(l);

			return 1;
		}
	l2 = l;
	l = l->next;
	counter++;
	}

	return 0;

}

/*	int r = 1;
	ListNode * l = list -> head ;/* = (ListNode * ) malloc (sizeof(ListNode));
	ListNode * temp;// = (ListNode*) malloc (sizeof(ListNode));
	temp = NULL;
	l = list -> head;
	int i = 0;
	while (l != NULL) {
	if (i == ith)
	break;
	temp = l;
	l = l -> next;
	i++;
	}

	if (temp != NULL)
	temp -> next = l -> next;

	return (l == NULL) ? --r : r;*/
//interpretation part 2
/*	for (--ith; ith-- && l != NULL; l = l -> next);
	if (l->next!= NULL) {
	free(l->next);
	l = l -> next->next;
	return r;
	} 
	return r-1; */
/*	int i = 0;
//	ListNode * l = list-> head;
if (ith == 0) {
free(list-> head);
list->head = l-> next;
return 1;
}

for (; (l!= NULL && i < ith - 1) ;) {
if (l ==  NULL) {
return 0;
}
free( l -> next);
l-> next = l-> next -> next;
}
return ( l != NULL);

} */


int llist_get_ith(LinkedList * list, int ith , int * value) {
	//ListNode * l = (ListNode*) malloc ( sizeof(ListNode));
	ListNode * l = list -> head;
	int r = 1;
	int rand=0;
	for ( ; (! (l == NULL) ) ;) {
		if (! (ith != rand) ){
			*value = l-> value;
			return r;
		}
		l = l -> next;

		rand ++;
	}

	return r - 1;
}

//
// It returns the number of elements in the list.
//
int llist_number_elements(LinkedList * list) {
	int counter = 0;
	ListNode * l = (ListNode *) malloc(sizeof(ListNode));
	l = list-> head;
	for (; (!(l == NULL)) ;) {
		l = l-> next;
		counter++;
	}

	return counter;
}


//
// It saves the list in a file called file_name. The format of the
// file is as follows:
//
// value1\n
// value2\n
// ...
//
int llist_save(LinkedList * list, char * file_name) {
	FILE * fd = fopen(file_name, "w");
	int r = 1;
	ListNode * l;
	l = list-> head;
	if ( fd == NULL ) //if l == NULL
		return r-1;
	for (; !(l  == NULL) ;) {
		fprintf(fd , "%d\n",l ->value);
		l = l ->next;
	}


	//fprintf(fd, "%d\n", l  ->value); 
	fclose(fd);
	return 0;
}

//
// It reads the list from the file_name indicated. If the list already has entries, 
// it will clear the entries.
//
int llist_read(LinkedList * list, char * file_name) {
	int r = 1;
	int temp ;
	FILE * fd = fopen(file_name, "r");
	if (fd == NULL)
		return r - 1;
	//llist_init(list);

	for ( ;	( fscanf (fd,"%d", &temp ) != EOF  )	;     )
		llist_add(list, temp);
	fclose(fd);
	return r ;
}


//
// It sorts the list. The parameter ascending determines if the
// order si ascending (1) or descending(0).
//
void llist_sort(LinkedList * list, int ascending) {
	int i = 0;
	int tempA, tempB, tempC, tempD;
	tempA = 0;
	tempB = 0;
	tempC = 0;
	tempD = 0 ;
	ListNode * l = list -> head;
	ListNode * ln = list -> head -> next;
	if (ascending == 1) {
		for ( ; (!(l == NULL)) ;) {
			for (; (!(ln == NULL)) ;) {
				if (l-> value > ln-> value) {
					tempA = l-> value;
					tempB = ln-> value;
					l-> value = tempB;
					ln -> value = tempA;

				} 
				ln = ln -> next;
			}
			l = l-> next;
			ln = l;
		}
	} 
	if (ascending == 0) {
		for (;( !(l == NULL) ) ; ) {
			for (; (!( ln == NULL ) ) ; )  {
				if (ln -> value > l -> value) {
					tempC = l->value;
					tempD = ln -> value;
					ln-> value = tempC;
					l-> value = tempD;
				} 

				ln = ln -> next;
			} 
			l = l-> next;
			ln = l;
		}

	}

}
//ith, save, sort, fix it all !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//
// It removes the first entry in the list and puts value in *value.
// It also frees memory allocated for the node
//
int llist_remove_first(LinkedList * list, int * value) {
	int r = 1;
	ListNode * l = list -> head;
	if(l == NULL)
		return r -1;

	//list->head = list->head -> next;
	*value = l -> value;
	list->head = l->next;
	return r;
}

//
// It removes the last entry in the list and puts value in *value/
// It also frees memory allocated for node.
//
int llist_remove_last(LinkedList * list, int *value) {
	ListNode * l = list->head;
	ListNode * l2 = NULL;
	ListNode * l3 = NULL;
	int counter = 0;

	while(l != NULL) {
		counter++;
		l3 = l2;
		l2 = l;
		l = l->next;
	}
	*value = (l2!=NULL)?l2->value:0;
	if(l3 != NULL) {
		l3->next = NULL;
		return 1;
	} else {

		//printf("%d\n",counter);
		return 0;
	}
	//return llist_remove_ith(list, counter);

}

//
// Insert a value at the beginning of the list.
// There is no check if the value exists. The entry is added
// at the beginning of the list.
//
void llist_insert_first(LinkedList * list, int value) {
	/*	ListNode * l = (ListNode *) malloc(sizeof(ListNode));//malloc
		l -> value = value;

		l -> next = list -> head->next;
		list -> head = l;
		}*/
return llist_add(list,value);
}

//
// Insert a value at the end of the list.
// There is no check if the name already exists. The entry is added
// at the end of the list.
//
void llist_insert_last(LinkedList * list, int value) {
	ListNode * l = (ListNode *) malloc(sizeof(ListNode));
	l->value = value;
	if (list->head == NULL) {
		list -> head = l;
		//l -> value = value;
		list ->head -> next = NULL;
		return;

	}

	ListNode * e = list-> head;
	for (; (!( e->next == NULL) ) ;)
		e = e -> next;

	e->next  = l; 
}

//
// Clear all elements in the list and free the nodes
//
void llist_clear(LinkedList *list)
{
	ListNode * l = list->head;
	for ( ; ( l != NULL) ;) {
		free(l);
		l = l->next;
	}
	list->head = NULL;
}


