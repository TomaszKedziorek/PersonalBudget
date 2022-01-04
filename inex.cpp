#include "inex.h"

using namespace std;

InEx::InEx( int userID, string name, string surname, string login, string password ) {
        this -> userID = userID;
        this -> name = name;
        this -> surname = surname;
        this -> login = login;
        this -> password = password;
}

void InEx::setLogin( string userLogin ) {
    login = userLogin;
}

void InEx::setPassword( string userPassword ) {
    password = userPassword;
}

void InEx::setID( int ID_user ) {
    userID = ID_user;
}
void InEx::setName( string userName ){
    name = userName;
}
void InEx::setSurname( string userSurname ){
    surname = userSurname;
}

string InEx::getLogin() {
    return login;
}

string InEx::getPassword() {
    return password;
}

string InEx::getName() {
    return name;
}

string InEx::getSurname() {
    return surname;
}
int InEx::getID() {
    return userID;
}

void InEx::showUserData() {
    cout<< login << " " << password <<endl;
    cout<< name << " " <<surname <<endl;
    cout<< "ID: "<< userID <<endl;
}
