/* Assignment 5
 * Wonhee Lee
 * 10/29/2019 */

#include <stdio.h>

long double power(long double x, int y);

long double power(long double x, int y)
{
	long double result = 1;
	int i;	
	for(i=0;i<y;i++)
	{
		result *= x;
	}
	
	return (result);
}

int main(void)
{
	long double x;
	int n;
	printf("Please input a positive number (1 to 10000): ");
	scanf("%Lf", &x);	
	printf("Please input the value of integer n (n>0): ");
	scanf("%d", &n);

	long double x1 = x;
	long double x2 = 0;
	long double f, g;
	int count = 1;
	
	while (1)
	{
		f = power(x1, n) - x;
		g = (n)*(power(x1, n-1));		
		x2 = x1 - (f/g);

		switch (n)
		{
			case 2:
			{
				printf("Iteration %d: the square root of %.10Lf is approximately %.10Lf\n", count, x, x2);
				break;
			}
			case 3:
			{
				printf("Iteration %d: the cube root of %.10Lf is approximately %.10Lf\n", count, x, x2);
				break;
			}
			default:
			{
				printf("Iteration %d: the %dth root of %.10Lf is approximately %.10Lf\n", count, n, x, x2);
				break;
			}
		}
		if((x2*x2 - x)< 0.00000000005)
		{
			break;
		}
		x1 = x2;
		count++;
	}
	return 0;
}
