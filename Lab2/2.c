
#include <stdio.h>
#include <math.h>

#define _USE_MATH_DEFINES

double z1(double alpha) {
	return ( sin(M_PI / 2 + 3 * alpha) ) / (1 - sin(3 * alpha - M_PI) );
}

double z2(double alpha) {
	return 1 / tan(M_PI * 5 / 4 + alpha * 3 / 2);
}

int main()
{
	double a;
	printf("alpha = ");
	scanf("%lf", &a);

	printf("z1(alpha) = %lf\n", z1(a));
	printf("z2(alpha) = %lf", z2(a));
	
	return 0;
}

