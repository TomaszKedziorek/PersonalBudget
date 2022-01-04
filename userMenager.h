#ifndef USERMENAGER_H
#define USERMENAGER_H
#include <iostream>
#include <conio.h>   //getch
#include <windows.h> //exit(0)
#include "user.h"
#include "usersFile.h"
#include <vector>

using namespace std;

class UserMenager {
    vector<User> users;
    UsersFile usersFile;

    void loadUsersFromFile();
    bool checkPassword( string userPassword );
    vector<User>::iterator findUserByID( int IDLoggedUser );
public:
    UserMenager( string usersFileName ="users.xml" );
    void registration();
    int signIn();
    void changePassword( int IDLoggedUser  );
    int signOut();
    void showAllUsers();
};

#endif // USERMENAGER_H
