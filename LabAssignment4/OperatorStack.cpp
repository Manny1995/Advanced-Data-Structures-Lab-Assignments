//
//  OperatorStack.cpp
//  LabAssignment4
//
//  Created by Immanuel Amirtharaj and Brian Pingel on 1/26/15.
//  Copyright (c) 2015 Immanuel Amirtharaj and Brian Pingel. All rights reserved.
//

#include "OperatorStack.h"

using namespace std;


// Constructor for the stack, the maximum size is passed in by the user
OperatorStack::OperatorStack(int _MAXCOUNT)
{
    stack = new double [MAXCOUNT];
    MAXCOUNT = _MAXCOUNT;
}

// Destructor for the stack, deallocates the memory for the dynamic array
OperatorStack::~OperatorStack()
{
    delete [] stack;
}

// Adds a new entry to the end of the stack
void OperatorStack::push(double newEntry)
{
    assert(count < MAXCOUNT);
    
    stack[count] = newEntry;
    count++;
}

// removes the last entry entered into the stack
double OperatorStack::pop()
{
    
    assert(count > 0);
    
    double temp = stack[count-1];
    stack[count-1] = NULL;
    count--;
    return temp;
}


