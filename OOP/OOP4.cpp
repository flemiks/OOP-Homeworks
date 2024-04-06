// OOP.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstring>
#include <functional>
#include <iomanip>

#include <iostream>
using namespace std;


//--------------Task1---------------------
/*
class Fraction {
private:
    int numerator;
    int denominator;
public:

    Fraction(int numerator =1, int denominator =1) : numerator(numerator), denominator(denominator) {
        if (denominator == 0) {
            throw std::invalid_argument("Denominator should not be equal 0");
        }
    }

    void set(int numerator, int denominator) {
        if (denominator != 0) {
            this->numerator = numerator;
            this->denominator = denominator;
        }
        else {
            throw std::invalid_argument("Denominator should not be equal 0");
        }
    }

    int getNumerator() {
        return numerator;
    }
    int getDenominator() {
        return denominator;
    }

    friend Fraction operator*(const Fraction& f1, const Fraction& f2);
    friend Fraction operator*(const Fraction& f1, int value);
    friend Fraction operator*(int value, const Fraction& f1);

    friend Fraction operator/(const Fraction& f1, const Fraction& f2);
    friend Fraction operator/(const Fraction& f1, int value);
    friend Fraction operator/(int value, const Fraction& f1);

    friend Fraction operator+(const Fraction& f1, const Fraction& f2);
    friend Fraction operator+(const Fraction& f1, int value);
    friend Fraction operator+(int value, const Fraction& f1);

    friend Fraction operator-(const Fraction& f1, const Fraction& f2);
    friend Fraction operator-(const Fraction& f1, int value);
    friend Fraction operator-(int value, const Fraction& f1);
};
    
Fraction operator*(const Fraction& f1, const Fraction& f2) {
    return Fraction(f1.numerator * f2.numerator, f1.denominator * f2.denominator);
}
 Fraction operator*(const Fraction& f, int value) {
    return Fraction(f.numerator * value, f.denominator);
}
 Fraction operator*(int value, const Fraction& f) {
     return f * value;
 }

 Fraction operator/(const Fraction& f1, const Fraction& f2) {
     if (f2.numerator == 0) {
         throw std::invalid_argument("Denominator should not be equal 0");
     }
     return Fraction(f1.numerator / f2.numerator, f1.denominator / f2.denominator);
 }
 Fraction operator/(const Fraction& f, int value) {
     if (f.numerator == 0) {
         throw std::invalid_argument("Denominator should not be equal 0");
     }
     return Fraction(f.numerator / value, f.denominator);
 }
 Fraction operator/(int value, const Fraction& f) {
     return f / value;
 }


 Fraction operator+(const Fraction& f1, const Fraction& f2) {
     return Fraction(f1.numerator + f2.numerator, f1.denominator + f2.denominator);
 }
 Fraction operator+(const Fraction& f, int value) {
     return Fraction(f.numerator + value, f.denominator);
 }
 Fraction operator+(int value, const Fraction& f) {
     return f + value;
 }

 Fraction operator-(const Fraction& f1, const Fraction& f2) {
     return Fraction(f1.numerator - f2.numerator, f1.denominator - f2.denominator);
 }
 Fraction operator-(const Fraction& f, int value) {
     return Fraction(f.numerator - value, f.denominator);
 }
 Fraction operator-(int value, const Fraction& f) {
     return f - value;
 }


class ComplexNumber {
private:
    double real;
    double imag;

public:
    ComplexNumber(double real = 0.0, double imag = 0.0) : real(real), imag(imag) {}

    void set(double real, double imag) {
        this->real = real;
        this->imag = imag;
    }

    double getReal() const {
        return real;
    }
    double getImag() const {
        return imag;
    }

    friend ComplexNumber operator+(const ComplexNumber& c1, const ComplexNumber& c2) {
        return ComplexNumber(c1.real + c2.real, c1.imag + c2.imag);
    }

    friend ComplexNumber operator-(const ComplexNumber& c1, const ComplexNumber& c2) {
        return ComplexNumber(c1.real - c2.real, c1.imag - c2.imag);
    }

    friend ComplexNumber operator*(const ComplexNumber& c1, const ComplexNumber& c2) {
        double realPart = c1.real * c2.real - c1.imag * c2.imag;
        double imagPart = c1.real * c2.imag + c1.imag * c2.real;
        return ComplexNumber(realPart, imagPart);
    }

    friend ComplexNumber operator/(const ComplexNumber& c1, const ComplexNumber& c2) {
        double denominator = c2.real * c2.real + c2.imag * c2.imag;
        if (denominator == 0) {
            throw std::invalid_argument("Division by zero is not allowed.");
        }
        double realPart = (c1.real * c2.real + c1.imag * c2.imag) / denominator;
        double imagPart = (c1.imag * c2.real - c1.real * c2.imag) / denominator;
        return ComplexNumber(realPart, imagPart);
    }
};*/

  /*
int main()
{   
    //--------------Task1---------------------
  
    Fraction fraction1{};
    Fraction fraction2{};
    fraction1.set(5, 8);
    fraction2.set(3, 5);

    Fraction fraction3 = fraction1 * fraction2;
    Fraction fraction4 = fraction1 / fraction2;
    Fraction fraction5 = fraction1 + fraction2;
    Fraction fraction6 = fraction1 - fraction2;

    cout << "Multiplication " << fraction3.getNumerator() << " / " << fraction3.getDenominator() << endl;
    cout << "Division " << fraction4.getNumerator() << " / " << fraction4.getDenominator() << endl;
    cout << "Addition " << fraction5.getNumerator() << " / " << fraction5.getDenominator() << endl;
    cout << "Substruction " << fraction6.getNumerator() << " / " << fraction6.getDenominator() << endl;


//--------------Task2---------------------
    ComplexNumber c1(2, 3);
    ComplexNumber c2(1, 7);

    ComplexNumber sum = c1 + c2;
    ComplexNumber difference = c1 - c2;
    ComplexNumber product = c1 * c2;
    ComplexNumber quotient = c1 / c2;

    cout << "Sum: " << sum.getReal() << " + " << sum.getImag() << "i" << endl;
    cout << "Difference: " << difference.getReal() << " + " << difference.getImag() << "i" << endl;
    cout << "Product: " << product.getReal() << " + " << product.getImag() << "i" << endl;
    cout << "Quotient: " << quotient.getReal() << " + " << quotient.getImag() << "i" << endl;

    return 0;
}
*/

