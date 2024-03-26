/*
* Programmer: Carlos completed: March 26, 2024
*
* Instructor: Book
*
* Description: computes the weight of a specified quantity of flat washers
* 
*/
#include <stdio.h>

#define PI 3.14159


int main ()
{
	/* Inputs variables*/
	double hole_diameter; 	/* diameter of hole */
	double edge_diameter; 	/* diameter of outer edge */
	double thickness; 		/* thickness of washer */
	double density; 			/* density of material used */
	double quantity;			/* number of washers made */

	/* output variables */
	double wieght; /* wieght of batch of washers */

	/* program variables */
	double hole_radius; 	/* radius of hole */
	double edge_radius;		/* radius of outer edge */
	double rim_area;		/* area of rim */
	double unit_weight;		/* weight of 1 washer */
	

	/* get inputs */
	printf("hole diameter: ");
	scanf("%lf", &hole_diameter);

	printf("\nedge diameter: ");
	scanf("%lf", &edge_diameter);

	printf("\nthickness: ");
	scanf("%lf", &thickness);

	printf("\ndensity: ");
	scanf("%lf", &density);

	printf("\nquantity: ");
	scanf("%lf", &quantity);

	/* get radius */
	hole_radius = (hole_diameter / 2.0);
	edge_radius = (edge_diameter / 2.0);

	/* get area */
	double hole_area = (PI) * (hole_radius * hole_radius);
	double edge_area = (PI) * (edge_diameter * edge_diameter);
	rim_area = (edge_area - hole_area);

	/* get weight*/
	unit_weight = (rim_area * thickness * density);
	wieght = unit_weight * quantity;

	printf("weight: %.2f", wieght);



	return 1;
}