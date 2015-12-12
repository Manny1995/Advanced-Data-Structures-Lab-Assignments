//
//  orderedlist.cpp
//  LabAssignment5
//
//  Created by Immanuel Amirtharaj on 2/2/15.
//  Copyright (c) 2015 Immanuel Amirtharaj. All rights reserved.
//

#include "orderedlist.h"

// Precondition: Takes in an index and the element to replace with as parameters
// Postcondition: Deletes the node at the selected index and adds the new element to the list
void OrderedList::replace(int index, int element)
{
    index--;
    OrderedList::node *traverse = list;
    node *temp = traverse;
    for (int i = 0; i < size; i++)
    {
        if (i == index)
        {
            break;
        }
        
        temp = traverse;
        traverse = traverse->next;
    }
    
    if (traverse == list)
    {
        list = list->next;
    }
    
    else
        if (traverse == cursor)
        {
            temp->next = NULL;
            cursor = temp;
        }
    
        else
            temp->next = traverse->next;
    
    delete traverse;
    size--;
    insert(element);
    
    
    
}


// Precondition: Takes in an integer as a parameter to insert into the list
// Poscondition: inserts a new node which contains the element into the list in ascending order
void OrderedList::insert(const int & _data)
{
    node *newnode = new node(_data, NULL);
    if (list == NULL)
    {
        list = newnode;
        cursor = newnode;
    }
    
    
    else
    {
        node *traverse = list;
        node *temp = traverse;
        while (traverse != NULL)
        {
            
            if (traverse->data >= _data)
                break;
            
            temp = traverse;
            traverse = traverse->next;
            
        }
        
        if (traverse == list)
        {
            newnode->next = traverse;
            list = newnode;
        }
        
        else
            if (temp == cursor)
            {
                temp->next = newnode;
                cursor = newnode;
            }
            else
            {
                newnode->next = traverse;
                temp->next = newnode;
            }
        
    }
    
    size++;
    
}

// Precondition: Takes in an ostream parameter and an OrderedList instance to print out the list
// Postcondition: Executes the print function and then returns the ostream parameter to print out the list
ostream& operator<<(ostream& out, const OrderedList& lhs) {
    OrderedList::node *newnode = lhs.list;
    while(newnode!=NULL) {
        out << newnode->data << ", ";
        newnode = newnode->next;
    }
    return out;
}

// Default Constructor
OrderedList::OrderedList()
{
    
}

// Default Destructor
OrderedList::~OrderedList()
{
}

