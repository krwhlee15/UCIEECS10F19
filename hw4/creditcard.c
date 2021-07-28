/* Assignment 4 
 * Wonhee Lee
 * 22/10/2019 */

#include <stdio.h>
int main (void)
{
  double cl, b, apr, mp;

  printf ("Enter the crdit limit         : ");
  scanf ("%lf", &cl);
  printf ("Enter the balance on the card : ");
  scanf ("%lf", &b);
  printf ("Enter the APR                 : ");
  scanf ("%lf", &apr);
  printf ("Enter the montly payment      : ");
  scanf ("%lf", &mp);

  double i;
  double nb = b;
  printf ("\nMonth  Balance    Interest    Payment    New Balance\n");

  int count = 1;
  double total = b;


	while (nb > 0)
    {
      b = nb;
      i = nb * (apr / 12 / 100.0);
      total += i;  
	
	if (mp > b)
	{
	  mp = nb + i;
	  nb = 0;
	  printf ("%2d     %7.2f    %5.2f       %6.2f     %7.2f\n", count, b, i, mp, nb);
	  break;
	}
	
      nb = nb - mp + i;
      printf ("%2d     %7.2f    %5.2f       %6.2f     %7.2f\n", count, b, i, mp, nb);
      count++;
    }

  printf ("\nIt will take $%.2f over %d month to pay off this debt.\n", total, count);

  return 0;
}
