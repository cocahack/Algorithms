#include<stdio.h>
const double PIE = 3.14159265358979;
int main()
{
	int r;
	scanf("%d", &r);
	printf("%6f\n", r*r*PIE);
	printf("%6f\n", (double)r*r*2);
	return 0;
}