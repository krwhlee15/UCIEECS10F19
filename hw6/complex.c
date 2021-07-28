/* Assignment 6
 * Wonhee Lee
 * 10/31/2019 */

#include <stdio.h>
#include <math.h>

double sqrt(double value);
double atan(double value);
double cos(double value);
double sin(double value);
double angle(double x, double y);
double mgntd(double x, double y);
double rcprclx(double x, double y);
double rcprcly(double x, double y);
double multx(double a, double b, double c, double d);
double multy(double a, double b, double c, double d);
double dividex(double a, double b, double c, double d);
double dividey(double a, double b, double c, double d);

double angle(double x, double y) 
{
	double theta;
	double a = x;
	double b = y;
	if (a > 0)
	{
		theta = atan(b/a);
	}
	if (a < 0 && b >= 0)
	{
		theta = atan(b/a) + 3.1415926;
	}
	if (a < 0 && b < 0)
	{
		theta = atan(b/a) - 3.1415926;
	}
	if (a == 0 && b < 0)
	{
		theta = (-3.1415926)/2;
	}
	if (a == 0 && b == 0)
	{
		theta = 0;
	}
	return (theta*180/3.1415926);
}

double mgntd(double x, double y)
{
	return(sqrt((x*x)+(y*y)));
}

double rcprclx(double x, double y)
{
	return(x/((x*x)+(y*y)));
}

double rcprcly(double x, double y)
{
	return((-y)/((x*x)+(y*y)));
}

double multx(double a, double b, double c, double d)
{
	return((a*c) - (b*d));
}

double multy(double a, double b, double c, double d)
{
	return((b*c) + (a*d));
}

double dividex(double a, double b, double c, double d)
{
	return(((a*c)+(b*d))/((c*c)+(d*d)));
}

double dividey(double a, double b, double c, double d)
{
	return(((b*c)-(a*d))/((c*c)+(d*d)));
}



int main(void)
{
	double a, b;
	printf("Welcome to my complex number calculator!\n");
	printf("Enter a complex number.\n");
	printf("Enter the real part: ");
	scanf("%lf", &a);
	printf("Enter the imaginary part: ");
	scanf("%lf", &b);

	double r;
	double theta;
	
	int choice;
	double x,y;
	while(1)
	{
		r = mgntd(a, b);
		theta = angle(a, b);
		
		printf("\nCurrent number is %.3f + %.3fi\n", a, b);
		printf("Polar Notation: %.3f @ %.3f degrees\n\n", r, theta);


		printf("(1) Set the complex number in regular format\n");
		printf("(2) Set the complex number in polar format\n");
		printf("(3) Compute the absolute value of the number\n");
		printf("(4) Compute the reciprocal of the number\n");
		printf("(5) Add another complex number\n");
		printf("(6) Substract another complex number\n");
		printf("(7) Multiply by another complex number\n");
		printf("(8) Divide by another complex number\n");
		printf("(9) \"Rotate\" the number by N degrees counterclockwise\n");
		printf("(10) Exit\n\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		
		if (choice == 10)
		{
			break;
		}
		switch (choice)
		{
			case 1:
			{
				printf("\nEnter the real part: ");
				scanf("%lf", &a);
				printf("Enter the imaginary part: ");
				scanf("%lf", &b);
				break;
			}
			case 2:
			{
				printf("\nEnter the magnitude: ");
				scanf("%lf", &r);
				printf("Enter the phase: ");
				scanf("%lf", &theta);
				a = r * cos(theta/180*3.1415926);
				b = r * sin(theta/180*3.1415926);
				break;
			}
			case 3:
			{
				printf("\nThe absolute value of the current number is %.3f", r);
				break;
			}
			case 4:
			{
				x = a;
				y = b;
				if ((x*x)+(y*y) == 0)
				{
					printf("\nError! The selected reciprocal operation cannot be performed!");
					break;
				}
				a = rcprclx(x,y);
				b = rcprcly(x,y);	
				break;
			}
			case 5:
			{
				printf("\nEnter the real part of the operand: ");
				scanf("%lf", &x);
				printf("Enter the imagniary part of the operand: ");
				scanf("%lf", &y);
				a += x;
				b += y;
				break;
			}
			case 6:
			{
				printf("\nEnter the real part of the operand: ");
				scanf("%lf", &x);
				printf("Enter the imagniary part of the operand: ");
				scanf("%lf", &y);
				a -= x;
				b -= y;
				break;
			}
			case 7:
			{
				printf("\nEnter the real part of the operand: ");
				scanf("%lf", &x);
				printf("Enter the imagniary part of the operand: ");
				scanf("%lf", &y);
				a = multx(a, b, x, y);
				b = multy(a, b, x, y);
				break;
			}
			case 8:
			{
				printf("\nEnter the real part of the operand: ");
				scanf("%lf", &x);
				printf("Enter the imagniary part of the operand: ");
				scanf("%lf", &y);
				if ((x*x)+(y*y) == 0)
				{
					printf("Error! The selected division operation cannot be performed.");
					break;
				}
				a = dividex(a, b, x, y);
				b = dividey(a, b, x, y);	
				break;
			}
			case 9:
			{
				printf("\nEnter the degrees you want to rotate: ");
				scanf("%lf", &x);
				theta += x;
				a = r * cos(theta*3.1415926/180);
				b = r * sin(theta*3.1415926/180);
				break;
			}
			default:
			{
				printf("\nInvalid Input. Try Again!");
				break;
			}
		}
		
	}

	return 0;
}
