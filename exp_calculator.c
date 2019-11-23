#include <stdio.h>
#include <stdbool.h>
/* Function power returns the value of the power given the base and exponent:
  base ^ exponent */
float power(float b, int e) {
    float temp;
   if(e == 1) {
       return b;
   }
   else if (e == 0){
       return 1;
   }
   //for even exp's
   else if ((e%2) == 0){
       temp = power(b, e/2);
       return temp*temp;
   }
   //odd case
   else {
       temp = power(b,(e-1)/2);
       return temp*temp*b;
   }
   
    
}

int main() {
//set up variables
bool flag = true;
float base;
int exp;
while(flag) {
    flag =false;
    //prompt user
    printf("Please enter a positive base value: \n");
    scanf("%f",&base);
    printf("Please enter a non-negative exponent value: \n");
    scanf("%d",&exp);

    if (!(base>0)) {
        printf("Invalid! enter new base\n");
        flag = true;
    } 
    if (!(exp>=0)) {
        printf("Invalid! enter new exponent\n");
        flag = true;
    }
}
/* Calculate and display the result */
  if (exp >= 0){
    printf ("%f^ %d = %f \n", base, exp, power(base, exp));
  }
  else{
    printf ("%f^ %d = %f \n", base, exp, 1/(power(base, -exp)));
  }
}