#include <iostream>
#include <cmath>
#include "mycomplex.h"
using namespace std;

Complex::Complex(double aRe, double aIm) {
    re_ = aRe;
    im_ = aIm;
}

Complex::Complex(const Complex& aRval) {
    re_ = aRval.re_;
    im_ = aRval.im_;
}

Complex::~Complex() {
    re_ = 0.0;
    im_ = 0.0;
}

void Complex::set(double aRe, double aIm) {
    re_ = aRe;
    im_ = aIm;
}

Complex::operator double() {
    return abs();
}

double Complex::abs() {
    return sqrt(re_ * re_ + im_ * im_);
}

Complex Complex::operator+(const Complex& aRval) {
    Complex Result;
    Result.re_ = re_ + aRval.re_;
    Result.im_ = im_ + aRval.im_;
    return Result;
}

Complex Complex::operator-(const Complex& aRval) {
    Complex Result;
    Result.re_ = re_ - aRval.re_;
    Result.im_ = im_ - aRval.im_;
    return Result;
}

Complex Complex::operator+(const double& aval) {
    Complex result;
    result.re_ = re_ + aval;
    result.im_ = im_;
    return result;
}

Complex Complex::operator-(const double& aRval) {
    Complex Result(*this);
    Result.re_ = re_ - aRval;
    return Result;
}

Complex Complex::operator*(const Complex& aRval) {
    Complex Result;
    Result.re_ = re_ * aRval.re_ - im_ * aRval.im_;
    Result.im_ = re_ * aRval.im_ + im_ * aRval.re_;
    return Result;
}

Complex Complex::operator*(const double& aRval) {
    Complex Result;
    Result.re_ = re_ * aRval;
    Result.im_ = im_ * aRval;
    return Result;
}

Complex Complex::operator/(const double& aRval) {
    Complex Result;
    Result.re_ = re_ / aRval;
    Result.im_ = im_ / aRval;
    return Result;
}

Complex& Complex::operator+=(const Complex& aRval) {
    re_ += aRval.re_;
    im_ += aRval.im_;
    return *this;
}

Complex& Complex::operator-=(const Complex& aRval) {
    re_ -= aRval.re_;
    im_ -= aRval.im_;
    return *this;
}

Complex& Complex::operator*=(const Complex& aRval) {
    double tmpRe = re_;
    re_ = re_ * aRval.re_ - im_ * aRval.im_;
    im_ = im_ * aRval.re_ + tmpRe * aRval.im_;
    return *this;
}

Complex& Complex::operator+=(const double& aRval) {
    re_ += aRval;
    return *this;
}

Complex& Complex::operator-=(const double& aRval) {
    re_ -= aRval;
    return *this;
}

Complex& Complex::operator*=(const double& aRval) {
    re_ *= aRval;
    im_ *= aRval;
    return *this;
}

Complex& Complex::operator/=(const double& aRval) {
    re_ /= aRval;
    im_ /= aRval;
    return *this;
}

Complex& Complex::operator=(const Complex& aRval) {
    re_ = aRval.re_;
    im_ = aRval.im_;
    return *this;
}

Complex& Complex::operator=(const double& aRval) {
    re_ = aRval;
    im_ = 0.0;
    return *this;
}

istream& operator>>(istream& stream, Complex& a) {
    char tmp[256];
    stream >> a.re_ >> a.im_ >> tmp;
    return stream;
}

ostream& operator<<(ostream& stream, Complex& a) {
    stream << a.re_;
    if (!(a.im_ < 0)) {
        stream << '+';
    }
    stream << a.im_ << 'i';
    return stream;
}

Complex operator+(const double& aLval, const Complex& aRval) {
    Complex Result;
    Result.re_ = aLval + aRval.re_;
    Result.im_ = aRval.im_;
    return Result;
}

Complex operator-(const double& aLval, const Complex& aRval) {
    Complex Result;
    Result.re_ = aLval - aRval.re_;
    Result.im_ = -aRval.im_;
    return Result;
}

Complex operator*(const double& aLval, const Complex& a) {
    Complex r;
    r.re_ = aLval * a.re_;
    r.im_ = aLval * a.im_;
    return r;
}
