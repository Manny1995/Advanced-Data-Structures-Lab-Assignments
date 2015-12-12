//
//  Complex.h
//  LabAssignment2
//
//  Created by Immanuel Amirtharaj on 1/12/15.
//  Copyright (c) 2015 Immanuel Amirtharaj. All rights reserved.
//

#ifndef __LabAssignment2__Complex__
#define __LabAssignment2__Complex__

#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

class Complex
{
    
    public:
    
        Complex();
        Complex(double real, double imaginary);

    
        friend Complex operator+ (const Complex &left, const Complex &right);
        friend Complex operator* (const Complex &left, const Complex &right);
        friend ostream& operator<<(ostream &out, const Complex complexNumber);
        friend istream& operator>>(istream &in, Complex &complexNumber);


        double getReal();
        double getImaginary();
        void setReal(double real);
        void setImaginary(double imaginary);
    
    private:
        double a;
        double b;
    


};


#endif /* defined(__LabAssignment2__Complex__) */
