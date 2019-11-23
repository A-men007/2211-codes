#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "memory.h"

// add coments
List list_ini(void) {
	List_node *head= (List_node *) simu_malloc( sizeof(List_node) ); 
	head->next = NULL;
	return head;
}

// add coments
Data *list_search(List list, Key key) {
}

// add coments
void list_add(List list, Key key, Data data) {
}

// add coments
void list_delete(List list, Key key) {
}

// add coments
void list_print(List list) {
}

// add coments
void list_free(List list) {
}
