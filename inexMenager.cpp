#include "inexMenager.h"

InExMenager::InExMenager( int loggedUserID, string incomesFileName, string expensesFileName )
    :  LOGGED_USER_ID( loggedUserID ),INCOMES_FILE_NAME( incomesFileName ), EXPENSES_FILE_NAME( expensesFileName ) {
        loadInExFromFile();
        setLastIncomesID( inexFile.getLastIncomesID() );
        setLastExpensesID( inexFile.getLastExpensesID() );
}

string InExMenager::getIncomesFileName() {
    return INCOMES_FILE_NAME;
}
string InExMenager::getExpensesFileName() {
    return EXPENSES_FILE_NAME;
}
int InExMenager::getLoggedUserID() {
    return LOGGED_USER_ID;
}
void InExMenager::setLastIncomesID( int lastInID ) {
    lastIncomesID = lastInID;
}
void InExMenager::setLastExpensesID( int lastExID ) {
    lastExpensesID = lastExID;
}
int InExMenager::getLastIncomesID() {
    return lastIncomesID;
}
int InExMenager::getLastExpensesID() {
    return lastExpensesID;
}

void InExMenager::loadInExFromFile( ){
    expenses = inexFile.loadInExFile( getExpensesFileName(), getLoggedUserID() );
    incomes  = inexFile.loadInExFile( getIncomesFileName(), getLoggedUserID() );
}
void InExMenager::setInExLastID( string inexFileName, int lastID ) {
    if( inexFileName == getIncomesFileName() )
        setLastIncomesID( lastID );
    else
        setLastExpensesID( lastID );
}
int InExMenager::getInExLastID( string inexFileName ){
    if( inexFileName == getIncomesFileName() )
        return getLastIncomesID();
    else
        return getLastExpensesID();
}

float InExMenager::checkComa( string value ){
    for ( int i=0; i<value.length(); i++ ){
        if( value[i] == ',' ){
            value.replace( i, 1, "." );
        }
    }
    return atof( value.c_str() ) ;
}
void InExMenager::addToVector( string inexFileName, InEx &newInEx ){
    if( inexFileName == getIncomesFileName() )
        incomes.push_back( newInEx );
    else
        expenses.push_back( newInEx );
}

void InExMenager::addNewInEx( string inexFileName, int inexDate ){
    string inexItem = "";
    string inexAmount = "";
    cout<<"Short item description: " ;
    getline( cin, inexItem );
    cout<<"Amount: " ;
    getline( cin, inexAmount );
    int inexID = getInExLastID( inexFileName ) + 1;
    setInExLastID( inexFileName, inexID );
    InEx newInex( inexID, getLoggedUserID(), inexDate ,inexItem , checkComa( inexAmount ));
    addToVector( inexFileName, newInex );
    inexFile.addNewInEx( inexFileName, newInex );
}

void InExMenager::addNewTodayIncome(){
    Date date;
    addNewInEx( getIncomesFileName(), date.getCurrentDateInt() );
}
void InExMenager::addNewTodayExpens(){
    Date date;
    addNewInEx( getExpensesFileName(), date.getCurrentDateInt() );
}
void InExMenager::addNewDiffDateIncome(){
    Date date;
    int diffDate = date.setInExDate();
    addNewInEx( getIncomesFileName(), diffDate );
}
void InExMenager::addNewDiffDateExpens(){
    Date date;
    int diffDate = date.setInExDate();
    addNewInEx( getExpensesFileName(), diffDate );
}

void InExMenager::showAllInEx(  ) {
    cout<<"Expenses: "<<endl;
    for( unsigned int i=0; i<expenses.size(); i++ ) {
        expenses[i].showInExInfo();
        cout<< "---------" <<endl;
    }
    cout<<"Incomes: "<<endl;
    for( unsigned int i=0; i<incomes.size(); i++ ) {
        incomes[i].showInExInfo();
        cout<< "---------" <<endl;
    }
}

