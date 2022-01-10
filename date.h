#ifndef DATES_H
#define DATES_H
#include <iostream>
#include <ctime>
#include "commonFunk.h"

using namespace std;
class InExMenager;
class Date {
    bool checkDateLength( string date_str );

    bool checkDate( string date_str ) ;
    bool checkDateFormat( string date_str );

public:
    int getCurrentDateInt();
    string dateStringFormat( int date_int );
    int dateIntFormat( string date_str );
    string adjustDateFormat( string date_str );
    bool checkDateCorrectness( string date_str );
    int setInExDate();
    int howManyDays( string date_str );
};


#endif // DATES_H
