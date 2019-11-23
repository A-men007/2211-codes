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
	unsigned int *ptr;
	ptr = (unsigned int *) malloc(size);
	//use Key *bstree data search(BStree bst, Data data);

}

// add comments
void simu_free(void *ptr) {

}

// add comments
void mem_print(void) {
}

// add comments
void mem_free(void) {

}
