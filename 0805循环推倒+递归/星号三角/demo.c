#include <stdio.h>

int main()
{
	int i, j, k;
	int n;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		for (j = n - i; j > 0; j--)
			printf(" ");
		for (k = 0; k < 2 * i - 1; k++)
			printf("*");
		printf("\n");
	}
	return 0;
}