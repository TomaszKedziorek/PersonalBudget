#include "date.h"

int Date::getCurrentDateInt() {
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

int Date::dateIntFormat( string date_str ) {
    int date_int = 0;
    date_str.erase( 7, 1 );
    date_str.erase( 4, 1 );
    date_int = atoi( date_str.c_str() );
    return date_int;
}

bool Date::checkDateLength( string date_str ) {
    bool correct = false;
    if( date_str.length() != 10 ) {
        correct = false;
    } else {
        correct = true;
    }
    return correct;
}

int Date::howManyDays( string date_str ) {
    int yyyy = atoi( date_str.substr(0,4) .c_str() );
    int mm  = atoi( date_str.substr(5,2).c_str() );
    int dd  = atoi( date_str.substr(8,2).c_str() );
    int days = 0;
    if( mm<=7 ) {
        if( mm!=2 ) {
            if ( mm%2 != 0 ) {
                days = 31;
            } else if( mm%2 == 0 ) {
                days = 30;
            }
        } else {
            if( (yyyy%4 ==0 && yyyy%100!=0) || yyyy%400==0 ) {
                days = 29;
            } else {
                days = 28;
            }
        }
    } else if( mm > 7 ) {
        if ( mm%2 == 0  ) {
            days = 31;
        } else if( mm%2 != 0 ) {
            days = 30;
        }
    }
    return days;
}
bool Date::checkDateFormat( string date_str ) {
    bool correct = false;
    if( date_str[4] != '-' || date_str[7] != '-' ) {
        correct = false;
    } else
        correct = true;

    return correct;
}
bool Date::checkDate( string date_str ) {
    int yyyy = atoi( date_str.substr(0,4) .c_str() );
    int mm  = atoi( date_str.substr(5,2).c_str() );
    int dd  = atoi( date_str.substr(8,2).c_str() );
    bool correct = false;
    if ( yyyy < 2000 ) {
        correct = false;
    } else {
        if ( mm > 12 || mm < 1 ) {
            correct = false;
        } else {
            if( dd<= howManyDays( date_str ) && dd >= 1 ) {
                correct = true;
            }
        }
    }
    return correct;
}

bool Date::checkDateCorrectness( string date_str ) {
    bool correct = false;
    if( !checkDateLength( date_str ) ) {
        cout<<"Given date: " << date_str << " has wrong length." <<endl;
    }
    else if( !checkDateFormat( date_str ) ) {
            cout<<"Given date: " << date_str << " has wrong format." <<endl;
    }
    else if( !checkDate( date_str ) ){
                cout<<"Given date: " << date_str << " is incorrect." <<endl;
    }else
        correct = true;
    return correct;
}

string Date::adjustDateFormat( string date_str ) {
    for( int i=0; i<date_str.length(); i++ ) {
        if( date_str[i] < '0' || date_str[i] > '9' ) {
            date_str.replace( i, 1, "-" );
        }
    }

    return date_str;
}

int Date::setInExDate(){
    string inexDate = "2000-01-01";

    do{
        cout<<"Please type date in format: yyyy-mm-dd" <<endl;
        getline( cin, inexDate );
    }while( !checkDateCorrectness( inexDate ) );
    return dateIntFormat( inexDate );
}
