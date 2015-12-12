//
//  ExpTree.cpp
//  LabAssignment8
//
//  Created by Immanuel Amirtharaj and Justin Wong on 2/23/15.
//  Copyright (c) 2015 Immanuel Amirtharaj. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include "ExpTree.h"

//constructor
ExpTree::ExpTree()
{
}

//builds the tree
void ExpTree::build()
{
    
    
    
    // Declaring the result
    string line;
    
    cout << "Add an equation: ";
    
    // Collects the input from the command line for parsing and adds a space to fit the constraints for the algorithm
    getline(cin, line);
    line = line +" ";
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
        
        Expression *tempRoot = new Expression();
        
        // Reading an operator
        if (temp == "+" || temp == "-" || temp == "*" || temp == "/")
        {
            
            if (temp == "+")
                tempRoot->operation = '+';
            if (temp == "-")
                tempRoot->operation = '-';
            if (temp == "*")
                tempRoot->operation = '*';
            if (temp == "/")
                tempRoot->operation = '/';
            
            tempRoot->right = x.top();
            x.pop();
            
            tempRoot->left = x.top();
            x.pop();
            
            if (tempRoot->operation == '+')
                tempRoot->operand = (tempRoot->left->operand + tempRoot->right->operand);
            if (tempRoot->operation == '-')
                tempRoot->operand = (tempRoot->left->operand - tempRoot->right->operand);
            if (tempRoot->operation == '*')
                tempRoot->operand = (tempRoot->left->operand * tempRoot->right->operand);
            if (tempRoot->operation == '/')
                tempRoot->operand = (tempRoot->left->operand / tempRoot->right->operand);
            
            
            x.push(tempRoot);
            
            
        }
        
        // Reading an operand
        else
        {
            tempRoot->operand = atoi(temp.c_str());
            x.push(tempRoot);
        }
        
        //check push later
        line = line.substr(pos+1);
    }
    root = x.top();
    
}


//print postorder
void ExpTree::print_postorder(Expression *subRoot)
{
    if(subRoot == NULL)
        return;
    print_postorder(subRoot->left);
    print_postorder(subRoot->right);
    if(subRoot->operation == '*' || subRoot->operation == '/' || subRoot->operation == '-' || subRoot->operation == '+')
    {
        cout << subRoot->operation << " " ;
    }
    else
        cout << subRoot->operand << " ";
    return;
}

//print preorder
void ExpTree::print_preorder(Expression *subRoot)
{
    if(subRoot == NULL)
        return;
    
    if(subRoot->operation == '*' || subRoot->operation == '/' || subRoot->operation == '-' || subRoot->operation == '+')
    {
        cout << subRoot->operation << " " ;
    }
    else
        cout << subRoot->operand << " ";

    
    print_preorder(subRoot->left);
    print_preorder(subRoot->right);
    
    return;
    
}

//print inorder
void ExpTree::print_inorder(Expression *subRoot)
{
    if(subRoot == NULL)
        return;
    
    print_inorder(subRoot->left);

    if(subRoot->operation == '*' || subRoot->operation == '/' || subRoot->operation == '-' || subRoot->operation == '+')
    {
        cout << subRoot->operation << " " ;
    }
    else
        cout << subRoot->operand << " ";
    
    
    print_inorder(subRoot->right);
    
    return;
    
}

//returns a pointer to the root
ExpTree::Expression* ExpTree::getRoot()
{
    return root;
}

//returns the sum in the root
int ExpTree::evaluate()
{
    return root->operand;
}