#ifndef INEXFILE_H
#define INEXFILE_H
#include <vector>
#include "inex.h"
#include "Markup.h"

using namespace std;

class InExFile {
    const string INCOMES_FILE_NAME;
    const string EXPENSES_FILE_NAME;
    CMarkup xmlIncomes;
    CMarkup xmlExpenses;
    int lastUserID = 0;
    string getIncomesFileName();
    string getExpensesFileName();

public:
    InExFile( string incomesFileName = "incomes.xml", string expensesFileName = "expenses.xml" );


};

#endif // INEXFILE_H
