#include <stdio.h>
#define  MAX_SIZE 50

int data[MAX_SIZE];
int cnt = 0;
void print(int n)
{
	int i;
	printf("No.%d :", ++cnt);
	for (i = 0; i < n; i++)
		printf("%d ", data[i]);
	printf("\n");
}

void Devision(int n)
{
	int i;
	int temp = data[n - 1];
	print(n);
	// 必须升序 保证不重复，因此从上一个元素开始循环
	for (i = data[n-2]; i < temp; i++)
	{
		data[n - 1] = i;
		data[n] = temp - i;
		Devision(n + 1);
	}
}

void work(int n)
{
	int i;
	for (i = 1; i <= n / 2; i++)
	{
		data[0] = i;
		data[1] = n - i;
		Devision(2);
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	work(n);

	return 0;
}