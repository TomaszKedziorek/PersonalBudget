#ifndef INEX_H
#define INEX_H
#include <iostream>

using namespace std;

class InEx {
    string login;
    string password;
    string name ;
    string surname;
    int userID;

public:
    InEx(int userID =0, string name ="",string surname ="",string login ="",string password ="" );
    void setLogin( string userlogin );
    void setPassword( string userPassword );
    void setName( string userName );
    void setSurname( string userSurname );
    void setID( int ID_user );
    string getLogin();
    string getPassword();
    string getName();
    string getSurname();
    int getID();
    void showUserData();
};


#endif // INEX_H
