#include "personalBudget.h"

PersonalBudget::PersonalBudget( string usersFileName, string incomesFileName, string expensesFileName )
    :userMenager( usersFileName ), INCOMES_FILE_NAME( incomesFileName ),EXPENSES_FILE_NAME( expensesFileName ) {
    inexMenager = NULL;
}
string PersonalBudget::getIncomesFileName() {
    return INCOMES_FILE_NAME;
}
string PersonalBudget::getExpensesFileName() {
    return EXPENSES_FILE_NAME;
}
void PersonalBudget::registration() {
    userMenager.registration();
}

int PersonalBudget::signIn() {
    int IDuser = userMenager.signIn();
    if ( IDuser > 0 ) {
        inexMenager = new InExMenager( IDuser, getIncomesFileName(), getExpensesFileName() );
    }
    return IDuser;
}
void PersonalBudget::changePassword( int IDLoggedUser ) {
    userMenager.changePassword( IDLoggedUser );
}
int PersonalBudget::signOut() {
    int IDuser = userMenager.signOut();
    delete inexMenager;
    inexMenager = NULL;
    return IDuser;
}

void PersonalBudget::addNewTodayIncome() {
    inexMenager -> addNewTodayIncome();
}
void PersonalBudget::addNewTodayExpense() {
    inexMenager -> addNewTodayExpense();
}
void PersonalBudget::addNewDiffDateIncome() {
    inexMenager -> addNewDiffDateIncome();
}
void PersonalBudget::addNewDiffDateExpense() {
    inexMenager -> addNewDiffDateExpense();
}

void PersonalBudget::addNewIncome() {
    char choice3 ='p';
    while( choice3 != '3' ) {
        displayTitle( "   Add new income" );
        cout<< "1. Today's date" <<endl;
        cout<< "2. Different date" <<endl;
        cout<< "3. Back to menu" <<endl;
        cout<< "Your choice: ";
        cin>> choice3;
        switch( choice3 ) {
        case '1':
            cleanBuffer();
            addNewTodayIncome();
            break;
        case '2':
            cleanBuffer();
            addNewDiffDateIncome();
            break;
        case '3':
            break;
        }
    }
}

void PersonalBudget::addNewExpense() {
    char choice3 ='p';
    while( choice3 != '3' ) {
        displayTitle( "   Add new expense" );
        cout<< "1. Today's date" <<endl;
        cout<< "2. Different date" <<endl;
        cout<< "3. Back to menu" <<endl;
        cout<< "Your choice: ";
        cin>> choice3;
        switch( choice3 ) {
        case '1':
            cleanBuffer();
            addNewTodayExpense();
            break;
        case '2':
            cleanBuffer();
            addNewDiffDateExpense();
            break;
        case '3':
            break;
        }
    }
}
void PersonalBudget::currentMonthBalance(){
    displayTitle( "   Current month balance" );
    inexMenager -> currentMonthBalance();
    backToMenu();
}
void PersonalBudget::previousMonthBalance(){
    displayTitle( "   Previous month balance" );
    inexMenager -> previousMonthBalance();
    backToMenu();
}
void PersonalBudget::rangeMonthBalance(){
    displayTitle( "   Selected period balance" );
    inexMenager -> rangeMonthBalance();
    backToMenu();
}
