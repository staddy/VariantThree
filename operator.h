#ifndef OPERATOR_H
#define OPERATOR_H

#include "evaluatable.h"

class Operator : public Evaluatable {
public:
    enum class Type {
        NONE,
        PLUS,
        MINUS,
        MULTIPLY,
        DIVIDE,
        REAL,
        IMAGINARY,
        ABS,
    };
    Operator() = default;
    Operator(Type t_);
    Operator(char c_);
    Operator(const std::string& s_);
    void evaluate(Stack<ComplexNumber>& operands_) const override;
private:
    Type m_type{Type::NONE};
    Type charToType(char c_);
    Type stringToType(const std::string& s_);
};

#endif // OPERATOR_H
