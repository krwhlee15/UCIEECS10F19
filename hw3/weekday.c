/* Assignment 3 
 * Wonhee Lee
 * 10/10/2019 */

#include <stdio.h>

int main(void)
{
	int w, d, m, y, J, K;

	printf("Please enter a calendar date:\n");
	printf("Day			 d = ");
	scanf("%d", &d);
	printf("Month			 m = ");
	scanf("%d", &m);
	printf("Year			 y = ");
	scanf("%d", &y);

	printf("For the date %d/%d/%d, the day of the week is ", m, d, y);

	if(m<3)
	{
		m += 12;
		y -= 1;
	}

	J = y/100;
	K = y%100;

	w = (d + (((m+1)*13)/5) + K + (K/4) + (J/4) - (2*J)) % 7;
	
	printf("%d.\nThis is a ", w);
	if(w==0)
	{
		printf("Saturday.");
	}

	if(w==1)
	{
		printf("Sunday.");
	}
	if(w==2)
	{
		printf("Monday.");
	}
	if(w==3)
	{
		printf("Tuesday.");
	}
	if(w==4)
	{
		printf("Wednesday.");
	}
	if(w==5)
	{
		printf("Thursday.");
	}
	if(w==6)
	{
		printf("Friday.");
	}
		
	printf("\n");

	return 0;
}

