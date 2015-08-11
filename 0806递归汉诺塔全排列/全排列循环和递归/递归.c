#include <stdio.h>
#define MAX_SIZE 10

int cnt = 0;
char array[MAX_SIZE] = { 0 };

int Init(char *p)
{
	int i, n;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		p[i] = 'A' + i;
	return n;
}

int judge(int index)
{
	int i;
	//printf("%d\n", index);
	for (i = 0; i < index; i++)
	{
		if (array[index] == array[i])
			return 0;
	}
	return 1;
}

// 循环改递归
// 模拟法，一位一位的试，从最高位到最低位填充，无冲突就填充下一位。
void work(int index, int n)
{
	if (index == n)
	{
		++cnt;
		printf("%s\n", array);
		return;
	}
	int i;
	for (i = 0; i < n; i++)
	{	
		array[index] = 'A' + i;
		if (judge(index))
		{	
			work(index + 1, n);
		}
	}
}

int main()
{
	int n = 0;

	n = Init(array);
	work(0, n);
	printf("%d\n", cnt);

	return 0;
}