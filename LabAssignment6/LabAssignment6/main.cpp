//
//  main.cpp
//  LabAssignment6
//
//  Created by Immanuel Amirtharaj on 2/7/15.
//  Copyright (c) 2015 Immanuel Amirtharaj. All rights reserved.
//

#include <iostream>
#include <list>
#include "Map.h"
#include "Pair.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    
    map<int, string> mappy;
    mappy.insert(1, "bread");
    mappy.insert(5, "ham");
    mappy.insert(3, "cheese");
    mappy.insert(2, "salad");
    mappy.insert(9, "water");

    mappy.printList();  // Shows all 5 elements
    
    cout << endl;
    
    mappy.insert(9, "water");
    
    cout << endl;
    
    bool hasKey = mappy.contains_key(5);    // Returns true (1)
    cout << hasKey << endl;
    
    bool newKey = mappy.contains_key(0);    // Returns false (0)
    cout << newKey << endl;
    
    cout << endl;

    string keyString = mappy.value_of(3);   // Returns cheese
    cout << keyString << endl;
    
    string test = mappy.value_of(0);
    cout << test << endl;
    cout << endl;

    mappy.remove_key(5);    // ham is deleted
    
    mappy.printList();      // Shows 4 elements now
    
    cout << endl;

    
    
    map<int, float> intmappy;
    intmappy.insert(1, 4);
    intmappy.insert(5, 5.76);
    intmappy.insert(3, -1.43);
    intmappy.insert(2, 2.15);
    intmappy.insert(9, -6.18);
    
    
    intmappy.printList();
    
    
    
    return 0;
}
