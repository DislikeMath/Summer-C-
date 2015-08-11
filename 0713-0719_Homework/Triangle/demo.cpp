#include <iostream>
#include "IsoscelesTriangle.h"
#include <cmath>
using namespace std;

int main()
{
	CIsoscelesTriangle a(3, 5, 5);
	double ha = 0, hb = 0, hc = 0;
	double ma = 0, mb = 0, mc = 0;
	cout << "<A: " << static_cast<int>(a.GetAngelA() + 0.5) << endl;
	cout << "<B: " << static_cast<int>(a.GetAngelB() + 0.5) << endl;
	cout << "<C: " << static_cast<int>(a.GetAngelC() + 0.5) << endl;
	cout << "Area: " << a.GetArea() << endl;
	cout << "<Perimeter: " << a.GetPerimeter() << endl;
	a.GetMedian(ma, mb, mc);
	a.GetAltitude(ha, hb, hc);
	cout << "ma = " << ma << "mb = " << mb << "mc = " << mc << endl;
	cout << "ha = " << ha << "hb = " << hb << "hc = " << hc << endl;

	return 0;
}