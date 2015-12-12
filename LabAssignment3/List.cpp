//
//  List.cpp
//  LabAssignment3
//
//  Created by Immanuel Amirtharaj on 1/18/15.
//  Copyright (c) 2015 Immanuel Amirtharaj. All rights reserved.
//

#include <iostream>
#include "List.h"

using namespace std;


List::List()
{
    size = 0;
    list = new node(0,NULL);
    cursor = list;
}


List::~List()
{
    node* deletenode = list;
    node *tempnode;
    
    while (deletenode != NULL)
    {
        tempnode = deletenode->next;
        delete deletenode;
        deletenode = tempnode;
    }
    
}


List::List(List& source)
{
    *this = source;
    
}

// Function: Insert an item to the list
// Postcondition: insert after the pointer and
// move the pointer to the new item
void List::insert(const int& data)
{
    List::node *newnode = new node(data, NULL);
    node(data, newnode);
    
    if (list == NULL)
    {
        list = newnode;
        cursor = newnode;
    }
    else
    {
        cursor->next = newnode;
        cursor = newnode;
    }
    
    size++;
}


ostream& operator<<(ostream& outStream, const List& passedList)
{
    if (this != &passedList)
    {
        if (this)
    }
    List::node *newnode = passedList.list;
    while (newnode!=NULL)
    {
        outStream << newnode->data << " ";
        newnode = newnode->next;
    }
    
    outStream << "" << endl;

    return outStream;
}


const List& List::operator=(const List& source)
{
    
    if (this != source)
    {
        if (this->list != NULL)
        {
            delete [] this->list;
        }
        
        
    }
    
    return *this;
   
}


List::node::node(int insertData, node* nextNode)
{

    data = insertData;
    next = nextNode;
    
}

