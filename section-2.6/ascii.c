#include <stdio.h>

/*
* Programmer: Carlos completed: March 14, 2024
* Instructor: Book
*
* Display the ASCII table on screen
* 
*/

int main() 
{
    for (int i = 0; i<= 127; i++)
    {
    	printf("|dec: %d |char: %c\n", i, (char)i);
    }

    return 0;
}
