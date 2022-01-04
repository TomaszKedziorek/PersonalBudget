#include "user.h"

using namespace std;

User::User( int userID, string name, string surname, string login, string password ) {
        this -> userID = userID;
        this -> name = name;
        this -> surname = surname;
        this -> login = login;
        this -> password = password;
}

void User::setLogin( string userLogin ) {
    login = userLogin;
}

void User::setPassword( string userPassword ) {
    password = userPassword;
}

void User::setID( int ID_user ) {
    userID = ID_user;
}
void User::setName( string userName ){
    name = userName;
}
void User::setSurname( string userSurname ){
    surname = userSurname;
}

string User::getLogin() {
    return login;
}

string User::getPassword() {
    return password;
}

string User::getName() {
    return name;
}

string User::getSurname() {
    return surname;
}
int User::getID() {
    return userID;
}

void User::showUserData() {
    cout<< login << " " << password <<endl;
    cout<< name << " " <<surname <<endl;
    cout<< "ID: "<< userID <<endl;
}
