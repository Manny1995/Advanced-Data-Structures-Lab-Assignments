//
//  orderedlist.h
//  LabAssignment5
//
//  Created by Immanuel Amirtharaj on 2/1/15.
//  Copyright (c) 2015 Immanuel Amirtharaj. All rights reserved.
//

#ifndef __LabAssignment5__List__
#define __LabAssignment5__List__

#include <stdio.h>

#include <iostream>
using namespace std;


class List {
public:
    //Function:	Constructors
    List();
    //Function:	Destructor
    ~List();
    //Function:	Copy constructor
    List(List&);
    //Function:	Assignment operator
    const List& operator=(const List&);
    //Function:	output	operator
    friend ostream&	operator<<(ostream&, const List&);
    //Function:	Insert an item to the list
    //Postcondition: insert	after the pointer and
    //move the pointer to the new item
    void insert(const int&);
    
    void replace(int index, int element);

    
    class node {
    public:
        node(int, node*);
        int data;
        node* next;
    };
protected:
    node* list;
    int	size;
    node* cursor;
};


#endif /* defined(__LabAssignment5__orderedlist__) */
