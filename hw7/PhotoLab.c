/*********************************************************************/
/* PhotoLab.c: Assignment 7 for EECS 10, Fall 2019                   */
/* Wonhee Lee														 */
/*********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*** global definitions ***/
#define WIDTH  480		/* image width */
#define HEIGHT 360		/* image height */
#define SLEN    80		/* maximum length of file names */

/*** global variables ***/
int n = 20;

/*** function declarations ***/

/* print a menu */
void PrintMenu(void);

/* read image from a file */
int LoadImage(const char fname[SLEN], unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]);

/* save a processed image */
int SaveImage(const char fname[SLEN], unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]);

/* change a color image to black & white */
void BlackNWhite(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]);

/* reverse image color */
void Negative(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]);

/* flip image horizontally */
void HFlip(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]);

/* mirror image horizontally */
void HMirror(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]);

/* zoom into the image */
void Zoomin(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]);

/* sharpen the image */
void Sharpen(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]);

/* exchange R and G color channels */
void ExRG(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]);

/* add salt-and-pepper noise to image */
void AddNoise(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT], int percentage);

/* add overlay image */
void Overlay(char fname[SLEN], unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]);

/* add a border to the image */
void AddBorder(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT], int r, int g, int b, int bw);

/* Example: aging the photo */
void Aging(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]);

/* Keeps pixel values in bound */
void adjust(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char [WIDTH][HEIGHT], int SR, int SG, int SB, int x, int y);

/* test all functions */
void AutoTest(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]);

int main(void)
{
    /* Two dimensional arrays to hold the current image data, */
    /* one array for each color component.                    */
    unsigned char   R[WIDTH][HEIGHT];
    unsigned char   G[WIDTH][HEIGHT];
    unsigned char   B[WIDTH][HEIGHT];
	int r, g, b, bw;
	int choice = 0;
	char fname[SLEN];
	
	while(1)
	{
		PrintMenu();	
		scanf("%d", &choice);
		
		if(choice == 14)
		{
			break;
		}
		switch(choice)
		{
			case 1:
			{
				printf("Please input the file name to load: ");
				scanf("%79s", fname);
				LoadImage(fname,R,G,B);
				break;
			}
			case 2:
			{	
				printf("Please input the fime name to save: ");
				scanf("%79s", fname);
				SaveImage(fname,R,G,B);
				break;
			}
			case 3:
			{
				BlackNWhite(R, G, B);
				printf("\"Black & White\" Operation is done!\n");
				break;
			}
			case 4:
			{
				Negative(R, G, B);
				printf("\"Negative\" operation is done!\n");
				break;	
			}
			case 5:
			{
				HFlip(R, G, B);
				printf("\"HFlip\" operation is done!\n");
				break;
			}
			case 6:
			{
				HMirror(R, G, B);
				printf("\"HMirror\" operation is done!\n");
				break;
			}
			case 7:
			{
				Zoomin(R, G, B);
				printf("\"Zoom\" operation is done!\n");
				break;
			}
			case 8:
			{
				Sharpen(R, G, B);
				printf("\"Sharpen\" operation is done!\n");
				break;
			}
			case 9:
			{
				ExRG(R, G, B);
				printf("\"Exchange RG\" operation is done!\n");	
				break;
			}
			case 10:
			{
				AddNoise(R, G, B, n);
				printf("\"Add noise\" operation is done!\n");
				break;
			}
			case 11:
			{
				printf("Please input the file name of the second image to load: " );
				scanf("%79s", fname);
				Overlay(fname, R, G, B);
				printf("\"Add Overlay\" operation is done!\n");
			}
			case 12:
			{
				printf("Enter the R value of the border color(0 to 255): ");
				scanf("%d", &r);
				printf("Enter the G value of the border color(0 to 255): ");
				scanf("%d", &g);
				printf("Enter the B value of the border color(0 to 255): ");
				scanf("%d", &b);
				printf("Enter the width of the border: ");
				scanf("%d", &bw);
				AddBorder(R, G, B, r, g, b, bw);
				printf("\"Add Border\" operation is done!\n");
				break;
			}
			case 13:
			{
				AutoTest(R, G, B);
			}
		}
	}

    return 0;
}

/* Print a Menu */
void PrintMenu(void)
{
		printf("----------------------------------------------\n");
		printf(" 1: Load a PPM image						  \n");
		printf(" 2: Save the image in PPM and JPEG format	  \n");
		printf(" 3: Change the color image to black and white \n");
		printf(" 4: Make a negative of the image			  \n");
		printf(" 5: Flip the image horizontally				  \n");
		printf(" 6: Mirror the image horizontally			  \n");
		printf(" 7: Zoom into the image						  \n");
		printf(" 8: Sharpen the image						  \n");
		printf(" 9: Exchange the red and green color channels \n");
		printf("10: Add noise to an image					  \n");
		printf("11: Add overlay to an image					  \n");
		printf("12: Add border to an image					  \n");
		printf("13: Test all functions						  \n");
		printf("14: Exit									  \n");
		printf("----------------------------------------------\n");
		printf("Please make your choice: ");	
}

/* read image from a file */
int LoadImage(const char fname[SLEN], unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
    FILE *File;
    char Type[SLEN];
    int  Width, Height, MaxValue;
    int  x, y;
    char ftype[] = ".ppm";
    char fname_ext[SLEN + sizeof(ftype)];

    strcpy(fname_ext, fname);
    strcat(fname_ext, ftype);

    File = fopen(fname_ext, "r");
    if (!File) {
        printf("\nCannot open file \"%s\" for reading!\n", fname);
        return 1;
    }
    fscanf(File, "%79s", Type);
    if (Type[0] != 'P' || Type[1] != '6' || Type[2] != 0) {
        printf("\nUnsupported file format!\n");
        return 2;
    }
    fscanf(File, "%d", &Width);
    if (Width != WIDTH) {
        printf("\nUnsupported image width %d!\n", Width);
        return 3;
    }
    fscanf(File, "%d", &Height);
    if (Height != HEIGHT) {
        printf("\nUnsupported image height %d!\n", Height);
        return 4;
    }
    fscanf(File, "%d", &MaxValue);
    if (MaxValue != 255) {
        printf("\nUnsupported image maximum value %d!\n", MaxValue);
        return 5;
    }
    if ('\n' != fgetc(File)) {
        printf("\nCarriage return expected!\n");
        return 6;
    }
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            R[x][y] = fgetc(File);
            G[x][y] = fgetc(File);
            B[x][y] = fgetc(File);
        }
    }
    if (ferror(File)) {
        printf("\nFile error while reading from file!\n");
        return 7;
    }
    printf("%s was read successfully!\n", fname_ext);
    fclose(File);
    return 0;
}

/* save a processed image */
int SaveImage(const char fname[SLEN], unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
    FILE *File;
    char ftype[] = ".ppm";
    char fname_ext[SLEN + sizeof(ftype)];
    char SysCmd[SLEN * 5];
    int  x, y;

    strcpy(fname_ext, fname);
    strcat(fname_ext, ftype);

    File = fopen(fname_ext, "w");
    if (!File) {
        printf("\nCannot open file \"%s\" for writing!\n", fname);
        return 1;
    }
    fprintf(File, "P6\n");
    fprintf(File, "%d %d\n", WIDTH, HEIGHT);
    fprintf(File, "255\n");

    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            fputc(R[x][y], File);
            fputc(G[x][y], File);
            fputc(B[x][y], File);
        }
    }

    if (ferror(File)) {
        printf("\nFile error while writing to file!\n");
        return 2;
    }
    fclose(File);
    printf("%s was saved successfully. \n", fname_ext);

    /*
     * rename file to image.ppm, convert it to ~/public_html/<fname>.jpg
     * and make it world readable
     */
    sprintf(SysCmd, "~eecs10/bin/pnmtojpeg.tcsh %s", fname_ext);
    if (system(SysCmd) != 0) {
        printf("\nError while converting to JPG:\nCommand \"%s\" failed!\n", SysCmd);
        return 3;
    }
    printf("%s.jpg was stored for viewing. \n", fname);

    return 0;
}

/* change a color image to black & white */
void BlackNWhite(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
	int x, y, z = 0;
		
	for(y = 0; y < HEIGHT; y++)
	{
		for(x = 0; x < WIDTH; x++)
		{
			z = (R[x][y] + G[x][y] + B[x][y]) / 3;
			R[x][y] = z;
			G[x][y] = z;
			B[x][y] = z;
		}
	}
}

/* reverse image color */
void Negative(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
	int x,y = 0;
	
	for(y = 0; y < HEIGHT; y++)
	{
		for(x = 0; x < WIDTH; x++)
		{
			R[x][y] = 255 - R[x][y];
			G[x][y] = 255 - G[x][y];
			B[x][y] = 255 - B[x][y];
		}
	}
}

/* flip image horizontally */
void HFlip(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
	int x, y = 0;
	int r, g, b = 0;
	for(y = 0; y < HEIGHT; y++)
	{
		for(x = 0; x < WIDTH/2; x++)
		{
			r = R[x][y];
			g = G[x][y];
			b = B[x][y];
			R[x][y] = R[WIDTH-1-x][y];
			G[x][y] = G[WIDTH-1-x][y];
			B[x][y] = B[WIDTH-1-x][y];
			R[WIDTH-1-x][y] = r;
			G[WIDTH-1-x][y] = g;
			B[WIDTH-1-x][y] = b;
		}
	}
}

/* mirror image horizontally */
void HMirror(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
	int x, y = 0;
	for(y = 0; y < HEIGHT; y++)
	{
		for(x = 0; x < WIDTH/2; x++)
		{
			R[WIDTH-x-1][y] = R[x][y];
			G[WIDTH-x-1][y] = G[x][y];
			B[WIDTH-x-1][y] = B[x][y];
		}
	}
}

/* zoom into the image */
void Zoomin(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
	int x, y = 0;
	unsigned char R2[WIDTH][HEIGHT], G2[WIDTH][HEIGHT], B2[WIDTH][HEIGHT];
	
	for(y = 0; y < HEIGHT; y++)
	{
		for(x = 0; x < WIDTH; x++)
		{
			R2[x][y] = R[x][y];
			G2[x][y] = G[x][y];
			B2[x][y] = B[x][y];
		}
	}
	for(y = 0; y < HEIGHT/2; y++)
	{
		for(x = 0; x < WIDTH/2; x++)
		{
			R[2*x][2*y] = R2[120+x][y];
			R[2*x+1][2*y] = R2[120+x][y];
			R[2*x][2*y+1] = R2[120+x][y];
			R[2*x+1][2*y+1] = R2[120+x][y];
			G[2*x][2*y] = G2[120+x][y];
			G[2*x+1][2*y] = G2[120+x][y];
			G[2*x][2*y+1] = G2[120+x][y];
			G[2*x+1][2*y+1] = G2[120+x][y];
			B[2*x][2*y] = B2[120+x][y];
			B[2*x+1][2*y] = B2[120+x][y];
			B[2*x][2*y+1] = B2[120+x][y];
			B[2*x+1][2*y+1] = B2[120+x][y];
		}
	}	
}

/* sharpen the image */
void Sharpen(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
	int x, y = 0;
	unsigned char R2[WIDTH][HEIGHT], G2[WIDTH][HEIGHT], B2[WIDTH][HEIGHT];
	int SR, SG, SB = 0;
	
	for(y = 0; y < HEIGHT; y++)
	{
		for(x = 0; x < WIDTH; x++)
		{
			R2[x][y] = R[x][y];
			G2[x][y] = G[x][y];
			B2[x][y] = B[x][y];
		}
	}
	
	for(y = 1; y < HEIGHT - 1; y++)
	{
		for(x = 1; x < WIDTH - 1; x++)
		{
			SR = 9*R2[x][y] - R2[x-1][y-1] - R2[x][y-1] - R2[x+1][y-1] - R2[x-1][y] - R2[x+1][y] - R2[x-1][y+1] - R2[x][y+1] - R2[x+1][y+1];
			SG = 9*G2[x][y] - G2[x-1][y-1] - G2[x][y-1] - G2[x+1][y-1] - G2[x-1][y] - G2[x+1][y] - G2[x-1][y+1] - G2[x][y+1] - G2[x+1][y+1];
			SB = 9*B2[x][y] - B2[x-1][y-1] - B2[x][y-1] - B2[x+1][y-1] - B2[x-1][y] - B2[x+1][y] - B2[x-1][y+1] - B2[x][y+1] - B2[x+1][y+1];
			adjust(R, G, B, SR, SG, SB, x, y);
		}
	}
}

/* exchange R and G color channels */
void ExRG(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
	int x, y, z = 0;
	for(y = 0; y < HEIGHT; y++)
	{
		for(x = 0; x < WIDTH; x++)
		{
			z = R[x][y];
			R[x][y] = G[x][y];
			G[x][y] = z;
		}
	}
}

/* add salt-and-pepper noise to image */
void AddNoise(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT], int percentage)
{
	int x, y, i = 0;
	int total = 0;
	srand(0);

	total = percentage * WIDTH * HEIGHT / 100;

	for(i = 0; i < total/2; i++) /* changes random point white */
	{
		x = rand() % WIDTH;
		y = rand() % HEIGHT;
		R[x][y] = 255;
		G[x][y] = 255;
		B[x][y] = 255;
	}

	for(i = 0; i < total/2; i++) /* changes random point black */
	{
		x = rand() % WIDTH;
		y = rand() % HEIGHT;
		R[x][y] = 0;
		G[x][y] = 0;
		B[x][y] = 0;
	}
}

/* add overlay image */
void Overlay(char fname[SLEN], unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
	int x, y = 0;
	unsigned char R2[WIDTH][HEIGHT], G2[WIDTH][HEIGHT], B2[WIDTH][HEIGHT];
	LoadImage(fname, R2, G2, B2);
	
	for(y = 0; y < HEIGHT; y++)
	{
		for(x = 0; x < WIDTH; x++)
		{
			if(!(R2[x][y] >= 250 && G2[x][y] >= 250 && B2[x][y] >= 250))
			{
				R[x][y] = R2[x][y];
				G[x][y] = G2[x][y];
				B[x][y] = B2[x][y];
			}
		}
	}
}

/* add a border to the image */
void AddBorder(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT], int r, int g, int b, int bw)
{
	int x, y = 0;
	for(y = 0; y < HEIGHT; y++)
	{
		for (x = 0; x < WIDTH; x++)
		{
			if(x < bw || x > WIDTH - 1 - bw || y < bw || y > HEIGHT - 1 - bw)
			{
				R[x][y] = r;
				G[x][y] = g;
				B[x][y] = b;
			}
		}
	}
}

/* Age the image to make it look like old picture */
void Aging(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
    int x, y;

    for( y = 0; y < HEIGHT; y++ ) 
	{
        for( x = 0; x < WIDTH; x++ ) 
		{
	    	B[x][y] = (R[x][y]+G[x][y]+B[x][y])/5;
            R[x][y] = (unsigned char) (B[x][y]*1.6);
            G[x][y] = (unsigned char) (B[x][y]*1.6);
		}
    }
}

/* Keeps pixel values in bound */
void adjust(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT], int SR, int SG, int SB, int x, int y)
{
	if(SR <= 255 && SR >= 0)
	{
		R[x][y] = SR;
	}
	if(SG <= 255 && SG >= 0)
	{
		G[x][y] = SG;
	}
	if(SB <= 255 && SB >= 0)
	{
		B[x][y] = SB;
	}
	if(SR < 0)
	{
		R[x][y] = 0;
	}
	if(SG < 0)
	{
		G[x][y] = 0;
	}
	if(SB < 0)
	{
		B[x][y] = 0;
	}
	if(SR > 255)
	{
		SR = 255;
	}
	if(SG > 255)
	{
		SG = 255;
	}
	if(SB > 255)
	{
		SB = 255;
	}
}

/* Test all functions */
void AutoTest(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
	int r, g, b, bw;
	char fname[SLEN];

	LoadImage("Iceland", R, G, B);
	BlackNWhite(R, G, B);
	SaveImage("bw", R, G, B);
	printf("BlackNWhite tested!\n\n");

	LoadImage("Iceland", R, G, B);
	Negative(R, G, B);
	SaveImage("negative", R, G, B);
	printf("Negative tested!\n\n");

	LoadImage("Iceland", R, G, B);
	HFlip(R, G, B);
	SaveImage("hflip", R, G, B);
	printf("HFlip tested!\n\n");

	LoadImage("Iceland", R, G, B);
	HMirror(R, G, B);
	SaveImage("hmirror", R, G, B);
	printf("HMirror tested!\n\n");

	LoadImage("Iceland", R, G, B);
	Zoomin(R, G, B);
	SaveImage("zoomin", R, G, B);
	printf("Zoom tested!\n\n");

	LoadImage("Iceland", R, G, B);
	Sharpen(R, G, B);
	SaveImage("sharpen", R, G, B);
	printf("Sharpen tested!\n\n");

	LoadImage("Iceland", R, G, B);
	ExRG(R, G, B);
	SaveImage("xRG", R, G, B);
	printf("ExRG tested!\n\n");

	LoadImage("Iceland", R, G, B);
	AddNoise(R, G, B, n);
	SaveImage("noise", R, G, B);
	printf("AddNoise tested!\n\n");

	LoadImage("Iceland", R, G, B);
	printf("Please input the file name of the second image to load for Overlay testing: " ); 
	scanf("%79s", fname);
	Overlay(fname, R, G, B);
	SaveImage("overlay", R, G, B);
	printf("Overlay tested!\n\n");

	LoadImage("Iceland", R, G, B);
	printf("Enter the R value of the border color(0 to 255) for testing AddBorder: ");
	scanf("%d", &r);
	printf("Enter the G value of the border color(0 to 255) for testing AddBorder: ");
	scanf("%d", &g);
	printf("Enter the B value of the border color(0 to 255) for testing AddBorder: ");
	scanf("%d", &b);
	printf("Enter the width of the border for testing AddBorder: ");
	scanf("%d", &bw);
	AddBorder(R, G, B, r, g, b, bw);
	SaveImage("border", R, G, B);
	printf("AddBorder tested!\n\n");

	LoadImage("Iceland", R, G, B);
	Aging(R, G, B);
	SaveImage("aging", R, G, B);
	printf("Aging tested!\n\n");
}
/* EOF */


