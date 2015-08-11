#include <stdio.h>
#include <math.h>
#define MAX_SIZE  30
//  1 1 2 3 5 8 13 21 34...
//  sqrt(5)+1/2
int main()
{
	int i;
	long long num = 1;
	const double q = (sqrt(5) + 1.0) / 2;
	printf("%d %d ", 1, 1);
	for (i = 3; i < MAX_SIZE; i++)
	{
		num = (long long)(num*q + 0.5);
		printf("%ld ", num);
		
	}
	return 0;
}