#include <iostream>
#include "user.h"
#include "usersFile.h"
#include "userMenager.h"
#include "inex.h"
#include "inexFile.h"
#include "date.h"
#include "inexMenager.h"
#include "personalBudget.h"

using namespace std;
int main() {
    char choice1='p', choise2='p';
    int IDuser = 0;
    PersonalBudget personalBudget( "users1.xml" , "incomes.xml", "expenses.xml");
    while( true ) {
        if( IDuser == 0) {
            displayTitle( "   Personal Budget" );
            cout<< "1. Registration." <<endl;
            cout<< "2. Sign In." <<endl;
            cout<< "9. Exit." <<endl;
            cout<< "Your choice: ";
            cin>> choice1;

            switch( choice1 ) {
            case '1':
                personalBudget.registration();
                break;

            case '2':
                IDuser = personalBudget.signIn();
                while( IDuser > 0) {
                    displayTitle( "   Personal Budget", true, true );
                    displayTitle( "Logged: ", false, false );
                    cout<<  "ID: " << IDuser;
                    displayTitle( "", true, false );
                    cout<< "1. Add New Income" <<endl;
                    cout<< "2. Add New Expense" <<endl;
                    cout<< "3. Current month balance" <<endl;
                    cout<< "4. Previous month balance" <<endl;
                    cout<< "5. Selected period balance" <<endl;
                    cout<< "8. Change password" <<endl;
                    cout<< "9. Sign out" <<endl;
                    cout<< "Your choice: ";

                    cin>> choise2;
                    switch( choise2 ) {
                    case '1':
                        personalBudget.addNewIncome();
                        break;
                    case '2':
                        personalBudget.addNewExpense();
                        break;
                    case '3':
                        personalBudget.currentMonthBalance();
                        break;
                    case '4':
                        personalBudget.previousMonthBalance();
                        break;
                    case '5':
                        personalBudget.rangeMonthBalance();
                        break;
                    case '8':
                        personalBudget.changePassword( IDuser );
                        break;
                    case '9':
                        IDuser = personalBudget.signOut();
                        break;
                    }
                }
                break;

            case '9':
                exit( 0 );
                break;
            }
        }
    }
    return 0;
}

