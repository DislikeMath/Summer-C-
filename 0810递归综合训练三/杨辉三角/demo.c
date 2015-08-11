#include <stdio.h>


int func(int i, int j)
{
	if (j == 1 || i == j)
	{
		return 1;
	}
	int ret = func(i - 1, j - 1) + func(i - 1, j);
	return ret;
}

int main()
{
	int i, j, k ,n;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		for (k = n - i; k >= 0; k--)
			printf(" ");
		for (j = 1; j <= i; j++)
		{
	
			printf("%d ", func(i,j));
		}
		printf("\n");
	}
	//printf("%d\n", func(1, 1));
	//printf("%d\n", func(2, 1));
	//printf("%d\n", func(2, 2));
	return 0;
}