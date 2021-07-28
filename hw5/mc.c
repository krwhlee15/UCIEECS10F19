/* Assignment 5
 * Wonhee Lee
 * 10/28/2019 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	srand(0);
	int r, p;	
	
	printf("Enter the radius of circle:  ");
	scanf("%d", &r);
	printf("Enter the number of points:  ");
	scanf("%d", &p);

	int in = 0, out = 0;
	double x, y;
	int count = 0;
	while (count < p)
	{
		x = (((double)rand())/((double)(RAND_MAX)))*2*r;
		y = (((double)rand())/((double)(RAND_MAX)))*2*r;
		
		printf("Point No.%d(x=%f, y=%f) :  ", count, x, y);
		if (((x-r)*(x-r)) + ((y-r)*(y-r)) <= (r*r))
		{
			printf("IN\n");
			in++;
		}
		else
		{
			printf("OUT\n");
			out++;
		}
		count++;
	}
	
	printf("/******In Summary******/\n");
	printf("Points within circle area:  %d\n", in);
	printf("Points out of circle area:  %d\n", out);
	double Pi = 4 * ((double)in / (double)(in + out));
	printf("Pi = %f\n", Pi);

	return 0;	
}
