/*
* Programmer: Carlos completed: March 26, 2024
*
* Instructor: Book
*
* Description: Calculate the absolute difference beetwen two integers
* 
*/

#include <stdio.h>
#include <stdlib.h>

int get_absolute_difference(int x, int y)
{
	return abs(x) - abs(y);
}

int main ()
{
	int x = -10;
	int y = -5;
	printf("absolute difference beetwen %d and %d is: %d\n", x, y, get_absolute_difference(x, y));

	return 1;
}