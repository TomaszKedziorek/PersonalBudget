#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H
#include <iostream>
#include <vector>
#include "userMenager.h"
#include "inexMenager.h"
#include "inex.h"
#include "inexFile.h"
#include "date.h"
#include "commonFunk.h"
using namespace std;

class PersonalBudget {
    UserMenager userMenager;
    InExMenager *inexMenager;
    const string INCOMES_FILE_NAME;
    const string EXPENSES_FILE_NAME;

    string getIncomesFileName();
    string getExpensesFileName();
    void addNewTodayIncome();
    void addNewTodayExpense();
    void addNewDiffDateIncome();
    void addNewDiffDateExpense();
public:
    PersonalBudget( string usersFileName ="users.xml" , string incomesFileName = "incomes.xml", string expensesFileName = "expenses.xml"  );
    ~PersonalBudget() {
        delete inexMenager;
        inexMenager = NULL;
    };
    void registration();
    int signIn();
    void changePassword( int IDLoggedUser );
    int signOut();
    void addNewExpense();
    void addNewIncome();

    void currentMonthBalance();
    void previousMonthBalance();
    void rangeMonthBalance();
};

#endif // PERSONALBUDGET_H
