//
//  main.cpp
//  LabAssignment1
//
//  Created by Immanuel Amirtharaj on 1/5/15.
//  Copyright (c) 2015 Immanuel Amirtharaj. All rights reserved.
//

// Fix the program so that the object B has the intended string (“Hello World”).

/* HelloWorldExample.cpp */
#include <iostream>
#include <string>
using namespace std;

// Fix the program so that the object B has the intended string (“Hello World”).
struct object {
    string* s;
};
int main() {
    object A, B;
    A.s = new string;
    *A.s = "Hello World"; // A has "Hello World"
    B.s = new string;
    *B.s = *A.s;
    *A.s = "Goodbye";
    cout << *A.s << endl;
    cout << *B.s << endl;
    return 0;
}




// The largest index of i can only be 9, otherwise out of bounds.  The loops starts from 1 and then ends at 10, but we want it to start from 0 and end at 9
int main() {
    int score[10];
    for (int i=0; i < 10; ++i)
    {
        score[i]=3*i;
        cout << score[i] << endl;   // added endl for readability purposes
    }
    return 0;
}

/*SphereExample.cpp*/
#include <iostream>
using namespace std;
const double PI = 3.14159265359;
void GetRadius(double & radius);
void ShowResults(double rad, double area, double vol);
int main() {
    cout << "Program computes surface area and volume of a sphere.\n";
    double  radius,
    surfaceArea=0,
    volume=0;
    // radius of sphere
    // its surface area
    // its volume
    GetRadius(radius);
    
    //first call surface area, then call volume
    surfaceArea = 4.0 * PI * radius * radius;
    volume = surfaceArea * radius / 3.0;
    ShowResults(radius, surfaceArea, volume);
    return 0; }
void GetRadius(double& rad)
{
    cout << "Enter radius of sphere: ";
    cin >> rad; }
void ShowResults(double rad, double area, double vol)
{
    cout << "Radius of sphere is " << rad << " inches\n";
    cout << "Its surface area is " << area << "sq. inches\n"
    << "Its volume is " << vol << " cubic inches.\n\n";
}
