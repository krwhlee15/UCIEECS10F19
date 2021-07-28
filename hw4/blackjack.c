/* Assignment 4 
 * Wonhee Lee
 * 10/22/2019 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int main(void)
{
	srand(time(NULL));

	printf("\n**********************************\n");
	printf("** Welcome to EECS10 BlackJack! **\n");
	printf("**********************************\n");
	
	int total1 = 0;
	int c1 = 0;
	int yn = 0;
	
	int count = 1;
	
	int total2 = 0;
	int c2 = 0;
	int A = 0;
	while (total1 < 21)
	{
		c1 = (rand() % 13) + 1;
		
		if (count == 1)
		{
			printf("Your first card is:");
		}
		else
		{
			printf("Your next card is:");
		}
	
			
		switch (c1)
		{
			case 11:
			{
				printf("J\n");
				break;
			}
			case 12:
			{
				printf("Q\n");
				break;
			}
			case 13:
			{
				printf("K\n");
				break;
			}
			case 1:
			{
				printf("A\n");
				printf("Do you want it to be 1 or 11? ");
				scanf("%d", &A);
				c1 = A;
				break;
			}
			default:
			{
				printf("%d\n", c1);
				break;
			}
		}
		
		total1 += c1;
		if(count > 1)
		{
			printf("Your combined value is:%d\n", total1);
		}
		
		if (total1 > 21)
		{
			printf("Sorry. You lose!\n");
			break;
		}
		
		count++;
		printf("Do you want another card?\n");
		printf("Type 1 for Yes, 0 for No:\n");
		scanf("%d", &yn);
		if (yn == 0)
		{
			while(total2 < 21)
			{
				printf("Dealer draws another card.\n");
				c2 = (rand() % 13) + 1;
	
				printf("Dealer's card is:");
				switch (c2)
				{
					case 1:
					{
						printf("A\n");
						break;
					}
					case 11:
					{
						printf("J\n");
						break;
					}
					case 12:
					{
						printf("Q\n");
						break;
					}
					case 13:
					{
						printf("K\n");
						break;
					}
					default:
					{
						printf("%d\n", c2);
						break;
					}
				}
				total2 += c2;
				printf("Dealer's value is %d, you have %d.\n", total2, total1);
				
				if (total2 > 21)
				{
					printf("Dealer loses. You win!\n");
					break;
				}
				if (total2 >= total1)
				{
					printf("Sorry. You lose!\n");
					break;
				}
				else { continue; }
			}
			break;	
		}	
		else { continue; }
	}
	
	return 0;
}
