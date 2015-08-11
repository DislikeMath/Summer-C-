#include <stdio.h>

void input(int n, int *p)
{
	if (n == 1)
		scanf("%d", &p[n - 1]);
	else
	{
		input(n - 1, p);
		scanf("%d", &p[n - 1]);
	}
}

int MaxValue(int *p, int n)
{
	if (n == 1)
		return p[n - 1];
	else if (n == 2)
		return p[n - 1] > p[n - 2] ? p[n - 1] : p[n - 1];
	else
	{
		int maxv;
		maxv = MaxValue(p, n-1);
		return p[n - 1] > maxv ? p[n - 1] : maxv;
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

int isRaise(int *p, int n)
{
	if (n == 1)
		return 1;
	else if (n == 2)
		return p[n - 2] < p[n - 1];
	else
		return isRaise(p, n - 1) && p[n - 2] < p[n - 1];
}

int main()
{
	int array[10] = { 0 };
	input(10, array);
	print(array, 10);
	printf("\nmax = %d", MaxValue(array, 10));
	if (isRaise(array, 10))
		printf("\nÊÇÉýÐò");
	else
		printf("\n²»ÊÇÉýÐò");

	return 0;
}