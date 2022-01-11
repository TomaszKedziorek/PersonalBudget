#include "userMenager.h"
#include "commonFunk.h"

using namespace std;
UserMenager::UserMenager( string usersFileName ) :usersFile( usersFileName ) {
    loadUsersFromFile();
};

void UserMenager::loadUsersFromFile() {
    users = usersFile.loadUsersFile(  );
}

bool UserMenager::checkPassword( string userPassword ) {
    return true;
}

void UserMenager::registration(  ) {
    string userLogin ="", userPassword ="", userSurname ="", userName ="";
    int userID = 0;
    displayTitle( "   Registration" );
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

    userID = usersFile.getLastUserID() + 1;
    usersFile.setLastUserID( userID );
    User newUser(  userID, userName, userSurname, userLogin, userPassword );

    users.push_back( newUser );

    usersFile.addNewUser( newUser );
    cout<< "The user " << userLogin << " has been registered." <<endl;

    Sleep(1000);
}

int UserMenager::signIn(  ) {
    string userLogin ="", userPassword ="";
    bool user = false;
    int unsigned i = 0;
    int attempt = 3;
    displayTitle( "   Sign In" );
    while( attempt>0 ) {
        displayTitle( "Login: ", false, false);
        getline( cin, userLogin );
        displayTitle( "Password: ", false, false);
        getline( cin, userPassword );

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
            cout<<"The given login or password is incorrect."<< attempt << " attempts left."<<endl;
        } else
            break;
    }

    if( user == true ) {
        return users[i].getID();
    } else {
        cout<<"Login failed."<<endl;
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
    displayTitle( "   Change password" );
    displayTitle( "Type new password: ", false, false);
    vector<User>::iterator loggedUser = findUserByID( IDLoggedUser );
    bool correct = false;
    do {
        newPassword = typeStringData();
        correct = checkPassword( newPassword );
        if( !correct )
            cout<< "Password must contain at least 8 chars. Password: " <<endl;
    } while( !correct );
    (*loggedUser).setPassword( newPassword );
    usersFile.changePassword( (*loggedUser).getID(), (*loggedUser).getPassword()  );
    cout<<"Password has been changed.";
    Sleep(1000);

}

int UserMenager::signOut() {
    displayTitle("Logging out...");
    Sleep(500);
    return 0;
}

void UserMenager::showAllUsers() {
    for( unsigned int i=0; i< users.size(); i++ )
        users[i].showUserData();
}
