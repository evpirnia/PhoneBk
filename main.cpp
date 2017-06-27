/********************************************************************
 * DESCRIPTION:  main driver written in C++
 ********************************************************************/
#include <iostream>
#include <fstream>
#include "llist.h"

using namespace std;

int main(int argc, const char * argv[]) {
    cout << "Hello and Welcome to your own Personal Address Book!" << endl;
    llist mylist("input.txt");
    int run = 0;
    while (run == 0) {
      run = mylist.menu();
    }
    return 0;
}
