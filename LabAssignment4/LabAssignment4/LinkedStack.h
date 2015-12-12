//
//  LinkedStack.h
//  LabAssignment4
//
//  Created by Immanuel Amirtharaj on 1/26/15.
//  Copyright (c) 2015 Immanuel Amirtharaj. All rights reserved.
//

#ifndef __LabAssignment4__LinkedStack__
#define __LabAssignment4__LinkedStack__

#include <stdio.h>
#include <iostream>

using namespace std;


class LinkedStack
{
    
public:
    class node
    {
        public:
            double data;
            node* next;
            node();
            node(double _data, node *_next);
    };
    LinkedStack();
    void push(double data);
    double pop();
    friend ostream& operator<<(ostream& outStream, LinkedStack&);
    LinkedStack& operator=(LinkedStack&);
    void reverseStack();
    LinkedStack(LinkedStack&);
    ~LinkedStack();

    
private:
    int count;
    node *head; //sentinel node
    
};

#endif /* defined(__LabAssignment4__LinkedStack__) */
