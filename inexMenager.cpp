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
    expenses = inexFile.loadInExFile( getIncomesFileName(), getLoggedUserID() );
    incomes  = inexFile.loadInExFile( getExpensesFileName(), getLoggedUserID() );
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

