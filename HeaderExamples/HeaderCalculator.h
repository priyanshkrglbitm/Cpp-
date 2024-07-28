
#ifndef CALCULATOR_H
#define CALCULATOR_H

// Calculator class declaration
class Calculator {
public:

    Calculator();

    // Member functions for basic arithmetic operations
    double add(double a, double b);
    double subtract(double a, double b);
    double multiply(double a, double b);
    double divide(double a, double b);

    ~Calculator();
};

#endif 
