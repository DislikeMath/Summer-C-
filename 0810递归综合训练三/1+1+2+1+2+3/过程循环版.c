#include <stdio.h>

// 1 + (1 + 2) + (1 + 2 + 3) +...+ ( 1 + 2 + 3 + .. +n)

int work2(int n)
{
	int i, j;
	int total = 0, sum = 0;
	for (i = 1; i <= n; i++)
	{
		sum = 0;
		for (j = 1; j <= i; j++)
		{
			sum += j;
			if (j == n)
				printf("%d ", j);
			else
				printf("%d + ", j);
		}
		total += sum;
	}
	printf("= %d\n", total);
	return total;
}


int main2()
{
	int num;
	while(scanf("%d", &num))
		work2(num);

	return 0;
}