#include <stdio.h>

void input(int n, int *p)
{
	if (n == 1)
		scanf("%d", &p[n-1]);
	else
	{
		input(n - 1,p);
		scanf("%d", &p[n - 1]);
	}
}

void print(int *p, int n)
{
	if (n == 1)
		printf("%d ", p[n - 1]);
	else
	{
		print(p, n - 1);
		printf("%d ", p[n - 1]);
	}
}

int main()
{
	int array[10] = { 0 };
	input(10, array);
	print(array, 10);

	return 0;
}