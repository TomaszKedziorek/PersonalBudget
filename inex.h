#ifndef INEX_H
#define INEX_H
#include <iostream>
#include "commonFunk.h"
#include "date.h"
#include <iomanip>
using namespace std;

class InEx {
    int InExID;
    int userInExID;
    int date ;
    string item;
    float amount;

public:
    InEx(int InExID =0, int userInExID =0, int date =0, string item ="", float amount =0.0 );
    void setInExID( int InExID );
    void setUserInExID( int userInExID );
    void setDate( int date );
    void setItem( string item );
    void setAmount( float amount );
    int getInExID();
    int getUserInExID();
    int getDate();
    string getItem();
    float getAmount();
    string getAmount_str();
    void showInExInfo();
};


#endif // INEX_H
