#ifndef COMMONFUNK_H
#define COMMONFUNK_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <conio.h>
#include <windows.h>
using namespace std;

void displayTitle( string title, bool showLine = true, bool screenClear = true );
string IntToString( int n );
string typeStringData();
string floatToString( float n );
void cleanBuffer();
void backToMenu();
#endif // COMMONFUNK_H
