#include <iostream>
#include <string>
#define ADD(x,y) (x+y)
using namespace std;

int add(int a, int b)
{
	return a + b;
}

double add(double a, double b)
{
	return a + b;
}

string add(string a, string b)
{
	return a + b;
}


int main()
{
	cout << add(1, 2) << endl;
	cout << ADD(1, 2) << endl;
	cout << add(1.2, 2.0) << endl;
	cout << ADD(1.2, 2.0) << endl;
	cout << add("Hello", " World") << endl;

	return 0;
}