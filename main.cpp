#include <iostream>
#include "user.h"
#include "usersFile.h"

using namespace std;

int main()
{   cout<< "User class------" <<endl;
    User user1(1,"rob","roy","free","scotland");
    user1.showUserData();
    user1.setPassword( "scotlandTheBrave");
    user1.showUserData();
    User user2;
    user2.showUserData();
    cout<< "-------------" <<endl;
    cout<< "UserFile class------" <<endl;
    UsersFile usersFile;
    vector<User> allUsers = usersFile.loadUsersFile( );
    usersFile.showAllUsers( allUsers );
    cout<< "-------------" <<endl;
    return 0;
}
