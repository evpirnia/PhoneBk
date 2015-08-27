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
 * FILE:         llist.h
 *
 * DESCRIPTION:  This file contains the header for the llist
 *               (aka linked list) class in project 2.
 *
 ********************************************************************/

#ifndef proj2_llist_h
#define proj2_llist_h

#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>

#include "record.h"
using namespace std;

class llist
{
    private:
        record *start;
        char filename[16];
        int readfile();
        int writefile();
        record* reverse(record *);
        void cleanup();
    
    public:
        llist();
        llist(char []);
        ~llist();
        int addRecord(char[], char[], int, char[]);
        int printRecord(char []);
        int modifyRecord(char[], char[], char[]);
        void printAll();
        int deleteRecord(char[]);
        void reverse();
    
        int menu(); /* added this */
        friend std::ostream &operator<<(std::ostream &, const llist &);
        llist &operator=(const llist &);
};

#endif
