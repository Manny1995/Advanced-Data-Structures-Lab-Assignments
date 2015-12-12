//
//  OperatorStack.h
//  LabAssignment4
//
//  Created by Immanuel Amirtharaj and Brian Pingel on 1/26/15.
//  Copyright (c) 2015 Immanuel Amirtharaj and Brian Pingel. All rights reserved.
//

#ifndef __LabAssignment4__OperatorStack__
#define __LabAssignment4__OperatorStack__

#include <stdio.h>
#include <assert.h>
#include <iostream>

using namespace std;

class OperatorStack
{
    public:

        // Constructor for the stack, the maximum size is passed in by the user
        OperatorStack(int _MAXCOUNT);
    
        // Destructor for the stack, deallocates the memory for the dynamic array
        ~OperatorStack();
    
        // Adds a new entry to the end of the stack
        void push(double newEntry);
    
        // removes the last entry entered into the stack
        double pop();
    
    private:
        double *stack;
        int count;
        int MAXCOUNT;
            
};



#endif /* defined(__LabAssignment4__OperatorStack__) */
