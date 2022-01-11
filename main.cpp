#include <iostream>
#include "user.h"
#include "usersFile.h"
#include "userMenager.h"
#include "inex.h"
#include "inexFile.h"
#include "date.h"
#include "inexMenager.h"
#include "bilansMenager.h"

using namespace std;
int main() {
    InExMenager inexMenager( 1 );
    //inexMenager.currentMonthBalance( );
    inexMenager.rangeMonthBalance();
    //inexMenager.previousMonthBalance();
    /*
    Date date1;
    cout<< date1.getCurrentDateInt() <<endl;
    cout<< date1.dateStringFormat( date1.getCurrentDateInt() ) <<endl;
    cout<< date1.dateStringFormat( 20002501 ) <<endl;
    cout<< date1.dateIntFormat( "2000-25-01" ) <<endl;
    string date2 = "2012-02-29";
    if( date1.checkDateCorrectness(date2) ){
        cout<< date2 <<endl;
    }else{
        cout<<"Please type date in format: yyyy-mm-dd" <<endl;
    }
    */
    return 0;
}

int omain() {
    cout<< "InEx class------" <<endl;
    InExFile inexFile( "incomes.xml", "expenses.xml" );
    vector<InEx> expenses = inexFile.loadInExFile( "expenses.xml", 1 );
    vector<InEx> incomes = inexFile.loadInExFile( "incomes.xml", 1 );
    cout<< "expenses: " <<endl;
    inexFile.showAllInEx( expenses );
    cout<< "incomes: " <<endl;
    inexFile.showAllInEx( incomes );
    cout<< "lasrExID: "  <<inexFile.getLastExpensesID() << " lasrInID: " << inexFile.getLastIncomesID() <<endl;
    InEx newExpens( inexFile.getLastExpensesID() + 1, 1, 20220107, "woda", 356.91 );
    inexFile.addNewInEx( inexFile.getExpensesFileName(), newExpens );
    return 0;
}

int pmain() {
    cout<< "User class------" <<endl;
    UserMenager userMenager( "users.xml" );
    //userMenager.registration();

    int id = userMenager.signIn( );
    //userMenager.changePassword( id );
    id = userMenager.signOut( );
    //cout<< id << " -------------" <<endl;
    userMenager.showAllUsers();

    return 0;
}
int _main() {
    cout<< "User class------" <<endl;
    User user1(10,"rob","roy","free","scotland");
    user1.showUserData();
    user1.setPassword( "scotlandTheBrave");
    user1.showUserData();
    User user2;
    user2.showUserData();
    cout<< "-------------" <<endl;
    cout<< "UserFile class------" <<endl;
    UsersFile usersFile( "users.xml");

    vector<User> allUsers = usersFile.loadUsersFile( );
    if( allUsers.empty() )
        cout<< "Plik nie istnieje. drugi raz mowie!" <<endl;
    else
        usersFile.showAllUsers( allUsers );
    cout<<"addNewUser:"<<endl;
    //usersFile.addNewUser( user1 );
    cout<< "-------------" << usersFile.getLastUserID() <<endl;
    usersFile.changePassword( 5, "nibelungi");
    return 0;
}
