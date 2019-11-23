#include <stdio.h>

int main(void) {
    int n;
    double euler = 1, term = 1;

    printf("Enter the value of n: ");
    if(scanf("%d", &n) != 1) {
        return 1;
    }

    for(int i = 1; i <= n; i++) {
        term /= i;
        euler += term;
    }
    printf("%.15f\n", euler);
    return 0;
}