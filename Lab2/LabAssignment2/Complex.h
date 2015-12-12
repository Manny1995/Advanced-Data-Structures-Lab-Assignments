//
//  Complex.h
//  LabAssignment2
//
//  Created by Immanuel Amirtharaj and Eric Castronovo on 1/12/15.
//  Copyright (c) 2015 Immanuel Amirtharaj and Eric Castronovo. All rights reserved.
//


#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;


class Complex
{
    // functions and variables that can be accessed by anyone
    public:
    
        // 2 constructors: One is the default constructor which sets the complex number to zero, the other takes in two parameters to create and initialize the complex number
        Complex();
        Complex(double real, double imaginary);

    
        // overlaoding the operators to implement addition, multiplication, input, and output
        friend Complex operator+ (const Complex &left, const Complex &right);
        friend Complex operator* (const Complex &left, const Complex &right);
        friend ostream& operator<<(ostream &out, const Complex complexNumber);
        friend istream& operator>>(istream &in, Complex &complexNumber);

    
        // accessors and mutators for both the real and imaginary components of the class
        double getReal();
        double getImaginary();
        void setReal(double real);
        void setImaginary(double imaginary);
   
    // functions and variables which only accessible to Complex itself.
    private:
        double a;   // a is our represention of the real number
        double b;   // b is our reoresention of the imaginary number
    


};


