#include "inex.h"

using namespace std;

InEx::InEx( int InExID, int userInExID, int date, string item, float amount ){
        this -> InExID = InExID;
        this -> userInExID = userInExID;
        this -> date = date;
        this -> item = item;
        this -> amount = amount;
}

void InEx::setInExID( int InExID ) {
    this ->InExID = InExID;
}
void InEx::setUserInExID( int userInExID ) {
    this ->userInExID = userInExID;
}
void InEx::setDate( int date ) {
    this ->date = date;
}
void InEx::setItem( string item ){
    this ->item = item;
}
void InEx::setAmount( float amount ){
    this ->amount = amount;
}

int InEx::getInExID() {
    return InExID;
}
int InEx::getUserInExID( ) {
    return userInExID;
}
int InEx::getDate() {
    return date;
}
string InEx::getItem(){
    return item;
}
float InEx::getAmount(){
    return amount;
}
string InEx::getAmount_str(){
    return floatToString( amount );
}

void InEx::showInExInfo(  ) {
    Date dat;
    cout<< left << setw(5) <<dat.dateStringFormat( getDate() ) << " ID:" << getInExID() << left << setw(3) << " " <<
    getItem() << ": "<< '\t'  << fixed << setprecision(2) << getAmount() <<endl;
}

