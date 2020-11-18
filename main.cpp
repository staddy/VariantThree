#include "mainwindow.h"

#include <QApplication>

#include <memory>
#include <iostream>

#include "complexnumber.h"
#include "operator.h"

int main(int argc, char* argv[]) {
    Stack<ComplexNumber> operands;
    Stack<std::shared_ptr<Evaluatable> > stack;
    stack.push(std::make_shared<ComplexNumber>(25));
    stack.push(std::make_shared<ComplexNumber>(4));
    stack.push(std::make_shared<Operator>('*'));
    stack.push(std::make_shared<ComplexNumber>(10));
    stack.push(std::make_shared<Operator>('+'));
    auto evaluationStack = stack.reversed();
    while (!evaluationStack.empty()) {
        evaluationStack.pop()->evaluate(operands);
    }
    std::cout << operands.pop() << std::endl;
    //QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    //return a.exec();
    return 0;
}
