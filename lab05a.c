#include <stdio.h>
/*calc the polynomial of 3x^5 + 2x^4 - 5x^3 - x^2 + 7x -6*///92 x=2
float power(float base, int pwr){
    if (pwr != 0)
        return (base*power(base, pwr-1));
    else{
        return 1;
    }
}

int main() {
float val;
float ans;
printf("Enter a value for x: ");
scanf(" %f", &val); //x-value
ans = (3*(power(val,5)) + (2*(power(val,4))) - (5*(power(val,3))) - (power(val,2)) + (7*val) - 6);
printf("The polynomial value is: %f", ans);   
return 0;
}