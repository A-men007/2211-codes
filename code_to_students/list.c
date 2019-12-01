#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "memory.h"
// Return a pointer to a dynamically allocated and initialized List
List list_ini(void) {
	List_node *head= (List_node *) simu_malloc( sizeof(List_node) ); 
	head->next = NULL;
	return head;
}

// If key is in list, return the address of key’s associated data. If key is not in list, return NULL.
Data *list_search(List list, Key key) {
	while (list != NULL) {
		if(list->key != key) {
			list = list->next;
		}
		else {
			return &list->data;
		}
		return NULL;
	}
}

// Add key with data into the front of list. If key is in list, then do nothing
void list_add(List list, Key key, Data data) {
	if (list_search(list, key) != NULL) {
		return;
	}
	else{
		//create ptr that points to new node in list
		List_node *oldh = (List_node *) simu_malloc(sizeof(List_node));
		//copies root data into new node
		oldh->data = list->data;
		oldh->key = list->key;
		oldh->next = list->next;
		//
		list->next = oldh; //might be off
		list->key = key;
		list->data = data;
	}
	return;
}

// Delete the node in list with its key equals to key. If no such node in list, do nothing.
//to delete skip the link to the "deleted" node and free its memory...
//3 cases: del begining, middle, and end
void list_delete(List list, Key key) {
	//if its root...
	if(list->key == key ) {
		List_node *newhead = (List_node *) simu_malloc(sizeof(List_node));
		printf("FIRST\n");
		newhead->key = list-key;
		newhead->data = list->data;
		*list = *list->next;
		list_free(newhead);
	}
	//to store list current node & previous node
	List current = list;
	List previous = list;
	//middle algorithm
	while (current->next != NULL) {
		if (key_comp(current->key, key) == 0) {
			previous->next = current->next;	
		}
		previous = current;
		current = current->next;
	}
}

// Linearly traversal the list and print each node’s key and data
void list_print(List list) {
   	if(list != NULL) {
   	    print_list_node(list);
       	list_print(list->next);
   	}
}

// Free all the dynamically allocated memory of list.
void list_free(List list) {
	simu_free(list);
}
