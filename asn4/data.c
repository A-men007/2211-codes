#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"

Key *key_construct(char *in_name, int in_id) {
	//Dynamic allocation of memory for holding key
	Key *ptr = (Key*)malloc(sizeof(Key));
	//Dynamic allocation of memory for the key's ..... (*ptr).name = ptr->name
	ptr->name = (char *)malloc((strlen(in_name)+1)*sizeof(char));
	//set key's id to be in_id (*ptr).id = ptr->id
	(*ptr).id = in_id;
	strcpy(ptr->name, in_name);
	return ptr;
}

int key_comp(Key *key1, Key *key2) {
	int value = strcmp(key1->name, key2->name);
	if (value < 0 || value > 0) {
		return value;
	}
	else {
		if (key1->id < key2->id)
			return -1;
		if (key1->id > key2->id)
			return 1;
		else
			return 0;
	}
}
void print_key(Key *key) {
	char *name = key->name;
	int id = key->id;
	printf("%s, %d", name, id);
}


void print_node(Node node) {
	printf("(%10s  %5i) %5d \n", node.key->name, node.key->id, node.data);
}



