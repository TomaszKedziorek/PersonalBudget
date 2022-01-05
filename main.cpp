#include <iostream>
#include "user.h"
#include "usersFile.h"
#include "userMenager.h"
#include "inex.h"
#include "inexFile.h"

using namespace std;
int main()
{   cout<< "InEx class------" <<endl;
    InEx inex(1,1,20220104,"prad",-256.25);
    inex.showInExInfo();

    return 0;
}

int pmain()
{   cout<< "User class------" <<endl;
    UserMenager userMenager( "users.xml" );
    //userMenager.registration();

    int id = userMenager.signIn( );
    //userMenager.changePassword( id );
    id = userMenager.signOut( );
    //cout<< id << " -------------" <<endl;
    userMenager.showAllUsers();

    return 0;
}
int _main()
{   cout<< "User class------" <<endl;
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
