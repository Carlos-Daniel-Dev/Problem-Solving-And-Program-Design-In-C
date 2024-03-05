#include <stdio.h>

#define KMS_PER_MILE 1.609

double kilometers_to_miles(double kilometers)
{
	return kilometers / KMS_PER_MILE;
}

int main ()
{
	double kilometers;

	scanf("%lf", &kilometers);

	double miles = kilometers_to_miles(kilometers);

	printf("%f\n", miles);
	return 1;
}