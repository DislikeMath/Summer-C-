#pragma once
// ������ �ӿ�
class CTriangle
{
public:
	CTriangle() = default;
	virtual double GetArea() = 0;			// �����
	virtual double GetPerimeter() = 0;		// ���ܳ�
	virtual double GetAngelA() = 0;			// ���ܽ�A
	virtual double GetAngelB() = 0;			// ���ܽ�B
	virtual double GetAngelC() = 0;			// ���ܽ�C
	virtual double GetAltitude(double &attA, double &attB, double &attC) = 0;		// �����
	virtual double GetMedian(double &mA, double &mB, double &mC) = 0;			// ������
};
