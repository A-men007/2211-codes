#include <stdio.h>

int main () {
    int arrA[] = {5, 6, 7, 9};
    int k, a, b;
    printf ("enter value of summation: ");
    scanf("%d", &k);
    for (int i=0; i<sizeof(arrA); i++) {
        a = arrA[i];
        for (int j=0; j<sizeof(arrA); j++) {
            b = arrA[j];
            if (a+b == k) {
                return true;
            }

        }

    }
}