#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#define MAX_SZIE 10

BOOL SetConsoleColor(WORD wAttributes)
{

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hConsole == INVALID_HANDLE_VALUE)
		return FALSE;
	BOOL bResult = SetConsoleTextAttribute(hConsole, wAttributes);
	//CloseHandle(hConsole);
	return bResult;
}

void Print(int *pArray, int n)
{
	
	int i;
	for (i = 0; i < n; i++)
	{
		if (i % 2)
			SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN |FOREGROUND_INTENSITY);
		else
			SetConsoleColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		printf("%d ", pArray[i]);
	}
	printf("\n");
	printf("┲▒▒▒▒▓▓▉▉██▆▆▇▇▇██\n");
}

void InsertSort(int *pArray, int n)
{
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &pArray[i]);
		// 先找位置
		for (j = 0; j < i; j++)
		{
			if (pArray[i] < pArray[j])
				break;
		}
		// 缓存输入的数
		int t = pArray[i];
		// 再移动 为位置腾出空间
		for (k = i; k > j; k--)
			pArray[k] = pArray[k - 1];
		pArray[k] = t;
	}
}

int main()
{
	int array[MAX_SZIE];
	InsertSort(array, MAX_SZIE);
	Print(array, MAX_SZIE);
	return 0;
}