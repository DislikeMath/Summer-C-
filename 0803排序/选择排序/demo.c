#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define  MAX_SIZE 10

void Init(int *p,int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &p[i]);
	}
}

void SlectSort(int *p, int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		int min_index = i;			// 最小值下标
		for (j = i+1; j < n; j++)
		{
			if (p[j] < p[min_index])
				min_index = j;
		}
		int t = p[i];
		p[i] = p[min_index];
		p[min_index] = t;
	}
}

int main()
{
	int array[MAX_SIZE];
	Init(array, MAX_SIZE);
	SlectSort(array, MAX_SIZE);
	int i;
	for (i = 0; i < MAX_SIZE; i++)
	{
		printf("%d ", array[i]);
	}
}