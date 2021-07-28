/* Assignment 5
 * Wonhee Lee
 * 10/29/2019 */

#include <stdio.h>

long double power(long double x, int y);

long double power(long double x, int y)
{
	int i;
	long double result = 1;
	for(i=0;i<y;i++)
	{
		result *= x;	
	}
	return(result);
}

int main(void)
{
	long double x;
	int n;
	printf("Please input a positive number (1 to 10000): ");
	scanf("%Lf", &x);	
	printf("Please input the value of integer n (n>0): ");
	scanf("%d", &n);

	long double a = 0;
	long double b = x;	
	long double m1;
	long double m2 = x;	
	int count = 1; 
	
	while (1)
	{
		m1 = (a+b)/2;
		if(m2 > m1)
		{
			if(m2 - m1 < 5.0E-11)
			{
				break;
			}
		}
		else
		{
			if(m1 - m2 < 5.0E-11)
			{
				break;
			}
		}
		m2 = m1;
		switch (n)
		{
			case 2:
			{
				printf("Iteration %d: the square root of %.10Lf is approximately %.10Lf\n", count, x, m1);
				break;
			}
			case 3:
			{
				printf("Iteration %d: the cube root of %.10Lf is approximately %.10Lf\n", count, x, m1);
				break;
			}
			default:
			{
				printf("Iteration %d: the %dth root of %.10Lf is approximately %.10Lf\n", count, n, x, m1);
				break;
			}
		}
		if (power(m1,n) > x)
		{
			if (power(m1,n) - x < 5.0E-11)
			{
				break;
			}
			b = m1;
		}
		else
		{
			if (x - power(m1,n) < 5.0E-11)
			{
				break;
			}
			a = m1;
		}			
		count++;
	}
	return 0;
}
