#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

BStree  bstree_ini(int size) {
	BStree binary_search_tree_init = (BStree) malloc(size * sizeof(BStree));
	binary_search_tree_init->tree_nodes = malloc(size * sizeof(binary_search_tree_init->tree_nodes));
	binary_search_tree_init->free_nodes = malloc(size * sizeof(binary_search_tree_init->free_nodes));
	binary_search_tree_init->size = size;
	binary_search_tree_init->top = 1;
	binary_search_tree_init->root = 0;
	for (size_t index = 0; index < size+1; index++) {
	  binary_search_tree_init->free_nodes[index] = index;
	}
	return binary_search_tree_init;
}

static int get_new_node(BStree binary_search_tree, Key *key, Data data)
{
	int new_idx = binary_search_tree->top;
	if (new_idx < binary_search_tree->size) {
		binary_search_tree->tree_nodes[new_idx].key = key;
		binary_search_tree->tree_nodes[new_idx].data = data;
		binary_search_tree->tree_nodes[new_idx].left = 0;
		binary_search_tree->tree_nodes[new_idx].right = 0;
		binary_search_tree->free_nodes[new_idx] = 0;
		binary_search_tree->top++;
		return new_idx;
	}
	else {
		printf("%d is out of bounds", new_idx);
	}
	// when out of bonds choosen
	return -1;
}

static void bst_helper_function(BStree binary_search_tree, int *index, Key *key, Data data)
{
	Node *binary_root = &binary_search_tree->tree_nodes[*index];
	int key_comp_value = key_comp(key, binary_root->key);

	if (key_comp_value < 0) {
		// char array is smaller than current one
		if (binary_root->left != 0) {
			bst_helper_function(binary_search_tree, &binary_root->left, key, data);
		}
		else {binary_root->left = get_new_node(binary_search_tree, key, data);}
	}
	else if (key_comp_value > 0) {
		// Char array is greater than current one
		if (binary_root->right != 0) {
		bst_helper_function(binary_search_tree, &binary_root->right, key, data);}
		else {binary_root->right = get_new_node(binary_search_tree, key, data);
		}
	}
}

void bstree_insert(BStree binary_search_tree, Key *key, Data data) {
    if (binary_search_tree->top == 1)
    binary_search_tree->root = get_new_node(binary_search_tree, key, data);
    bst_helper_function(binary_search_tree, &binary_search_tree->root, key, data);
}
//define bstree_inorder which does the hard coding for the logic in inserting the node in the right spot
void bstree_traversal_inorder(BStree bst, int index){
	if (index == 0) {
		return;
	}
    if (bst->tree_nodes[index].left != 0) {
		bstree_traversal_inorder(bst, bst->tree_nodes[index].left);
	}
	print_node(bst->tree_nodes[index]);
	if (bst->tree_nodes[index].right != 0) {
		bstree_traversal_inorder(bst, bst->tree_nodes[index].right);
	}
}

void bstree_traversal(BStree bst) {
    int index = bst->root;
    if(index < bst->size)
    bstree_traversal_inorder(bst, bst->root);
	bstree_free(bst);
}

void bstree_free(BStree bst) {
	free(bst -> tree_nodes);
  free(bst -> free_nodes);
  free(bst);
}
