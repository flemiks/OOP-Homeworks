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

class Fraction {
private:
    int numerator;
    int denominator;
public:

    Fraction() : numerator(1), denominator(1) {}


    void set(int numerator, int denominator) {
        if (denominator != 0) {
            this->numerator = numerator;
            this->denominator = denominator;
        }
        else {
            throw std::invalid_argument("Denominator should not be equal 0");
        }
    }

    Fraction& addition() {
        this ->numerator += denominator;
        return *this;
    }

    Fraction& subtraction() {
        this->numerator -= denominator;
        return *this;
    }

    Fraction& multiplication() {
        this->numerator *= denominator;
        return *this;
    }

    Fraction& division() {
        if (denominator != 0) {
            numerator /= denominator;
        }
        else {
            throw std::invalid_argument("Cannot divide by zero");
        }
        return *this;
    }

    void print() {
        cout << numerator << "/" << denominator << endl;
    }
};



class Ball {
private:
    string color;
    int radius;
public:
    Ball(string color = "Red", int radius = 1) : color(color), radius(radius) {};

    void print() {
        cout << "Color: " << color << "," << "Radius: " << radius << endl;
    }
};

//int main()
{   
    Fraction fraction1{};
    fraction1.set(5, 2);
    fraction1.addition().division().multiplication().subtraction();


    Ball bal_1{ "Red", 2 };
    bal_1.print();
    Ball bal_2{ "Blue" };
    bal_2.print();


}


