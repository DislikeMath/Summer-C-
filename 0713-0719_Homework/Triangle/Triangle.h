#pragma once
// 抽象类 接口
class CTriangle
{
public:
	CTriangle() = default;
	virtual double GetArea() = 0;			// 求面积
	virtual double GetPerimeter() = 0;		// 求周长
	virtual double GetAngelA() = 0;			// 求周角A
	virtual double GetAngelB() = 0;			// 求周角B
	virtual double GetAngelC() = 0;			// 求周角C
	virtual double GetAltitude(double &attA, double &attB, double &attC) = 0;		// 求高线
	virtual double GetMedian(double &mA, double &mB, double &mC) = 0;			// 求中线
};
