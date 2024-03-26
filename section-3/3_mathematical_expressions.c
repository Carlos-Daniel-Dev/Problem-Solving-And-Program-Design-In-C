/*
* Programmer: Carlos completed: March 26, 2024
*
* Instructor: Book
*
* Description: Rewrite mathematical expressions using functions
* Parameters to compile: -lm
* 
*/

#include <stdio.h>
#include <math.h>

double function_a(double u, double v, double w)
{
	return sqrt(u + (v * (w * w)));
}

double function_b(double x, double y)
{
	return log(pow(x, y));
}

double function_c(double x, double y)
{
	return sqrt(pow((x - y), 3));
}

double function_d(double x, double y, double w, double z)
{
	return (x * y) - (w / z);
}


int main ()
{	

	return 1;
}