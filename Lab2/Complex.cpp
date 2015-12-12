//
//  Complex.cpp
//  LabAssignment2
//
//  Created by Immanuel Amirtharaj and Eric Castronovo on 1/12/15.
//  Copyright (c) 2015 Immanuel Amirtharaj and Eric Castronovo. All rights reserved.
//

#include "Complex.h"

    Complex::Complex()
    {
        a = b = 0;
    }

    Complex::Complex(double real, double imaginary)
    {
        a = real;
        b = imaginary;
    }

    // Setter and getter functions for the components of the complex number

    double Complex::getReal()
    {
        return a;
    }

    double Complex::getImaginary()
    {
        return b;
    }
    
    void Complex::setReal(double real)
    {
        a = real;
    }
    
    void Complex::setImaginary(double imaginary)
    {
        b = imaginary;
    }

// print function, we are overloading the 'istream' function to output a complex number.
ostream& operator<<(ostream &out, const Complex complexNumber)
{
    out << complexNumber.a << '+' << complexNumber.b << '*' << 'i';
    return out;
}

//we are overloading the 'ostream' function to take in a complex number. To ignore the '+' or '-' that appears before the complex number.
istream& operator>>(istream &in, Complex &complexNumber)
{
    double real;
    double imaginary;
    
    char buffer;
    in>>real;
    in>>buffer;
    
    if (buffer == '+')
    {
        
            in>>imaginary;
    }
    
    else
    {
        in.unget();
        //b = 1;
    }
    
    complexNumber.a = real;
    complexNumber.b = imaginary;
    
    return in;
}
// overloads the '+' opperator to allow the addition of complex numbers
Complex operator+ (const Complex &left, const Complex &right)
{
    Complex result;
    
    double real = left.a + right.a;
    double imaginary = left.b + right.b;
    
    
    result.a = real;
    result.b = imaginary;
    
    return result;
}
// overloads the '*' opperator to allow the multiplication of complex numbers
Complex operator* (const Complex &left, const Complex &right)
{
    Complex result;
    
    double real = (left.a * right.a - left.b * right.b);
    double imaginary = (left.a * right.b + left.b * right.a);
    
    result.a = real;
    result.b = imaginary;
    
    return result;
}