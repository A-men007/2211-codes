#include "Memory.h"
#include "list.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
  //get input  for size of memry & list, ini both
    printf("Enter a size for dynamic memory allocation and deallocation system:\n");
    int size;
    //size >= 20 
    scanf("%d", &size);
    mem_ini(size);


    List_node* list = list_ini();
    printf("Enter a key integer: (one int per line)\n");

    Key key;

    while (scanf("%d", &key) != EOF)
    {
        //counts occourances for each data
        if(list_search(list, key) == NULL) {
            list_add(list, key, 1);
        }
        else {
            Data occur = *list_search(list, key);
            list_delete(list, key);
            list_add(list, key, occur + 1);
        }

    }
    //print list....
    printf("Integers          Occurances\n");
    list_print(list);

    //free memory for list and dynamically allocate
    list_free(list);
    mem_free();
}