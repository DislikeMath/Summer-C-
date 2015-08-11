#include <stdio.h>
#include <string.h>

#define MAX_SZIE 27
#define FALSE 0
#define TRUE 1
char array[MAX_SZIE] = { 0 };
char end[MAX_SZIE] = { 0 };
int Init(char *p)
{
	int i, n;
	scanf("%d", &n);
	for (i = 0; i != n; ++i)
	{
		array[i] = 'A' + i;
		end[i] = 'A' + n - 1 - i;
	}
	return i;
}

int judge(int n)
{
	int i,j;
	for (i = 0; i < n; i++)
	{
		if (array[i] >= 'A' + n)
			return TRUE;
	}
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (array[i] == array[j])
				return TRUE;
		}
	}
	return FALSE;
}

void increase(int index, int n)
{
	if (array[index] >= 'A' + n)
	{
		array[index] = 'A';
		increase(index - 1, n);
	}
	else
		array[index]++;
}
void work(int n)
{
	while (strcmp(array, end))
	{
		if (judge(n))
			increase(n - 1, n);
		else
		{
			printf("%s\n", array);
			increase(n - 1, n);
		}
	}
	printf("%s\n", array);
}

int main()
{
	int n = 0;
	n = Init(array);
	work(n);
	return 0;
}