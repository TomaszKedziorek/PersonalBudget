#ifndef INEXMENAGER_H
#define INEXMENAGER_H
#include <iostream>
#include <vector>
#include "inex.h"
#include "inexFile.h"

using namespace std;

class InExMenager {
    vector<InEx> expenses;
    vector<InEx> incomes;
    const string EXPENSES_FILE_NAME;
    const string INCOMES_FILE_NAME;
    InExFile inexFile;
    const int LOGGED_USER_ID;
    int lastExpenseID = 0;
    int lastIncomeID = 0;

public:
    InExMenager(  int loggedUserID , string incomesFileName = "incomes.xml", string expensesFileName = "expenses.xml" );
    void loadExpensesFromFile();
    void showFullExpense();
    InEx findExpenseByID();
    InEx findExpenseByDate();
    void showCurrentExpense();
    void addNewExpense();
    void sortExpenses();
    void setLastExpenseID();
    float sumExpenses();


};



#endif // INEXMENAGER_H
