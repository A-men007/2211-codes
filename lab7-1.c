#include <stdio.h>
#define LEN 3
int sum_array(const int a[], int size){
  int sum = 0;
  int *p;
   p = a;
  while (p < a + size){
    sum += *(p);
    p++;
  }
  return sum;
}

int sum_two_dimensional_array(const int a[][LEN], int n){
  int size, sum = 0;
  int *p = a;
  size = n*LEN;
  while (p < *a + size){
    sum += *(p);
    p++;
  }
  return sum;
}

int main(){
  int a[3] = {1,2,3};
  int b[3][3] = {{1,2,3},{1,2,3}};
  int answer = sum_array(a, 3);
  printf("The answer is : %d\n", answer);
  const int len = 3;
  int answer2 = sum_two_dimensional_array(b, 3);
  printf("The answer is : %d\n", answer2);
}
