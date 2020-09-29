#include <iostream>
#pragma once

using namespace std;

class complex {
public:
	//���캯��
	complex(double r = 0, double i = 0)
		:re(r), im(i)
	{ }//initialization list
	complex& operator +=(const complex&);
	double real() const { return re; }
	double imag() const { return im; }

private:
	double re, im;

	friend complex& __doapl(complex*, const complex&);
};

//��������
inline complex& 
__doapl(complex* ths, const complex& r) {
	ths->re += r.re;//friend ��Ԫ�������Է���ͬ��ʵ����˽�б���
	ths->im += r.im;
	return *ths;
}

//return by reference
inline complex& 
complex::operator += (const complex& r) {
	return __doapl(this, r);
}

//return by value
inline complex 
operator + (const complex& x, const complex& y) {
	return complex( x.real () + y.real (),
		            x.imag () + y.imag () );
}

inline complex
operator + (const complex& x, double y) {
	return complex(x.real() + y,x.imag());
}

inline complex
operator + (double x, const complex& y) {
	return complex(x + y.real(), y.imag());
}

ostream& operator << (ostream& os, const complex& x) {
	os << '(' << x.real() << ',' << ')' << x.imag() << endl;
}