/*
* Programmer: Carlos completed: March 14, 2024
*
* Instructor: Book
*
* Description: Compute and display the circle’s area and circumference.
* 
*/

#include <stdio.h>

#define PI 3.14159

int main ()
{
	/* input variables */
	double radius; 			/* radius of a circle */

	/* output variables*/
	double area; 			/* area of a circle */
	double circum; 			/* circumference of a circle */

	/* get inputs*/
	printf("type the radius:");
	scanf("%lf", &radius);

	/* calculate area of the circle */
	area = PI * (radius * radius);

	/* calculate circumference of a circle */
	circum = (2 * PI) * (radius);

	/* show area at screen*/
	printf("\narea: %lf", area);

	/* show circumference at screen*/
	printf( "\ncircumference: %lf\n", circum);



	return 1;
}