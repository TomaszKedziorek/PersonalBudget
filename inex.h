#ifndef INEX_H
#define INEX_H
#include <iostream>

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
    void setInExAmount( float amount );
    int getInExID();
    int getUserInExID();
    int getDate();
    string getItem();
    float getInExAmount();
    void showInExInfo();
};


#endif // INEX_H
