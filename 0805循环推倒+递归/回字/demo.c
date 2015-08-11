#include <stdio.h>
#define  MAX_SIZE 10

void print(int(*p)[MAX_SIZE], int n)
{
	int i, j;
	printf("\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			printf("%3d", p[i][j]);
		printf("\n");
	}
}
int main()
{
	int i = 0, j = 0, n = 0;
	int cnt = 1;
	int flag = 0;
	int data[MAX_SIZE][MAX_SIZE] = { 0 };
	scanf("%d", &n);
	int line = n;
	while (cnt <= (line*line))
	{
		
		for (; j < n; j++)
			data[i][j] = cnt++;
		j--, i++;	//¸´Î»
		for (; i < n; i++)
			data[i][j] = cnt++;
		i--, j--;
		for (; j >= flag; j--)
			data[i][j] = cnt++;
		i--, j++;
		for (; i > flag; i--)
			data[i][j] = cnt++;
		i++, j++;
		flag++;
		n--;
	}

	print(data, line);

	return 0;
}