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
void InExFile::setLastIncomesID( int lastInID ){
    lastIncomesID = lastInID;
}
void InExFile::setLastExpensesID( int lastExID ){
    lastExpensesID = lastExID;
}
int InExFile::getLastIncomesID(){
    return lastIncomesID;
}
int InExFile::getLastExpensesID(){
    return lastExpensesID;
}

vector<InEx> InExFile::loadInExFile( string inexFileName ) {
    vector<InEx> loadedInEx;
    bool fileExists = xmlInEx.Load( inexFileName );

    if (!fileExists) {
        cout<< "Flie does not exist." <<endl;
        if( inexFileName == getIncomesFileName() )
            setLastIncomesID( 0 );
        else
            setLastExpensesID( 0 );
    } else {
        xmlInEx.FindElem();
        xmlInEx.IntoElem();
        while( xmlInEx.FindElem( "NewInEx" ) ) {
            InEx newInEx;

            xmlInEx.IntoElem();
            xmlInEx.FindElem("InExID");
            newInEx.setInExID( atoi( MCD_2PCSZ(xmlInEx.GetData()) ));
            xmlInEx.FindElem("UserInExID");
            newInEx.setUserInExID( atoi( MCD_2PCSZ(xmlInEx.GetData()) ));
            xmlInEx.FindElem("Date");
            newInEx.setDate( atoi( MCD_2PCSZ(xmlInEx.GetData()) ));
            xmlInEx.FindElem("Item");
            newInEx.setItem( xmlInEx.GetData() );
            xmlInEx.FindElem("Amount");
            newInEx.setAmount( atof( MCD_2PCSZ(xmlInEx.GetData()) ));
            xmlInEx.OutOfElem();
            loadedInEx.push_back( newInEx );
        }
        if( inexFileName == getIncomesFileName() )
            setLastIncomesID( loadedInEx.back().getInExID() );
        else
            setLastExpensesID( loadedInEx.back().getInExID() );

    }
    return loadedInEx;
}

void InExFile::showAllInEx( vector<InEx> &allInEx ){
    for( unsigned int i=0; i<allInEx.size(); i++ ) {
        allInEx[i].showInExInfo();
        cout<< "---------" <<endl;
    }
}
