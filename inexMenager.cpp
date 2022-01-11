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

void InExMenager::loadInExFromFile( ) {
    expenses = inexFile.loadInExFile( getExpensesFileName(), getLoggedUserID() );
    incomes  = inexFile.loadInExFile( getIncomesFileName(), getLoggedUserID() );
}
void InExMenager::setInExLastID( string inexFileName, int lastID ) {
    if( inexFileName == getIncomesFileName() )
        setLastIncomesID( lastID );
    else
        setLastExpensesID( lastID );
}
int InExMenager::getInExLastID( string inexFileName ) {
    if( inexFileName == getIncomesFileName() )
        return getLastIncomesID();
    else
        return getLastExpensesID();
}

float InExMenager::checkComa( string value ) {
    for ( unsigned int i=0; i<value.length(); i++ ) {
        if( value[i] == ',' ) {
            value.replace( i, 1, "." );
        }
    }
    return atof( value.c_str() ) ;
}
void InExMenager::addToVector( string inexFileName, InEx &newInEx ) {
    if( inexFileName == getIncomesFileName() )
        incomes.push_back( newInEx );
    else
        expenses.push_back( newInEx );
}

void InExMenager::addNewInEx( string inexFileName, int inexDate ) {
    string inexItem = "";
    string inexAmount = "";
    cout<<"Short item description: " ;
    getline( cin, inexItem );
    cout<<"Amount: " ;
    getline( cin, inexAmount);
    int inexID = getInExLastID( inexFileName ) + 1;
    setInExLastID( inexFileName, inexID );
    InEx newInex( inexID, getLoggedUserID(), inexDate,inexItem, checkComa( inexAmount ));
    addToVector( inexFileName, newInex );
    inexFile.addNewInEx( inexFileName, newInex );
    newInex.showInExInfo();
    Sleep(2000);
}

void InExMenager::addNewTodayIncome() {
    Date date;
    addNewInEx( getIncomesFileName(), date.getCurrentDateInt() );
}
void InExMenager::addNewTodayExpense() {
    Date date;
    addNewInEx( getExpensesFileName(), date.getCurrentDateInt() );
}
void InExMenager::addNewDiffDateIncome() {
    Date date;
    int diffDate = date.setInExDate();
    addNewInEx( getIncomesFileName(), diffDate );
}
void InExMenager::addNewDiffDateExpense() {
    Date date;
    int diffDate = date.setInExDate();
    addNewInEx( getExpensesFileName(), diffDate );
}

void InExMenager::showInEx( vector<InEx> &inex ) {
    for( unsigned int i=0; i<inex.size(); i++ ) {
        inex[i].showInExInfo( );
    }
    cout<< "=============================================" <<endl;
}
float InExMenager::inexSum( vector<InEx> &inex ) {
    float sum = 0;
    if( !inex.empty() ){
    for( unsigned int i=0; i<inex.size(); i++ ) {
        sum = sum + inex[i].getAmount();
    }
    }
    return sum;
}
void InExMenager::inexSort() {
    sort( expenses.begin(), expenses.end() );
    sort( incomes.begin(), incomes.end() );
}
void InExMenager::balance( int since, int to ) {
    vector<InEx> incomesFromRange;
    vector<InEx> expensesFromRange;
    inexSort();
    for( unsigned int i=0; i<incomes.size(); i++ ){
        if( incomes[i].getDate() >= since && incomes[i].getDate() <= to ){
            incomesFromRange.push_back( incomes[i] );
        }
    }
    for( unsigned int i=0; i<expenses.size(); i++ ){
        if( expenses[i].getDate() >= since && expenses[i].getDate() <= to ){
            expensesFromRange.push_back( expenses[i] );
        }
    }
    float totalExpenses = inexSum( expensesFromRange );
    float totalIncomes = inexSum( incomesFromRange );
    displayTitle("Incomes: ", false,false);
    showInEx( incomesFromRange );
    displayTitle("Expenses: ", false,false);
    showInEx( expensesFromRange );
    cout<< "total incomes: ";
    cout<< setw(1) <<'\t'<< totalIncomes <<endl;
    cout<< "total expenses: ";
    cout<< totalExpenses <<endl;
    cout<< "--------------------------------" <<endl;
    cout<< "Balance: " << '\t'<< totalIncomes - totalExpenses << endl;
}
void InExMenager::currentMonthBalance() {
    Date date;
    int rangeEnd = date.getCurrentDateInt();
    int rangeBegin = (rangeEnd - rangeEnd%100 ) + 1;
    string balanceRange = "(" + date.dateStringFormat( rangeBegin ) + ") -- (" + date.dateStringFormat( rangeEnd ) + ")";
    displayTitle( balanceRange, false,false );
    balance( rangeBegin, rangeEnd );
}
void InExMenager::previousMonthBalance(){
    Date date;
    int today = date.getCurrentDateInt();
    int day = today%100;
    int currentMonth = (today/100)%100;
    int rangeBegin,rangeEnd;
    if( currentMonth > 1 ){
        rangeBegin = (today - 100)-day+1;
        rangeEnd =  rangeBegin -1 + date.howManyDays( date.dateStringFormat( rangeBegin ) );
    }
    else{
        rangeBegin = (today - 10000) - today%10000+ 1201;
        rangeEnd = rangeBegin + 30;
    }
    string balanceRange = "(" + date.dateStringFormat( rangeBegin ) + ") -- (" + date.dateStringFormat( rangeEnd ) + ")";
    displayTitle( balanceRange, false,false );
    balance( rangeBegin, rangeEnd );
}
void InExMenager::rangeMonthBalance() {
    Date date;
    cout<<"Begin of the range: ";
    int rangeBegin = date.setInExDate();
    cout<<"End of the range: ";
    int rangeEnd = date.setInExDate();
    if( rangeBegin > rangeEnd )
        swap( rangeBegin, rangeEnd );
    string balanceRange = "(" + date.dateStringFormat( rangeBegin ) + ") -- (" + date.dateStringFormat( rangeEnd ) + ")";
    displayTitle( balanceRange, false,false );
    balance( rangeBegin, rangeEnd );
}


