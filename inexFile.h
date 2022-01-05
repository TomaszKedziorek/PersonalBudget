#ifndef INEXFILE_H
#define INEXFILE_H
#include <vector>
#include "inex.h"
#include "Markup.h"

using namespace std;

class InExFile {
    const string INCOMES_FILE_NAME;
    const string EXPENSES_FILE_NAME;
    int lastIncomesID = 0;
    int lastExpensesID = 0;
    CMarkup xmlInEx;
    string getIncomesFileName();
    string getExpensesFileName();

public:
    InExFile( string incomesFileName = "incomes.xml", string expensesFileName = "expenses.xml" );
    vector<InEx> loadInExFile( string inexFileName );
    void setLastIncomesID( int lastInID );
    void setLastExpensesID( int lastExID );
    int getLastIncomesID();
    int getLastExpensesID();
    void showAllInEx( vector<InEx> &allInEx );

};

#endif // INEXFILE_H
