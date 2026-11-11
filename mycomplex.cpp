#include <iostream>
#include <cmath>
#include <string>
#include "mycomplex.h"
using namespace std;

Complex::Complex(double a_re, double a_im) : re_(a_re), im_(a_im) {
}

Complex::Complex(const Complex& a_rval)
    : re_(a_rval.re_), im_(a_rval.im_) {
}

Complex::~Complex() {
}

void Complex::set(double a_re, double a_im) {
    re_ = a_re;
    im_ = a_im;
}

Complex::operator double() const {
    return abs();
}

double Complex::abs() const {
    return sqrt(re_ * re_ + im_ * im_);
}

Complex Complex::operator+(const Complex& a_rval) const {
    Complex result;
    result.re_ = re_ + a_rval.re_;
    result.im_ = im_ + a_rval.im_;
    return result;
}

Complex Complex::operator-(const Complex& a_rval) const {
    Complex result;
    result.re_ = re_ - a_rval.re_;
    result.im_ = im_ - a_rval.im_;
    return result;
}

Complex Complex::operator+(const double& a_val) const {
    Complex result;
    result.re_ = re_ + a_val;
    result.im_ = im_;
    return result;
}

Complex Complex::operator-(const double& a_rval) const {
    Complex result(*this);
    result.re_ = re_ - a_rval;
    return result;
}

Complex Complex::operator*(const Complex& a_rval) const {
    Complex result;
    result.re_ = re_ * a_rval.re_ - im_ * a_rval.im_;
    result.im_ = re_ * a_rval.im_ + im_ * a_rval.re_;
    return result;
}

Complex Complex::operator*(const double& a_rval) const {
    Complex result;
    result.re_ = re_ * a_rval;
    result.im_ = im_ * a_rval;
    return result;
}

Complex Complex::operator/(const double& a_rval) const {
    Complex result;
    result.re_ = re_ / a_rval;
    result.im_ = im_ / a_rval;
    return result;
}

Complex& Complex::operator+=(const Complex& a_rval) {
    re_ += a_rval.re_;
    im_ += a_rval.im_;
    return *this;
}

Complex& Complex::operator-=(const Complex& a_rval) {
    re_ -= a_rval.re_;
    im_ -= a_rval.im_;
    return *this;
}

Complex& Complex::operator*=(const Complex& a_rval) {
    double tmp_re = re_;
    re_ = re_ * a_rval.re_ - im_ * a_rval.im_;
    im_ = im_ * a_rval.re_ + tmp_re * a_rval.im_;
    return *this;
}

Complex& Complex::operator+=(const double& a_rval) {
    re_ += a_rval;
    return *this;
}

Complex& Complex::operator-=(const double& a_rval) {
    re_ -= a_rval;
    return *this;
}

Complex& Complex::operator*=(const double& a_rval) {
    re_ *= a_rval;
    im_ *= a_rval;
    return *this;
}

Complex& Complex::operator/=(const double& a_rval) {
    re_ /= a_rval;
    im_ /= a_rval;
    return *this;
}

Complex& Complex::operator=(const Complex& a_rval) {
    re_ = a_rval.re_;
    im_ = a_rval.im_;
    return *this;
}

Complex& Complex::operator=(const double& a_rval) {
    re_ = a_rval;
    im_ = 0.0;
    return *this;
}

istream& operator>>(istream& stream, Complex& a) {
    std::string tmp;
    stream >> a.re_ >> a.im_ >> tmp;
    return stream;
}

ostream& operator<<(ostream& stream, const Complex& a) {
    stream << a.re_;
    if (!(a.im_ < 0)) {
        stream << '+';
    }
    stream << a.im_ << 'i';
    return stream;
}

Complex operator+(const double& a_lval, const Complex& a_rval) {
    Complex result;
    result.re_ = a_lval + a_rval.re_;
    result.im_ = a_rval.im_;
    return result;
}

Complex operator-(const double& a_lval, const Complex& a_rval) {
    Complex result;
    result.re_ = a_lval - a_rval.re_;
    result.im_ = -a_rval.im_;
    return result;
}

Complex operator*(const double& a_lval, const Complex& a) {
    Complex r;
    r.re_ = a_lval * a.re_;
    r.im_ = a_lval * a.im_;
    return r;
}
