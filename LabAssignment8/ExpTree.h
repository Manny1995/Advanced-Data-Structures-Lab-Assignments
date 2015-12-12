//
//  ExpTree.h
//  LabAssignment8
//
//  Created by Immanuel Amirtharaj on 2/23/15.
//  Copyright (c) 2015 Immanuel Amirtharaj. All rights reserved.
//

#ifndef __LabAssignment8__ExpTree__
#define __LabAssignment8__ExpTree__

#include <stdio.h>
#include <iostream>
#include <stack>


using namespace std;

class ExpTree
{
    //    build() – create the tree based on a postfix expression (recall Lab4) given by the user via
    //    the keyboard
    //    • evaluate() – recursively evaluate every node and output the value at the root
    //    • print_preorder() – output the tree with pre-order traversal
    //    • print_inorder() – output the tree with in-order traversal
    //    • print_postorder() – output the tree with post-order traversal
    
    public:
        class Expression
        {
        public:
            int operand;        // the operand
            char operation;     // the operator + - * /
            Expression *left;   // left child
            Expression *right;  // right child
        };
    
        // root node of the tree
        Expression *root;
    
        // the stack which manages the input and output
        stack <Expression *> x;
        
        // default constructor
        ExpTree();
    
        // returns the root of the tree
        Expression* getRoot();
    
        // returns the solution of the equation
        int evaluate();
    
    
        // print preorder
        void print_preorder(Expression *subRoot);
    
        // print inorder
        void print_inorder(Expression *subRoot);
    
        // print postorder
        void print_postorder(Expression *subRoot);
    
        // builds the tree using the stack and input
        void build();
    
    
};

#endif /* defined(__LabAssignment8__ExpTree__) */
