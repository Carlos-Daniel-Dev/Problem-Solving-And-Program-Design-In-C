/*
* Programmer: Carlos completed: March 26, 2024
*
* Instructor: Book
*
* Description: Draw diagrams from the figure 3.9 in the book
* 
*/

#include <stdio.h>

void draw_intersecting_lines ()
{
	printf("      / \\\n");
	printf("     /   \\\n");
	printf("    /     \\\n");
	printf("   /       \\\n");
	printf("  /         \\\n");
	printf(" /           \\\n");
	printf("/             \\\n");
}

void draw_base_line ()
{
	printf(" - - - - - - - \n");
}

void draw_parallel_lines ()
{
	printf("|             |\n");
}

void draw_circle ()
{
	printf("   *  \n");
	printf(" *   *\n");
	printf("   *  \n");
}

void draw_triangle ()
{
	draw_intersecting_lines();
	draw_base_line();
}

int main ()
{
	
	draw_triangle();
	draw_parallel_lines();
	draw_parallel_lines();
	draw_parallel_lines();
	draw_base_line();
	/*                            */
	draw_circle();
	draw_triangle();
	draw_intersecting_lines();


	return 1;
}