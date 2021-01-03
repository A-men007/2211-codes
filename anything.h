#include <stdio.h>
#include <string.h>

char *findLast(const char *s, const char *searchStr) {
char *sp=NULL;
int ls=strlen(s), lss=strlen(searchStr);
 for (int i=ls-lss; i>=0; i--) {
 if (strncmp(s+i, searchStr, lss)==0) {
 sp = s+i;
 break;
 }
 }
 return sp;
}