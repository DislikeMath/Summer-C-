#pragma once
#include "Triangle.h"

//µÈÑüÈý½Ç
class CIsoscelesTriangle :
	public CTriangle
{
public:
	CIsoscelesTriangle(double a = 0, double b = 0, double c = 0);
	virtual double GetArea();
	virtual double GetPerimeter();
	virtual double GetAngelA();
	virtual double GetAngelB();
	virtual double GetAngelC();
	virtual double GetAltitude(double &attA, double &attB, double &attC);
	virtual double GetMedian(double &mA, double &mB, double &mC);
protected:
	double m_dbA, m_dbB, m_dbC;	// Èý±ß
	
};

