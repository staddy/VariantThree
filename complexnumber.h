#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H

#include "evaluatable.h"
#include "stack.h"

class ComplexNumber : public Evaluatable {
public:
    ComplexNumber() = default;
    ComplexNumber(double real_, double imaginary_ = 0.0);
    double real() const;
    double imaginary() const;
    double abs() const;
    void evaluate(Stack<ComplexNumber>& operands_) const override;
    ComplexNumber operator+(const ComplexNumber& other_) const;
    ComplexNumber operator-(const ComplexNumber& other_) const;
    ComplexNumber operator*(const ComplexNumber& other_) const;
    ComplexNumber operator/(const ComplexNumber& other_) const;
private:
    double m_real{0.0};
    double m_imaginary{0.0};
};

std::ostream& operator<<(std::ostream& stream_, const ComplexNumber& complexNumber_);

#endif // COMPLEXNUMBER_H
