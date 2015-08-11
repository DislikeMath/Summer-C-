#include <stdio.h>
//  1 1 2 3 5 8 13 21 34...
int Fibonacci(int n)
{
	if (n == 1)
		return 1;
	else if (n == 2)
		return 1;
	int ret = Fibonacci(n - 1) + Fibonacci(n - 2);
	return ret;
}
int main()
{
	printf("%d\n",Fibonacci(50));

	return 0;
}