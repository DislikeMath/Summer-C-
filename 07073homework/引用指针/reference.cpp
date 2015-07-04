#include <iostream>

using namespace std;

int main()
{
	int a = 5;
	int *p = &a;
	int &r = *p;		//不能直接引用一个指针
	int *& ref = p;

	//对于TYPE &r 可以转换为 TYPE * const p
	//但是以后出现的 r 都必须用*p表示

	cout << a << endl;
	cout << p << endl;
	cout << r << endl;
	cout << ref << endl;

	*ref = 3;

	cout << a << endl;
	cout << p << endl;
	cout << r << endl;
	cout << ref << endl;

	return 0;
}