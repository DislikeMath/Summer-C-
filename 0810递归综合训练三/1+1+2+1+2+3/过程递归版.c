#include <stdio.h>
// Ç¶Ì×µÝ¹é
// 1 + (1 + 2) + (1 + 2 + 3) +...+ ( 1 + 2 + 3 + .. +n)
int flag = 0;
int GetSum(int len)
{
	if (len == 1)
	{
		if (flag != 0)
			printf(" ( 1 ");
		else
		{
			printf(" 1 ");
			flag = 1;
		}
		return 1;
	}

	int ret = GetSum(len - 1);
	printf("+ %d ", len);
	return ret + len;
}


int GetTotal(int n)
{
	if (n == 1)
	{
		int ret = GetSum(1);
		return ret;
	}
	int res = GetTotal(n - 1);
	if (res != 1)
		printf(") ");
	printf("+");
	return res + GetSum(n);
}

int main()
{
	int num, ret;
	scanf("%d", &num);
	ret = GetTotal(num);
	if (ret != 1)
		printf(") ");
	printf("= %d \n", ret);

	
	return 0;
}