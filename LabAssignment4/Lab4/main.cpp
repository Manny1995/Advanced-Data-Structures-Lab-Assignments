//
//  main.cpp
//  LabAssignment4
//
//  Created by Immanuel Amirtharaj and Brian Pingel on 1/26/15.
//  Copyright (c) 2015 Immanuel Amirtharaj and Brian Pingel. All rights reserved.
//

#include <iostream>
#include "OperatorStack.h"


using namespace std;

/* 10 TEST CASES
 
 Add an equation: -3.0 5.1 + 4.2 2.1 - *
 The answer to the expression is 4.41
 
 Add an equation: 3 2 + 6 *
 The answer to the expression is 30
 
 Add an equation: 4 2 - 2 /
 The answer to the expression is 1
 
 Add an equation: 2 7 / 4 *
 The answer to the expression is 1.14286
 
 Add an equation: 1.1 4.7 + 6.8 -
 The answer to the expression is -1
 
 Add an equation: 1.2 4.6 -
 The answer to the expression is -3.4
 
 Add an equation: 6.9 9.6 + 4.8 3.2 + /
 The answer to the expression is 2.0625
 
 Add an equation: 2.3 4.6 / 2
 The answer to the expression is 0.5
 
 Add an equation: 1.2 3.6 - 45.8 *
 The answer to the expression is -109.92
 
 Add an equation: 1.4 5.7 * 3.6 9.3 / +
 The answer to the expression is 8.3671
 
 */




int main(int argc, const char * argv[]) {
    
    while (1)
    {

        OperatorStack newStack(100);
        
        // Declaring the operands and the result
        double operand1, operand2, result;
        result = 0;
        string line;
        
        
        cout << "Add an equation: ";
        
        // Collects the input from the command line for parsing and adds a space to fit the constraints for the algorithm
        getline(cin, line);
        line = line + " ";
        ;
        
        /* Traverses through the line and reads operators/numbers until the first space.  After it reaches
            the space, it makes a new substring from the space to the end of the line and repeats the process
            until the string's length becomes 0;
         */
        
        while (line.length() != 0)
        {
        
            // Finds the space and saves the operator/number into a substring
            long pos = line.find(" ");
            string temp = line.substr(0, pos);

            // Reading an operator
            if (temp == "+" || temp == "-" || temp == "*" || temp == "/")
            {
                operand2 = newStack.pop();
                operand1 = newStack.pop();
            
                if (temp == "+")
                    result = operand1+operand2;
                if (temp == "-")
                    result = operand1-operand2;
                if (temp == "*")
                    result = operand1*operand2;
                if (temp == "/")
                    result = operand1/operand2;
            
                newStack.push(result);
            }
            
            // Reading an operand
            else
            {
                double operand = stod(temp, NULL);
                //cout << operand <<endl;
                newStack.push(operand);
            
            }
            
            line = line.substr(pos+1);
        }
        
        cout << "The answer to the expression is " << result << endl;;
        
        }
    
    return 0;
}
