//
//  List.h
//  LabAssignment3
//
//  Created by Immanuel Amirtharaj on 1/18/15.
//  Copyright (c) 2015 Immanuel Amirtharaj. All rights reserved.
//

#ifndef __LabAssignment3__List__
#define __LabAssignment3__List__

#include <stdio.h>
#include <iostream>

using namespace std;

class List
{
   
    public:
        // Function: Constructors
        List();
    
        // Function: Destructor
        ~List();
    
        // Function: Copy constructor
        List(const List&);
    
        // Function: Assignment operator
        List& operator=(const List&);
    
        // Function: output operator
        friend ostream& operator<<(ostream& outStream, List&);
    
    
        // Function: Insert an item to the list
        // Postcondition: insert after the pointer and
        // move the pointer to the new item
        void insert(const int&);
    
        class node {
            public:
                node(int, node*);
                int data;
                node* next;
        };
    
    private:
        node* list;
        int size;
        node* cursor;
};


#endif /* defined(__LabAssignment3__List__) */
