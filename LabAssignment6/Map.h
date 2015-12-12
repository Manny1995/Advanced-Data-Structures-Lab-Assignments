//
//  Map.h
//  LabAssignment6
//
//  Created by Immanuel Amirtharaj on 2/7/15.
//  Copyright (c) 2015 Immanuel Amirtharaj. All rights reserved.
//

//#ifndef __LabAssignment6__map__
//#define __LabAssignment6__map__

#include "Pair.h"
#include <stdio.h>
#include <list>
#include <iostream>

using namespace std;

template<typename K, typename V> class map
{
    public:
        /**
         Inserts a value into the map.
         @param key the key to insert @param value the value to insert
         */
        void insert(K key, V value); /**
                                      Determines whether the map contains a given key.
                                      @param key the key to check for */
        bool contains_key(K key); /**
                                   Retrieves the value of a given key. @param key the key to find
                                   @return the value
                                   */
        V value_of(K key);
        /**
         Removes the key and value. @param key the key to find
         */
        void remove_key(K key);
        map();
    
    
    void printList();
    
    private:
        list< Pair<K, V> > data;

};

// Constructof for map
template<typename K, typename V>
map<K, V>::map()
{
    
}

// Creates an instance of Pair with an inputted key and value, then adds it to the list
template<typename K, typename V>
void map<K, V>::insert(K key, V value)
{
    
    bool contains = contains_key(key);
    if (contains == false)
    {
        Pair<K, V> newEntry;
        newEntry.set_first(key);
        newEntry.set_second(value);
        data.push_back(newEntry);
    }
    
    else
    {
        cout << "The key already exists" << endl;
    }
}

// Takes in a key value and checks if it is in the list
template<typename K, typename V>
bool map<K, V>::contains_key(K key)
{
    for (typename list< Pair<K,V> >::iterator it=data.begin(); it != data.end(); ++it)
    {
        if (it->get_first() == key)
            return true;
    }
    
    return false;
}

// Takes in a key value and returns the value associated with it if found
template<typename K, typename V>
V map<K, V>::value_of(K key)
{
    for (typename list< Pair<K,V>> ::iterator it=data.begin(); it != data.end(); ++it)
    {
        
        if (it->get_first() == key)
            return it->get_second();
        
    }
    
    return V();
}


// Takes in a key value and removes the element associated to it from the list
template<typename K, typename V>
void map<K, V>::remove_key(K key)
{
    for (typename list< Pair<K,V> >::iterator it=data.begin(); it != data.end(); ++it)
    {
        
        if (it->get_first() == key)
        {
            data.erase(it);
            return;
        }
        
    }

    
}

// prints the list out USED FOR TESTING
template<typename K, typename V>
void map<K, V>::printList()
{
    
    for (typename list< Pair<K,V> >::iterator it=data.begin(); it != data.end(); ++it)
    {
        
        cout << it->get_first() << " " << it->get_second() << endl;
    }
    
}


//#endif /* defined(__LabAssignment6__Map__) */
