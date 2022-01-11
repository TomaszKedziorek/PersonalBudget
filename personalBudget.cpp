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
void PersonalBudget::registration(){
    userMenager.registration();
}

int PersonalBudget::signIn(){
    int IDuser = userMenager.signIn();
    if ( IDuser > 0 ) {
        inexMenager = new InExMenager( IDuser, getIncomesFileName(), getExpensesFileName() );
    }
    return IDuser;
}
void PersonalBudget::changePassword( int IDLoggedUser ){
    userMenager.changePassword( IDLoggedUser );
}
int PersonalBudget::signOut(){
    int IDuser = userMenager.signOut();
    delete inexMenager;
    inexMenager = NULL;
    return IDuser;
}
