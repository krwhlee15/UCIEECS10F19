/* Assignment 2
 * Wonhee Lee
 * 10/03/2019 */

#include <stdio.h>

int main(void)
{
	int i1, i2, s, p, d, q, r;
	printf("Please enter two numbers.\n");
	printf("Number 1: ");
	scanf("%d", &i1);
	printf("The first number is %d\n", i1);
	printf("Number 2: ");
	scanf("%d", &i2);
	printf("The second number is %d\n", i2);
	
	s = i1 + i2;
	p = i1 * i2;
	d = i1 - i2;
	q = i1 / i2;
	r = i1 % i2;

 	printf("The sum is %d.\n", s);
	printf("The product is %d.\n", p);
	printf("The difference is %d.\n", d);
	printf("The quotient is %d.\n", q);
	printf("The remainder is %d.\n", r);

	return 0;
}
	
	
