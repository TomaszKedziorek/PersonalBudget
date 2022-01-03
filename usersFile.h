#ifndef USERSFILE_H
#define USERSFILE_H
#include <vector>
#include "user.h"
#include "Markup.h"
using namespace std;

class UsersFile {
    const string USERS_FILE_NAME;
    string getUsersFileName();
    CMarkup xmlUser;

public:
    UsersFile( string usersFileName = "users.xml" );
    vector<User> loadUsersFile();
    void showAllUsers( vector<User> &allUsers );
    //void saveNewUser( string userOneLineData );
    //void saveAfterPasswordChange ( string userOneLineData,  int userID  );
};

#endif // USERSFILE_H
