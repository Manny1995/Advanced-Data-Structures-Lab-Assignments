//
//  main.cpp
//  LabAssignment8
//
//  Created by Immanuel Amirtharaj on 2/23/15.
//  Copyright (c) 2015 Immanuel Amirtharaj. All rights reserved.
//

#include <iostream>
#include <string>
#include "ExpTree.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    ExpTree x;
    x.build();
    
    
    x.print_preorder(x.getRoot());
    cout << endl;
    x.print_inorder(x.getRoot());
    cout << endl;
    x.print_postorder(x.getRoot());
    cout << endl;
    int solution = x.evaluate();
    cout << "Solution = " << solution << endl;

    return 0;
    
}
