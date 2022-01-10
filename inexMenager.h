#ifndef INEXMENAGER_H
#define INEXMENAGER_H
#include <iostream>
#include <vector>
#include "inex.h"
#include "inexFile.h"
#include "date.h"
#include "commonFunk.h"

using namespace std;

class InExMenager {
    vector<InEx> expenses;
    vector<InEx> incomes;
    const string EXPENSES_FILE_NAME;
    const string INCOMES_FILE_NAME;
    InExFile inexFile;
    const int LOGGED_USER_ID;
    int lastExpensesID = 0;
    int lastIncomesID = 0;
    string getIncomesFileName();
    string getExpensesFileName();
    int getLoggedUserID();
    void loadInExFromFile( );
    void setLastIncomesID( int lastInID );
    void setLastExpensesID( int lastExID );
    int getLastIncomesID();
    int getLastExpensesID();
    void setInExLastID( string inexFileName, int lastID );
    int getInExLastID( string inexFileName );
    float checkComa( string value );
    void addToVector( string inexFileName, InEx &newInEx);
    void addNewInEx( string inexFileName, int inexDate );

public:
    InExMenager(  int loggedUserID , string incomesFileName = "incomes.xml", string expensesFileName = "expenses.xml" );

    void showAllInEx(  );
    void addNewTodayIncome();
    void addNewTodayExpens();
    void addNewDiffDateIncome();
    void addNewDiffDateExpens();
};



#endif // INEXMENAGER_H
