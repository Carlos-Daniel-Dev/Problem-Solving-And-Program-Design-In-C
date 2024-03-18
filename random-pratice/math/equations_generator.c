#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define MIN_NUM -10
#define MAX_NUM  10
#define EQUATION_STRING_SIZE 27

int random_int(int min, int max) 
{
    return min + rand() % (max - min + 1);
}

char* generate_quadratic_standard_equation()
{
 	srand(time(NULL));
	int a, b, c;

	do {
		a = random_int(MIN_NUM, MAX_NUM);
	} while(a == 0);

	b = random_int(MIN_NUM, MAX_NUM);
	c = random_int(MIN_NUM, MAX_NUM);

	char* equation = malloc(sizeof(char) * EQUATION_STRING_SIZE);
	sprintf(equation, "%dx^2 + %dx + %d = 0\n", a, b, c);

	return equation;

}

double solve_quadratic_standard_equation(int a, int b, int c)
{
	double x = (-(b + sqrt( (b*b) - 4*a*c))) / (2*a);

	return x;
}

int main ()
{
	// char* equation = generate_standard_equation();
	// printf("Equation: %s", equation);

	double result = solve_quadratic_standard_equation(1, 5, 6);

	printf("%f", result);
	return 1;
}