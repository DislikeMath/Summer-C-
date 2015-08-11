#include <stdio.h>

// 1 + (1 + 2) + (1 + 2 + 3) +...+ ( 1 + 2 + 3 + .. +n)

int work1(int n)
{
	int i;
	int total = 0, sum = 0;
	for (i = 1; i <= n; i++)
	{
		sum = (1 + i)*i / 2;
		total += sum;
	}
	return total;
}

int main1()
{
	int num = 0;
	scanf("%d", &num);
	printf("%d\n", work1(num));
	return 0;
}