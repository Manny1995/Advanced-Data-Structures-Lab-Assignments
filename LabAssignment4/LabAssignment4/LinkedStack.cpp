//
//  LinkedStack.cpp
//  LabAssignment4
//
//  Created by Immanuel Amirtharaj on 1/26/15.
//  Copyright (c) 2015 Immanuel Amirtharaj. All rights reserved.
//

#include "LinkedStack.h"

LinkedStack::~LinkedStack()
{
    while(head->next!=NULL)
    {
        node *deleteNode = head->next;
        head->next = deleteNode->next;
        delete deleteNode;
    }
    
    delete head;
}

LinkedStack::LinkedStack(LinkedStack& newStack)
{
  
    *this = newStack;
    
}

LinkedStack::node::node(double _data, node * _next)
{
    data = _data;
    next = _next;
}

LinkedStack::node::node()
{
    data = 0;
    next = NULL;
}

LinkedStack::LinkedStack()
{
    head = new node(0, NULL);
}

void LinkedStack::push(double data)
{
    node *newNode = new node(data, NULL);
    
    if (head->next == NULL)
    {
        head->next = newNode;
        newNode->next = NULL;
    }
    
    else
    {
        newNode->next = head->next;
        head->next = newNode;
    }
    
}

double LinkedStack::pop()
{
    double tempData = head->next->data;
    node *tempNode = head->next;
    head->next = tempNode->next;
    tempNode->next = NULL;
    delete tempNode;
    return tempData;
}

void LinkedStack::reverseStack()
{
    
    node* current = head;
    node* previous=NULL;
    node* next;
    while (current != NULL)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    head = previous;
//    node *p, *q;
//    p = q = head->next;
//    q = p->next;
//    
//    while(p!=NULL)
//    {
//        p->next = q->next;
//        q->next = p;
//        
//        p = q->next;
//        q = p->next;
//    }
//    
//    node *p = head;
//    node *q = p->next;
//    while (p->next!=NULL)
//    {
//        p->next = q->next;
//        q->next = p;
//        q = p->next;
//    }
}

ostream& operator<<(ostream& outStream, LinkedStack& stackNode)
{
    LinkedStack::node *traverse = stackNode.head;
    while (traverse != NULL)
    {
        outStream << traverse->data << " ";
        traverse = traverse->next;
    }
    
    outStream << endl;
    return outStream;
}

//const List&	List::operator=(const List& other) {
//    *this = other;
//}


LinkedStack& LinkedStack::operator=(LinkedStack& other)
{
    //this->head = other.head;
    node *traverse = new node(0, NULL);
    head = traverse;
    
    node *othernode = other.head->next;
    
    while (othernode!= NULL)
    {
        
        traverse->next= new node(othernode->data, NULL);
        traverse = traverse->next;
        othernode = othernode->next;
        
    }
    
    return *this;
    
}
