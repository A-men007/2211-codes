/*program that approximates e by computing the value
e=1+1/2!+1/3!...1/n! n is small integer entered by user*/
#include <stdio.h>
#include <math.h>

double euler(double val) {
	long long factorial = 1;
	int i = 1;
	double e = 1, prev;
	while (fabs(e-prev) >= val) {
		prev = e;
		factorial = factorial * i++;
		e += 1.0 / factorial;
	}
	return e;
}
int main() {
	double val, e;
	printf("Please enter a small decimal value: ");
	scanf("%lf", &val);
	e = euler(val);
	printf("euler approximation is: %.15f\n", e);
	return 0;
}
