#include "IsoscelesTriangle.h"
#include <iostream>
#include <cmath>
using namespace std;
const double PI = 3.14;

CIsoscelesTriangle::CIsoscelesTriangle(double a, double b, double c)
{
	if (!(a == b || a == c || b == c))
	{
		throw "It's cannot construct an isosceles triangle!";
	}
	if (!(a + b > c) && (a + c) > b && (b + c) > a)
	{
		throw "It's cannot construct a triangle!";
	}

	m_dbA = a;
	m_dbB = b;
	m_dbC = c;
}


double CIsoscelesTriangle::GetArea()
{
	double p = (m_dbA + m_dbB + m_dbC) / 2;
	return sqrt(p*(p - m_dbA)*(p - m_dbB)*(p - m_dbC));
}

double CIsoscelesTriangle::GetPerimeter()
{
	return (m_dbA + m_dbB + m_dbC);
}

double CIsoscelesTriangle::GetAngelA()
{
	double ca = 0;
	ca = (m_dbB*m_dbB + m_dbC*m_dbC - m_dbA*m_dbA) / (2 * m_dbB*m_dbC);
	return acos(ca)*(180/PI);
}

double CIsoscelesTriangle::GetAngelB()
{
	double cb = 0; 
	cb = (m_dbA*m_dbA + m_dbC*m_dbC - m_dbB*m_dbB) /( 2 * m_dbA*m_dbC);
	return acos(cb)*(180 / PI);
}

double CIsoscelesTriangle::GetAngelC()
{
	double cc = 0;
	cc = (m_dbA*m_dbA + m_dbB*m_dbB - m_dbC*m_dbC) /( 2 * m_dbA*m_dbB);
	return acos(cc)*(180 / PI);
}

double CIsoscelesTriangle::GetAltitude(double &attA, double &attB, double &attC)
{
	double s = GetArea();
	attA = (2 / m_dbA)*s;
	attB = (2 / m_dbB)*s;
	attC = (2 / m_dbC)*s;
	return attA;
}

double CIsoscelesTriangle::GetMedian(double &mA, double &mB, double &mC)
{
	mA = sqrt(0.5*m_dbC*m_dbC + 0.5*m_dbB*m_dbB - 0.25*m_dbA*m_dbA);
	mB = sqrt(0.5*m_dbC*m_dbC + 0.5*m_dbA*m_dbA - 0.25*m_dbB*m_dbB);
	mC = sqrt(0.5*m_dbB*m_dbA + 0.5*m_dbA*m_dbA - 0.25*m_dbC*m_dbC);
	return mA;
}
