/* Assignment 3
 * Wonhee Lee
 * 2019/10/10 */

#include <stdio.h>

int main(void)
{
	double x, ex;
	
	printf("Please enter the real value x: ");
	scanf("%lf", &x);
	
	ex = 1 + x + (x*x/2) + (x*x*x/3/2) + (x*x*x*x/4/3/2) + (x*x*x*x*x/5/4/3/2)
		 + (x*x*x*x*x*x/6/5/4/3/2) + (x*x*x*x*x*x*x/7/6/5/4/3/2);

	printf("e to the power of x is approximately %f", ex);
	printf("\b\b\bxxx\n");

	return 0;
}
