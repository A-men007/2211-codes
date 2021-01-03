#include <stdio.h>
#include "anything.h"

int main() {
	char s = "samthedean";
	char check = 'the';

	char value = findLast(&s, &check);
	printf("the value came back as: %s", value);
}