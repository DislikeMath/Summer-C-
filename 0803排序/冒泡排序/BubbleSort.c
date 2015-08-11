#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 10

void Init(int *pAarray, int n)
{
	int i;
	for (i = 0; i < n; i++)
		scanf("%d", &pAarray[i]);
}

void BubbleSort(int *pArr, int n)
{
	int flag = 1;
	int i, j;
	for (i = 0; i < n - 1 && flag; i++)
	{
		flag = 0;
		for (j = n - 2; j >= i; j--)
		{
			if (pArr[j] > pArr[j + 1])
			{
				int t = pArr[j];
				pArr[j] = pArr[j + 1];
				pArr[j + 1] = t;
				flag = 1;
			}
		}
	}
}

int main()
{
	int i;
	int arr[MAX_SIZE];
	Init(arr, MAX_SIZE);
	BubbleSort(arr, MAX_SIZE);
	for (i = 0; i < MAX_SIZE; i++)
		printf("%d ", arr[i]);
	return 0;
}
