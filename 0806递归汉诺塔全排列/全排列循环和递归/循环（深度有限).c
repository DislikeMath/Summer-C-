#include <stdio.h>
#define MAX_SIZE 5

void Init(char *p, int n)
{
	int i;
	for (i = 0; i < n; i++)
		p[i] = 'A' + i;
}

int main()
{
	int cnt = 0;
	char array[MAX_SIZE] = { 0 };
	Init(array, MAX_SIZE-1);
	int i, j, k, l;
	for (i = 0; i < MAX_SIZE - 1; i++)
	{
		array[0] = 'A' + i;
		for (j = 0; j < MAX_SIZE - 1; j++)
		{
			if (i == j)
				continue;
			array[1] = 'A' + j;
			for (k = 0; k < MAX_SIZE - 1; k++)
			{
				if (i == k || k == j)
					continue;
				array[2] = 'A' + k;
				for (l = 0; l < MAX_SIZE - 1; l++)
				{
					if (i == l || j == l || k == l)
						continue;
					array[3] = 'A' + l;
					printf("%s\n", array);
					cnt++;
				}
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}