//
//  Complex.cpp
//  LabAssignment2
//
//  Created by Immanuel Amirtharaj on 1/12/15.
//  Copyright (c) 2015 Immanuel Amirtharaj. All rights reserved.
//

#include "Complex.h"

    // This is the constructor and sets the real and imaginary
    Complex::Complex()
    {
        a = b = 0;
    }
    
    Complex::Complex(double real, double imaginary)
    {
        a = real;
        b = imaginary;
    }
    
    
    // getter functions
    double Complex::getReal()
    {
        return a;
    }
    
    double Complex::getImaginary()
    {
        return b;
    }
    
    // setter functions
    void Complex::setReal(double real)
    {
        a = real;
    }
    
    void Complex::setImaginary(double imaginary)
    {
        b = imaginary;
    }


ostream& operator<<(ostream &out, const Complex complexNumber)
{
    out << complexNumber.a << '+' << complexNumber.b << 'i';
    return out;
}

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
    
    

    
    complexNumber.a = real;
    complexNumber.b = imaginary;
    cout<<complexNumber.b;
    
    return in;
}


Complex operator+ (const Complex &left, const Complex &right)
{
    
    Complex result;
    
    double real = left.a + right.a;
    double imaginary = left.b + right.b;
    
    
    result.a = real;
    result.b = imaginary;
    
    return result;
}

Complex operator* (const Complex &left, const Complex &right)
{
    Complex result;
    
    double real = (left.a * right.a - left.b * right.b);
    double imaginary = (left.a * right.b + left.b * right.a);
    
    result.a = real;
    result.b = imaginary;
    
    return result;
}


