#include <stdio.h>
#include <math.h>

//			1
//		   121
//		  12321
//       1234321
//      123454321
//       1234321
//        12321
//         121
//          1
int main()
{
	int i, j;
	int n;
	scanf("%d", &n);
	for (i = abs(n - 1); abs(i) < n; i--)
	{
		for (j = abs(i); j > 0; j--)
			printf(" ");
		for (j = 1; j <= n - abs(i); j++)
			printf("%d", j);
		for (j = n - abs(i) - 1; j > 0; j--)
			printf("%d", j);
		printf("\n");
	}
	return 0;
}