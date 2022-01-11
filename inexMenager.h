#ifndef INEXMENAGER_H
#define INEXMENAGER_H
#include <iostream>
#include <vector>
#include "inex.h"
#include "inexFile.h"
#include "date.h"
#include "commonFunk.h"
#include <algorithm>

using namespace std;

class InExMenager {
    const int LOGGED_USER_ID;
    const string INCOMES_FILE_NAME;
    const string EXPENSES_FILE_NAME;

    vector<InEx> expenses;
    vector<InEx> incomes;
    InExFile inexFile;
    int lastExpensesID = 0;
    int lastIncomesID = 0;

    string getIncomesFileName();
    string getExpensesFileName();
    int getLoggedUserID();
    void loadInExFromFile();
    void setLastIncomesID( int lastInID );
    void setLastExpensesID( int lastExID );
    int getLastIncomesID();
    int getLastExpensesID();
    void setInExLastID( string inexFileName, int lastID );
    int getInExLastID( string inexFileName );
    float checkComa( string value );
    void addToVector( string inexFileName, InEx &newInEx );
    void addNewInEx( string inexFileName, int inexDate );

    float inexSum( vector<InEx> &inex );
    void inexSort();
    void balance( int since, int to );
    void showInEx( vector<InEx> &inex );
public:
    InExMenager(  int loggedUserID , string incomesFileName = "incomes.xml", string expensesFileName = "expenses.xml" );

    void addNewTodayIncome();
    void addNewTodayExpense();
    void addNewDiffDateIncome();
    void addNewDiffDateExpense();
    void currentMonthBalance();
    void previousMonthBalance();
    void rangeMonthBalance();

};



#endif // INEXMENAGER_H
