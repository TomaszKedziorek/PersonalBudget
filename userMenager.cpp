#include "userMenager.h"

using namespace std;
UserMenager::UserMenager( string usersFileName ) :userFile( usersFileName ) {
    loadUsersFromFile();
};

void UserMenager::loadUsersFromFile() {
    users = userFile.loadUsersFile(  );
}

bool UserMenager::checkPassword( string userPassword ) {
    return true;
}

void UserMenager::registration(  ) {
    string userLogin ="", userPassword ="", userSurname ="", userName ="";
    int userID = 0;
    //displayTitle( "   Rejestracja" );
    cout<< "Numbers of users: " << users.size() <<endl;
    cout<< "Login: " ;
    getline( cin, userLogin );
    unsigned int i = 0;
    do {
        if( userLogin == users[i].getLogin() ) {
            cout<<"The given login already exists. Enter a different login: " <<endl;
            getline( cin, userLogin );
            i=0;
        } else i++;

    } while( i<users.size() );
    bool correct = false;
    cout<< "Password: ";
    do {
        getline( cin, userPassword );
        correct = checkPassword( userPassword );
        if( !correct )
            cout<< "Password must contain at least 8 chars. Password: " <<endl;
    } while( !correct );
    cout<< "Name: ";
    getline( cin, userName );
    cout<< "Surname: ";
    getline( cin, userSurname);

    userID = userFile.getLastUserID() + 1;
    userFile.setLastUserID( userID );
    User newUser(  userID, userName, userSurname, userLogin, userPassword );

    users.push_back( newUser );

    userFile.addNewUser( newUser );
    cout<< "The user " << userLogin << " has been registered." <<endl;

    Sleep(1000);
}
/*
int UserMenager::signIn(  ) {
    string userLogin ="", userPassword ="";
    bool user = false;
    int unsigned i = 0;
    int attempt = 3;
    displayTitle( "   Logowanie" );
    while( attempt>0 ) {
        displayTitle( "Podaj  login: ", false, false);
        cin>> userLogin;
        displayTitle( "Podaj  haslo: ", false, false);
        cin>> userPassword;

        while( i<users.size()) {
            if( users[i].getLogin() != userLogin || users[i].getPassword() != userPassword ) {
                user = false;
                i++;
            } else {
                user = true;
                break;
            }
        }
        if( user == false) {
            system("cls");
            i=0;
            attempt--;
            cout<<"Podany login lub haslo jest nieprawidlowe. Pozostalo "<< attempt << " prob."<<endl;
        } else
            break;
    }

    if( user == true ) {
        return users[i].getID();
    } else {
        cout<<"Nie udaloa sie zalogowac."<<endl;
        Sleep(2000);
        return 0;
    }
}

vector<User>::iterator UserMenager::findUserByID( int IDLoggedUser ) {
    vector<User>::iterator itr = users.begin();
    vector<User>::iterator endOfVector = users.end();
    while( itr != endOfVector ) {
        if( itr-> getID() == IDLoggedUser )
            break;
        else
            ++itr;
    }
    return itr;
}

void UserMenager::changePassword( int IDLoggedUser  ) {
    string newPassword = "";
    displayTitle( "   Zmiana hasla" );
    displayTitle( "Podaj nowe haslo: ", false, false);
    vector<User>::iterator loggedUser = findUserByID( IDLoggedUser );
    cin>> newPassword;
    (*loggedUser).setPassword( newPassword );
    userFile.saveAfterPasswordChange ( (*loggedUser).changeUserDataToOneLine(), (*loggedUser).getID() );
    cout<<"Haslo zostalo zmienione.";
    Sleep(1000);

}

int UserMenager::signOut() {
    displayTitle("Wylogouwywanie...");
    Sleep(500);
    return 0;
}

void UserMenager::showAllUsers() {
    for( unsigned int i=0; i< users.size(); i++)
        users[i].showUserData();
}
*/
