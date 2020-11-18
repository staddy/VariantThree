#include "complexnumber.h"

#include <math.h>

ComplexNumber::ComplexNumber(double real_, double imaginary_) :
    m_real{real_}, m_imaginary{imaginary_} { }

double ComplexNumber::real() const {
    return m_real;
}

double ComplexNumber::imaginary() const {
    return m_imaginary;
}

double ComplexNumber::abs() const {
    return std::sqrt(real() * real() + imaginary() * imaginary());
}

void ComplexNumber::evaluate(Stack<ComplexNumber>& operands_) const {
    operands_.push(*this);
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber& other_) const {
    return ComplexNumber(real() + other_.real(), imaginary() + other_.imaginary());
}
ComplexNumber ComplexNumber::operator-(const ComplexNumber& other_) const {
    return ComplexNumber(real() - other_.real(), imaginary() - other_.imaginary());
}
ComplexNumber ComplexNumber::operator*(const ComplexNumber& other_) const {
    return ComplexNumber(real() * other_.real() - imaginary() * other_.imaginary(), real() * other_.imaginary() + imaginary() * other_.real());
}
ComplexNumber ComplexNumber::operator/(const ComplexNumber& other_) const {
    auto tmp = ComplexNumber(other_.real(), -other_.imaginary());
    auto tmp2 = *this * tmp;
    tmp = tmp * other_;
    return ComplexNumber(tmp2.real() / tmp.real(), tmp2.imaginary() / tmp.real());
}

std::ostream& operator<<(std::ostream& stream_, const ComplexNumber& complexNumber_) {
    stream_ << "{" << complexNumber_.real() << "; " << complexNumber_.imaginary() << "}" << std::endl;
}
