

#include "HeaderCalculator.h"
#include <iostream>
#include <stdexcept>

using namespace std;

Calculator::Calculator() {
    cout << "Calculator initialized." << std::endl;
}

Calculator::~Calculator() {
    cout << "Calculator destroyed." << std::endl;
}

double Calculator::add(double a, double b) {
    return a + b;
}

// Member function to subtract two numbers
double Calculator::subtract(double a, double b) {
    return a - b;
}

// Member function to multiply two numbers
double Calculator::multiply(double a, double b) {
    return a * b;
}

// Member function to divide two numbers
double Calculator::divide(double a, double b) {
    if (b == 0) {
        throw std::runtime_error("Division by zero error!");
    }
    return a / b;
}


int main() {
    Calculator calc; 

    double num1 = 10.5;
    double num2 = 5.0;

    cout << "Addition: " << calc.add(num1, num2) << std::endl;
    cout << "Subtraction: " << calc.subtract(num1, num2) << std::endl;
    cout << "Multiplication: " << calc.multiply(num1, num2) << std::endl;

    try {
        cout << "Division: " << calc.divide(num1, num2) << std::endl;
    } catch (const std::runtime_error& e) {
        cerr << e.what() << endl;
    }

    return 0;
}
