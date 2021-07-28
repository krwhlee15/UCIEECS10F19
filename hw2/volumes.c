/* Assignment 2
 * Wonhee Lee
 * 10/03/2019 */

#include <stdio.h>

int main(void)
{
	printf("Please enter two liquid volumes: \n");
	
/*First liquid volume input*/
	int g1, q1, p1, c1, fo1, tabs1, teas1;
	double l1;
 
	printf("First volume, gallon(s): ");
	scanf("%d", &g1);
	printf("First volume, quart(s): "); 
	scanf("%d", &q1);
	printf("First volume, pint(s): ");
	scanf("%d", &p1);
	printf("First volume, cup(s): ");
	scanf("%d", &c1);
	printf("First volume, fluid ounce(s): ");
	scanf("%d", &fo1);
	printf("First volume, table spoon(s): ");
	scanf("%d", &tabs1);
	printf("First volume, tea spoon(s): ");
	scanf("%d", &teas1);

	int totalteas1;

	totalteas1 = (g1*4*2*2*8*2*3) + (q1*2*2*8*2*3) + (p1*2*8*2*3) + (c1*8*2*3) + (fo1*2*3) + (tabs1*3) + teas1;
	
	printf("Liquid volume 1 is %d gallon(s), %d quart(s), %d pint(s), %d cup(s), %d fluid ounce(s), %d table spoon(s), %d tea spoon(s).\n", g1, q1, p1, c1, fo1, tabs1, teas1);
	
	l1 = ((double)(totalteas1)/3/2/8/2/2/4)*3.7854;

	printf("It is approximately %.3f liters.\n\n", l1);
/*end of first liquid volume input*/

/*Second liquid volume input*/
	int g2, q2, p2, c2, fo2, tabs2, teas2;
	double l2;

	printf("Second volume, gallon(s): ");
	scanf("%d", &g2);
	printf("Second volume, quart(s): "); 
	scanf("%d", &q2);
	printf("Second volume, pint(s): ");
	scanf("%d", &p2);
	printf("Second volume, cup(s): ");
	scanf("%d", &c2);
	printf("Second volume, fluid ounce(s): ");
	scanf("%d", &fo2);
	printf("Second volume, table spoon(s): ");
	scanf("%d", &tabs2);
	printf("Second volume, tea spoon(s): ");
	scanf("%d", &teas2);

	int totalteas2;

	totalteas2 = (g2*4*2*2*8*2*3) + (q2*2*2*8*2*3) + (p2*2*8*2*3) + (c2*8*2*3) + (fo2*2*3) + (tabs2*3) + teas2;
		
	printf("Liquid volume 2 is %d gallon(s), %d quart(s), %d pint(s), %d cup(s), %d fluid ounce(s), %d table spoon(s), %d tea spoon(s).\n", g2, q2, p2, c2, fo2, tabs2, teas2);

	l2 = ((double)(totalteas2)/3/2/8/2/2/4)*3.7854;
	printf("It is approximately %.3f liters.\n\n", l2); 
/*end of second liquid volume input*/

/*total*/
	int g, q, p, c, fo, tabs, teas;
	double l;
	
	int totalteas;

	totalteas = totalteas1 + totalteas2;
	
	tabs = totalteas/3;
	teas = totalteas%3;
	fo = tabs/2;
	tabs = tabs%2;
	c = fo/8;
	fo = fo%8;
	p = c/2;
	c = c%2;
	q = p/2;
	p = p%2;
	g = q/4;
	q = q%4;	

	l = ((double)(totalteas)/3/2/8/2/2/4)*3.7854;

	printf("The sum is %d gallon(s), %d quart(s), %d pint(s), %d cup(s), %d fluid ounce(s), %d table spoon(s), %d tea spoon(s).\n", g, q, p, c, fo, tabs, teas);
	printf("It is approxtimately  %.3f liters.\n", l);
	return 0;
/*EOF*/
}







