
#include <stdio.h>
#include "bst.h"
int main(void) {
    FILE *fp;
    char txtFile[32];
    int R, id, data;
    char word[32];
    //create binary search tree
    BStree bst;
    bst = bstree_ini(65);
    //ask user for file of objects to insert
    printf("Enter the name of the file to read in (include.txt): ");
    //scan in input
    scanf("%s", txtFile);
    //open the .txt file
    fp = fopen(txtFile, "r");
    //if file does not exist, exit and print error
    if (fp == NULL) {
        printf("Error with opening file\n");
        return -1;
    }
    //if file does exist, read in line by line
    else {
        while (R != EOF) {
            //scan in the word, id, and data from the line
            R = fscanf(fp, "%s%d%d", word, &id, &data);
            bstree_insert(bst, key_construct(word, id), data);
        }
        //close file when end is reached
        fclose(fp);
        //operate a transversal on the binary search tree
        bstree_traversal(bst);
        //free memory before ending
        bstree_free(bst);
    }
    //exit program safetly 
    return 0;
}