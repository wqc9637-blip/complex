#ifndef MY_COMPLEX_H_INCLUDED
#define MY_COMPLEX_H_INCLUDED
#include <iostream>
class Complex {
    double re_;
    double im_;
public:
    Complex(double aRe = 0, double aIm = 0);
    Complex(const Complex&);
    ~Complex();
    void set(double aRe, double aIm = 0);
    operator double();
    double abs();
    friend std::istream& operator>>(std::istream&, Complex&);
    friend std::ostream& operator<<(std::ostream&, Complex&);
    Complex operator+(const Complex&);
    Complex operator-(const Complex&);
    Complex operator+(const double&);
    friend Complex operator+(const double&, const Complex&);
    Complex operator-(const double&);
    friend Complex operator-(const double&, const Complex&);
    Complex operator*(const Complex&);
    Complex operator*(const double&);
    friend Complex operator*(const double&, const Complex&);
    Complex operator/(const double&);
    Complex& operator+=(const Complex&);
    Complex& operator-=(const Complex&);
    Complex& operator*=(const Complex&);
    Complex& operator+=(const double&);
    Complex& operator-=(const double&);
    Complex& operator*=(const double&);
    Complex& operator/=(const double&);
    Complex& operator=(const Complex&);
    Complex& operator=(const double&);
};
#endif
