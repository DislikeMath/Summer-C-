#include <iostream>

using namespace std;

int main()
{
	int a = 5;
	int *p = &a;
	int &r = *p;		//����ֱ������һ��ָ��
	int *& ref = p;

	//����TYPE &r ����ת��Ϊ TYPE * const p
	//�����Ժ���ֵ� r ��������*p��ʾ

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