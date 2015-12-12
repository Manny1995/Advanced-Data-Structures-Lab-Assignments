//
//  RBTree.h
//  COEN 70
//  LabAssignment9
//
//  Created by Immanuel Amirtharaj & Greg Cusack on 3/2/15.
//  Copyright (c) 2015 Immanuel Amirtharaj, Greg Cusakc. All rights reserved.
//

#ifndef __LabAssignment9__RBTree__
#define __LabAssignment9__RBTree__
//#define RED RBNode<int>::RED
//#define BLACK RBNode<int>::BLACK

#include <stdio.h>
#include "RBNode.h"
#include <iostream>

//template<typename T>
class RBTree
{
    
protected:
    //     template <typename T>
    RBNode<int> *treeRoot;
    
public:
    
    //gets sibling(parents other child) of given node
    template<typename T>
    RBNode<T> * getSibling (RBNode<T> *root)
    {
        if(root == treeRoot)
        {
            return NULL;
        }
        RBNode<int>* parent = root->parent();
        if (parent->left() == root)
            return parent->right();
        else
            return parent->left();
    }
    
    //gets aunt (grandparents other child) of given node
    template<typename T>
    RBNode<T> * getAunt (RBNode<T> *root)
    {
        if (root == treeRoot)
            return NULL;
        else
            return getSibling( root->parent() );
    }
    
    //gets grandparent (parents parent) of given node
    template<typename T>
    RBNode<T> * getGrandparent(RBNode<T> *root)
    {
        if (root == treeRoot)
            return NULL;
        RBNode<int>* temp = root->parent();
        return temp->parent();
    }
    
    //rotates tree left around given node to make sure that red/black tree functionality is maintained
    template<typename T>
    void rotateLeft(RBNode<T> *x)
    {
        
        RBNode<int>* y;
        if (x->right() == NULL)
            return;
        
        y = x->right();
        
        if (y->left() != NULL){
            y->left()->set_parent(x);
            x->set_right(y->left());
        }
        
        y->set_parent(x->parent());
        
        if (x->parent() == NULL)
            treeRoot = y;
        else if(x == x->parent()->left())
            x->parent()->set_left(y);
        else
            x->parent()->set_right(y);
        
        x->set_right(y->left());
        y->set_left(x);
        x->set_parent(y);
    }
    
    //rotates tree right around given node to make sure that red/black tree functionality is maintained
    template<typename T>
    void rotateRight(RBNode<T> *&y)
    {
        RBNode<int>* x;
        if (y->left()==NULL)
            return;
        
        x = y->left();
        
        if (x->right() != NULL){
            x->right()->set_parent(y);
            y->set_left(x->right());
        }
        
        x->set_parent(y->parent());
        
        if (y->parent() == NULL)
            treeRoot = x;
        else if(y == y->parent()->left())
            y->parent()->set_left(x);
        else
            y->parent()->set_right(x);
        
        y->set_left(x->right());
        x->set_right(y);
        y->set_parent(x);
    }
    
    //user function to print tree-->calls printTreeRecursively
    void printTree()
    {
        printTreeRecursively(treeRoot);
    }
    
    //print preorder-->1 for BLACK, 0 for RED
    template<typename T>
    void printTreeRecursively(RBNode<T> *root)
    {
        if(root == NULL)
            return;
        cout << root->data() << "(" << root->color() << ") ";
        printTreeRecursively(root->left());
        printTreeRecursively(root->right());
        
        return;
    }
    
    //fixTree is used to fix the tree and make it into a proper red/black tree by rotation and setting node colors
    template<typename T>
    void fixTree(RBNode<T> *nodeptr)
    {
        if (nodeptr == treeRoot){
            nodeptr->set_color(RBNode<int>::BLACK);
            return;
        }
        
        else if (nodeptr->parent()->color() == RBNode<int>::BLACK )
            return;
        
        else{
            if (getAunt(nodeptr) == NULL || getAunt(nodeptr)->color() == RBNode<int>::BLACK ){
                if ( nodeptr == nodeptr->parent()->right() ){
                    if ( nodeptr->parent() == getGrandparent(nodeptr)->left() ){
                        RBNode<int>* temp = nodeptr->parent();
                        rotateLeft(temp);
                        fixTree(nodeptr->left());
                    }
                    else{
                        nodeptr->parent()->set_color(RBNode<int>::BLACK);
                        getGrandparent(nodeptr)->set_color(RBNode<int>::RED);
                        RBNode<int>* temp = getGrandparent(nodeptr);
                        rotateLeft(temp);
                        return;
                    }
                }
                else{
                    if (nodeptr->parent() == getGrandparent(nodeptr)->right()){
                        RBNode<int>* temp = nodeptr->parent();
                        rotateRight(temp);
                        fixTree(temp);
                    }
                    else{
                        nodeptr->parent()->set_color(RBNode<int>::BLACK);
                        getGrandparent(nodeptr)->set_color(RBNode<int>::RED);
                        RBNode<int>* temp = getGrandparent(nodeptr);
                        rotateRight(temp);
                        return;
                    }
                }
            }
            
            else{
                nodeptr->parent()->set_color(RBNode<int>::BLACK);
                getAunt(nodeptr)->set_color(RBNode<int>::BLACK);
                getGrandparent(nodeptr)->set_color(RBNode<int>::RED);
                RBNode<int>* temp = getGrandparent(nodeptr);
                fixTree(temp);
            }
        }
    }
    
    //user implementation of addNode
    void addNode(int x)
    {
        addNode2(treeRoot,x);
    }
    
    //addNode2 inserts a node by using binary search...then is calls fixTree to maintain red/black tree functionality
    void addNode2(RBNode<int>* nodePtr, int key)
    {
        
        
        
        fixTree(treeRoot);

        
    }
    
};

#endif /* defined(__LabAssignment9__RBTree__) */
