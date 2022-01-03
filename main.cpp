#include <iostream>
#include "user.h"
#include "usersFile.h"

using namespace std;

int main()
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
