#include "usersFile.h"

UsersFile::UsersFile( string usersFileName )
    : USERS_FILE_NAME( usersFileName ) {
}

string UsersFile::getUsersFileName() {
    return USERS_FILE_NAME;
}
void UsersFile::setLastUserID( int lastID ){
    lastUserID = lastID;
}
int UsersFile::getLastUserID(){
    return lastUserID;
}

vector<User> UsersFile::loadUsersFile( ) {
    vector<User> loadedUsers;
    bool fileExists = xmlUser.Load( getUsersFileName() );

    if (!fileExists) {
        cout<< "Plik nie istnieje." <<endl;
        setLastUserID( 0 );
    } else {
        xmlUser.FindElem();
        xmlUser.IntoElem();
        while( xmlUser.FindElem( "User" ) ) {
            User newUser;
            xmlUser.IntoElem();
            xmlUser.FindElem("UserID");
            newUser.setID( atoi( MCD_2PCSZ(xmlUser.GetData()) ));
            xmlUser.FindElem("Login");
            newUser.setLogin( xmlUser.GetData() );
            xmlUser.FindElem("Password");
            newUser.setPassword( xmlUser.GetData() );
            xmlUser.FindElem("Name");
            newUser.setName( xmlUser.GetData() );
            xmlUser.FindElem("Surname");
            newUser.setSurname( xmlUser.GetData() );
            xmlUser.OutOfElem();
            loadedUsers.push_back( newUser );
        }
        setLastUserID( loadedUsers.back().getID() );
    }
    return loadedUsers;
}
void UsersFile::addNewUser( User newUser ){
    bool fileExists = xmlUser.Load( getUsersFileName() );
    if (!fileExists)
    {
        xmlUser.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlUser.AddElem("Users");
    }
    xmlUser.FindElem();
    xmlUser.IntoElem();
    xmlUser.AddElem( "User" );
    xmlUser.IntoElem();
    xmlUser.AddElem( "UserID", newUser.getID() );
    xmlUser.AddElem( "Login", newUser.getLogin() );
    xmlUser.AddElem( "Password", newUser.getPassword() );
    xmlUser.AddElem( "Name", newUser.getName() );
    xmlUser.AddElem( "Surname", newUser.getSurname() );
    xmlUser.Save( getUsersFileName() );
}

void UsersFile::showAllUsers( vector<User> &allUsers ){
    for( unsigned int i=0; i<allUsers.size(); i++ ) {
        allUsers[i].showUserData();
        cout<< "---------" <<endl;
    }
}
