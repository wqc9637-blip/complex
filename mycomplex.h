#ifndef MY_COMPLEX_H_INCLUDED
#define MY_COMPLEX_H_INCLUDED
#include <iostream>
class Complex {
    double re_;
    double im_;
public:
    explicit Complex(double aRe = 0, double aIm = 0);
    Complex(const Complex&);
    ~Complex();
    void set(double aRe, double aIm = 0);
    explicit operator double() const;
    double abs() const;
    friend std::istream& operator>>(std::istream&, Complex&);
    friend std::ostream& operator<<(std::ostream&, const Complex&);
    Complex operator+(const Complex&) const;
    Complex operator-(const Complex&) const;
    Complex operator+(const double&) const;
    friend Complex operator+(const double&, const Complex&);
    Complex operator-(const double&) const;
    friend Complex operator-(const double&, const Complex&);
    Complex operator*(const Complex&) const;
    Complex operator*(const double&) const;
    friend Complex operator*(const double&, const Complex&);
    Complex operator/(const double&) const;
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
