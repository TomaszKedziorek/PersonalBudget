#include "date.h"

int Date::getCurrentDateInt(){
    int date = 20000101;
    int year = 0,month = 0,day = 0;
    time_t t = time(0);   // get time now
    tm* now = localtime(&t);
    year    = ( now->tm_year + 1900 ) *10000 ;  //years since 1900
    month   = ( now->tm_mon + 1 ) * 100;     //months since january 0-11
    day     = ( now->tm_mday );         //day of the month
    date    = year + month + day;
    return date;
}

string Date::dateStringFormat( int date_int ) {
    string date_str = IntToString( date_int );
    date_str.insert(4,"-");
    date_str.insert(7,"-");
    return date_str;
}
