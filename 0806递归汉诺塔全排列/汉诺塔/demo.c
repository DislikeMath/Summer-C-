#include <stdio.h>

// ��Ԫ��n�� ��ʼA  ����B  Ŀ��C
void Tower(int n, int A, int B, int C)
{
	if (n == 1)
		printf("%c -----> %c\n", A, C);
	else
		{
			Tower(n - 1, A, C, B);
			Tower(1, A, B, C);
			Tower(n - 1, B, A, C);
		}
}


int main()
{
	int n;
	scanf("%d", &n);
	Tower(n, 'A', 'B', 'C');

	return 0;
}