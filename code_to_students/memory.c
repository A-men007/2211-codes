#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

static unsigned char *memory;
static BStree bst;

// add comments
void mem_ini(unsigned int size) {
	memory = (unsigned char *) malloc(size);
	bst = bstree_ini(size/5); // size/5 is large enough
	bstree_insert(bst, 0, size);
}

// add comments
void *simu_malloc(unsigned int size) {
	bstree_data_search(bst,size + 4); 
	Key indexvalue = *bstree_data_search(bst,size + 4);
	Data memsize = *bstree_search(bst,indexvalue); 
	bstree_delete(bst,indexvalue); 
	bstree_insert(bst,indexvalue + (size +4), memsize - (size + 4) );
	//find first 4 bytes and save the size in those first 4
	memory[indexvalue] = size; 
	return &memory[indexvalue +4];
}

//point to any data type but need to cast
void simu_free(void *ptr) { 
	//stores an address so does memory
    unsigned char * newPtr = (unsigned char*) ptr; 
	//size is of what the user wants but we add value + 4
    int valueofsize = *(int *) (newPtr -4); 
    bstree_insert(bst,(newPtr-4) - memory, valueofsize+4);
}

// Print all the free memory blocks.
void mem_print(void) {
	bstree_traversal(bst);
}

// Free memory used for the array and the binary search tree
void mem_free(void) {
	free(memory);
	bstree_free(bst);
}