#ifndef MY_COMPLEX_H_INCLUDED
#define MY_COMPLEX_H_INCLUDED
#include <iostream>
class Complex {
    double re_;
    double im_;
public:
    explicit Complex(double a_re = 0, double a_im = 0);
    Complex(const Complex&);
    ~Complex();
    void set(double a_re, double a_im = 0);
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
