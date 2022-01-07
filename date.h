#ifndef DATES_H
#define DATES_H
#include <iostream>
#include <ctime>
#include "commonFunk.h"

using namespace std;

class Date {


public:
    int getCurrentDateInt();
    string dateStringFormat( int date_int );
};


#endif // DATES_H
