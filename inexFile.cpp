#include "inexFile.h"

InExFile::InExFile( string incomesFileName , string expensesFileName )
    : INCOMES_FILE_NAME( incomesFileName ), EXPENSES_FILE_NAME( expensesFileName ) {
}
string InExFile::getIncomesFileName() {
    return INCOMES_FILE_NAME;
}
string InExFile::getExpensesFileName() {
    return EXPENSES_FILE_NAME;
}
