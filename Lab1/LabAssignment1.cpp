/* HelloWorldExample.cpp */
#include <iostream>
#include <string>
using namespace std;
/* ArrayExample.cpp */
// The largest index of i can only be 9, otherwise out of bounds.  The loops starts from 1 and then ends at 10, but we want it to start from 0 and end at 9
int main() {
    int score[10];
    for (int i=0; i <= 9; ++i)
    {
        score[i]=3*i;
        cout << score[i] << endl;   // added endl for readability purposes
    }
    return 0;
}