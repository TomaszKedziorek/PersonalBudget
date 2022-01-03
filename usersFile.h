#ifndef USERSFILE_H
#define USERSFILE_H
#include <vector>
#include "user.h"
#include "Markup.h"
using namespace std;

class UsersFile {
    const string USERS_FILE_NAME;
    CMarkup xmlUser;
    int lastUserID = 0;

    string getUsersFileName();
    void setLastUserID( int lastID );
public:
    UsersFile( string usersFileName = "users.xml" );
    vector<User> loadUsersFile();

    int getLastUserID();
    void showAllUsers( vector<User> &allUsers );
    void addNewUser( User newUser );
    //void saveAfterPasswordChange ( string userOneLineData,  int userID  );
};

#endif // USERSFILE_H
