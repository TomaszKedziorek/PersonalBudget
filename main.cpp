#include <iostream>
#include "user.h"
#include "usersFile.h"
#include "userMenager.h"
#include "inex.h"
#include "inexFile.h"
#include "date.h"
#include "inexMenager.h"
#include "personalBudget.h"

using namespace std;
int main() {
    char choice1, choise2;
    int IDuser = 0;
    PersonalBudget personalBudget;
    while( true ) {
        if( IDuser == 0) {
            displayTitle( "   Personal Budget" );
            cout<< "1. Registration." <<endl;
            cout<< "2. Sign In." <<endl;
            cout<< "9. Exit." <<endl;
            choice1 = getch();

            switch( choice1 ) {
            case '1':
                personalBudget.registration();
                break;

            case '2':
                IDuser = personalBudget.signIn();
                while( IDuser > 0) {
                    displayTitle( "   Personal Budget", true, true );
                    displayTitle( "Logged: ", false, false );
                    cout<<  "ID: " << IDuser;
                    displayTitle( "", true, false );
                    cout<< "1. Wyswitl wszystko." <<endl;
                    cout<< "2. Dodaj nowy kontakt." <<endl;
                    cout<< "3. Wyszukaj po imieniu." <<endl;
                    cout<< "4. Wyszukaj po nazwisku." <<endl;
                    cout<< "6. Edytuj kontakt." <<endl;
                    cout<< "7. Usun kontakt." <<endl;
                    cout<< "8. Zmien haslo." <<endl;
                    cout<< "9. Wyloguj sie." <<endl;
                    cout<< "Twoj wybor:";

                    choise2 = cin.get();

                    switch( choise2 ) {/*
                    case '1':
                        addressBook.showAllUserContacts();
                        break;
                    case '2':
                        addressBook.addNewContact();
                        break;
                    case '3':
                        addressBook.findContactByName();
                        break;
                    case '4':
                        addressBook.findContactBySurname();
                        break;
                    case '6':
                        addressBook.editContact();
                        break;
                    case '7':
                        addressBook.removeContact();
                        break;*/
                    case '8':
                        personalBudget.changePassword( IDuser );
                        break;
                    case '9':
                        IDuser = personalBudget.signOut();
                        break;
                    }
                }
                break;

            case '9':
                exit( 0 );
                break;
            }
        }
    }
    return 0;
}

