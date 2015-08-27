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
 * FILE:         record.h
 *
 * DESCRIPTION:  This file contains the header for the record
 *               class in project 2.
 *
 ********************************************************************/

#ifndef proj2_record_h
#define proj2_record_h

#define TRUE 1
#define FALSE 0
#define NAME_SIZE 25
#define ADDRESS_SIZE 80
#define TELNO_SIZE 15

struct record
{
    public:
        char name[NAME_SIZE];
        char address[ADDRESS_SIZE];
        int yearofbirth;
        char telno[TELNO_SIZE];
        struct record* next;
};

#endif


