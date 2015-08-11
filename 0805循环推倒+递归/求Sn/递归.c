#include <stdio.h>

// Sn = a + a * a + a * a * a + ... + a * a * ... * a;	// n ¸öÏî
//    = a(1 + a + a * a + ... + a * a * ... * a)
//	  = a(1 + a(1 + a+ ... + a * a .. *a))
//    = a(1 + a(a + a(1 + .. + a * a .. a)))
// Sn = a + a * a + a * a * a 
//	  = a(1 + a + a * a)
//	  = a(1 + a(1 + a))
int Sn(int n, int a)
{
	if (n == 1)
		return a;
	else
	{
		return (Sn(n - 1, a)*a + a);
	}
}
int main()
{
	int n, a;
	scanf("%d %d", &n, &a);
	printf("%d", Sn(n, a));
	return 0;
}