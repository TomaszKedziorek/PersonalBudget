#include "commonFunk.h"
void displayTitle( string title, bool showLine, bool screenClear ) {
    if( screenClear == true )
        system("cls");

    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 10 );
    cout<< title <<endl;
    if( showLine == false )
        cout<<"";//endl;
    else
        cout<< "------------------------------------" <<endl;
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 15 );
}

string IntToString( int n ) {
    ostringstream ss;
    ss << n;
    string nstr=ss.str();
    return nstr;
}
string floatToString( float n ) {
    ostringstream ss;
    ss << n;
    string nstr=ss.str();
    return nstr;
}

string typeStringData() {
    string inputString = "";
    cin.ignore();
    getline( cin, inputString );
    return inputString;
}
void cleanBuffer(){
    string bufor ="";
    getline(cin,bufor );
}
void backToMenu(){
    cout<<" Press any key to continue"<<endl;
    getch();
}
