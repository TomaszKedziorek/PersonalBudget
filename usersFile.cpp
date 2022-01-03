#include "usersFile.h"

UsersFile::UsersFile( string usersFileName )
    : USERS_FILE_NAME( usersFileName ) {
}

string UsersFile::getUsersFileName() {
    return USERS_FILE_NAME;
}

vector<User> UsersFile::loadUsersFile( ) {
    vector<User> loadedUsers;
    //CMarkup xmlUser;
    bool fileExists = xmlUser.Load( "users.xml" );

    if (!fileExists) {
        cout<< "Plik nie istnieje." <<endl;
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
        return loadedUsers;
    }
}

void UsersFile::showAllUsers( vector<User> &allUsers ){
    for( unsigned int i=0; i<allUsers.size(); i++ ) {
        allUsers[i].showUserData();
        cout<< "---------" <<endl;
    }
}
