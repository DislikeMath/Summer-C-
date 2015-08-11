#include <stdio.h>

// Sn = a + a * a + a * a * a + ... + a * a * ... * a;	// n ¸öÏî
//    = a(1 + a + a * a + ... + a * a * ... * a)
//	  = a(1 + a(1 + a+ ... + a * a .. *a))
//    = a(1 + a(a + a(1 + .. + a * a .. a)))
// Sn = a + a * a + a * a * a 
//	  = a(1 + a + a * a)
//	  = a(1 + a(1 + a))
int main()
{
	int a, n;
	int i;
	int sum = 0;
	scanf("%d %d", &n, &a);
	for (i = 0; i < n; i++)
	{
		sum = a*(1 + sum);
	}
	printf("%d", sum);

	return 0;
}
