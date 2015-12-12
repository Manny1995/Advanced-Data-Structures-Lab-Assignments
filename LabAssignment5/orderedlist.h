//
//  orderedlist.h
//  LabAssignment5
//
//  Created by Immanuel Amirtharaj on 2/2/15.
//  Copyright (c) 2015 Immanuel Amirtharaj. All rights reserved.
//

#ifndef __LabAssignment5__orderedlist__
#define __LabAssignment5__orderedlist__

#include <stdio.h>
#include <iostream>

#include "List.h"


using namespace std;

// OrderedList is a subclass of List which manages the nodes in ascending order
class OrderedList: public List
{
    public:
        
        // Inserts a node into the list in ascending order
        void insert(const int&);
        
        // Uses the passed index value to delete the corresponding node, and then calls the insert function
        // to add the new element to the list in ascending order
        void replace(int index, int element);
        
        // Default Constructor
        OrderedList();
        
        // Default Destructor
        ~OrderedList();
        
        // Overloading the cout function to output the ordered list
        friend ostream&	operator<<(ostream&, const OrderedList&);
    
};

#endif /* defined(__LabAssignment5__orderedlist__) */
