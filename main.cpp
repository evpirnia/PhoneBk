/********************************************************************
 *
 * NAME:         Evelyn Pirnia
 *
 * HOMEWORK:     Project 2
 *
 * CLASS:        ICS 212
 *
 * INSTRUCTOR:   Ravi Narayan
 *
 * DATE:         July 24, 2015
 *
 * FILE:         main.cpp
 *
 * DESCRIPTION:  This C++ file contains the main driver for project 2
 *
 ********************************************************************/
#include <iostream>
#include <fstream>
#include "llist.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    cout<< "Hello and Welcome to your own Personal Address Book!" << endl;
    llist mylist("readthis.txt");
    
    int run = 0;
    while (run == 0)
    {
        run = mylist.menu();
    }
    return 0;
}
