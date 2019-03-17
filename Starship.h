//===========================================================================
//===================    ENTERPRIZE STARSHIP PROGRAM     ====================
//===
// programmer: Hagai Vinik.
// date: 12/12/2017.
// this is a program that handle aliens in space, save their names and details.
//===

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define N 16

typedef char STRING[N];

typedef struct // alien details.
{
        int id;
        STRING name;
        STRING star_name;
        int age;
}alien, * alienPtr;