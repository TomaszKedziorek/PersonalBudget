#ifndef COMMONFUNK_H
#define COMMONFUNK_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <conio.h>
#include <windows.h>
using namespace std;

void displayTitle( string title, bool showLine = true, bool screenClear = true );
void checkFileExistence( string fileName );
string IntToString( int n );
string typeStringData();
#endif // COMMONFUNK_H
