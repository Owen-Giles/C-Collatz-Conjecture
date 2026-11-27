/**********************************************************************/
/* Program:   C Collatz Conjecture                                    */
/* Programer: Owen Giles                                              */
/* Date:      11-26-26                                                */
/* Compile:   gcc 3x+1.c -o 3x+1                                      */
/* Run:       ./3x+1                                                  */
/**********************************************************************/
#include <stdio.h>

/**********************************************************************/
/*                       Function Declarations.                       */
/**********************************************************************/
void header();
char get_choice();
int get_num();

/**********************************************************************/
/*                           Main Function.                           */
/**********************************************************************/
int main()
{
   int x, 
       step = 1,
		 stopingNum;
	
	// Prints program header.
	header();

	// Lets user choose if they want to stop when x=1.
	if(get_choice() == 'y')
	{
		stopingNum = 1;
	}
	else
	{
		// Set to 0 because it should never = 0.
		stopingNum = 0;
	}
	
	// Gets users starting value.
	x = get_num();
	
	// Prints starting value.
	printf("\nStart: %d", x);

	// Loops calculations of Collatz conjecture.
	while(x != stopingNum)
	{
		if(x % 2 == 0)
		{
			x = x / 2;
		}
		else
		{
			x = (3 * x) + 1;
		}

		// Prints calculated values. 
		printf("\n%5d. %d", step++, x);
	}

	// Prints iteration program ended. 
	printf("\nProgram ended on interation %d.", --step);
	printf("\n\n");
}

/**********************************************************************/
/*                    Prints Program Intro Header.                    */
/**********************************************************************/
void header()
{
	// Program header. 
	printf("======================================================");
	printf("\nThis program will calculate Collatz conjecture until");
	printf("\nyour entered value reaches 1 or if you can choose to");
	printf("\ncalculate 4 2 1 over and over.");
	printf("\n======================================================\n");
}

/***********************************************************************/
/*                          Gets User Choice.                          */
/***********************************************************************/
char get_choice()
{
	char choice;

	// User decision if they want to loop forever. 
	printf("\nWould you like to stop calculating when value equals 1?");
	printf("\n(y / n)");
	printf("\nAnswer: ");
	scanf("%c", &choice);

	return choice;
}

/**********************************************************************/
/*                          Gets User Value.                          */
/**********************************************************************/
int get_num()
{
	int x;

	// Gets user starting value and validates value. 
	printf("\nEnter your starting whole positive value: ");
	while(scanf("%d", &x) != 1 || x <= 0)
	{
		printf("\nINVALID VALUE!");
		printf("\nTry again: ");
	}

	return x;
}