#ifndef EVALUATABLE_H
#define EVALUATABLE_H

#include "stack.h"

class ComplexNumber;

class Evaluatable {
public:
    virtual void evaluate(Stack<ComplexNumber>& operands_) const = 0;
    ~Evaluatable() = default;
};

#endif // EVALUATABLE_H
