#include "inexFile.h"

InExFile::InExFile( string incomesFileName, string expensesFileName )
    : INCOMES_FILE_NAME( incomesFileName ), EXPENSES_FILE_NAME( expensesFileName ) {
}
string InExFile::getIncomesFileName() {
    return INCOMES_FILE_NAME;
}
string InExFile::getExpensesFileName() {
    return EXPENSES_FILE_NAME;
}
void InExFile::setLastIncomesID( int lastInID ) {
    lastIncomesID = lastInID;
}
void InExFile::setLastExpensesID( int lastExID ) {
    lastExpensesID = lastExID;
}
int InExFile::getLastIncomesID() {
    return lastIncomesID;
}
int InExFile::getLastExpensesID() {
    return lastExpensesID;
}

void InExFile::setBothInExLastID( string inexFileName, int lastID ) {
    if( inexFileName == getIncomesFileName() )
        setLastIncomesID( lastID );
    else
        setLastExpensesID( lastID );
}

vector<InEx> InExFile::loadInExFile( string inexFileName, int loggedUserID ) {
    vector<InEx> loadedInEx;
    bool fileExists = xmlInEx.Load( inexFileName );
    int lastInExID = 0;
    if (!fileExists) {
        cout<< "Flie does not exist." <<endl;
        setBothInExLastID( inexFileName, lastInExID );
    } else {
        xmlInEx.FindElem();
        xmlInEx.IntoElem();
        while( xmlInEx.FindElem( "NewInEx" ) ) {
            xmlInEx.FindChildElem( "UserInExID" );
            if ( atoi( MCD_2PCSZ( xmlInEx.GetChildData() ) ) == loggedUserID ) {
                InEx newInEx;
                xmlInEx.ResetChildPos();
                xmlInEx.FindChildElem("InExID");
                lastInExID = atoi( MCD_2PCSZ(xmlInEx.GetChildData()) );
                newInEx.setInExID( atoi( MCD_2PCSZ(xmlInEx.GetChildData()) ));
                xmlInEx.FindChildElem("UserInExID");
                newInEx.setUserInExID( atoi( MCD_2PCSZ(xmlInEx.GetChildData()) ));
                xmlInEx.FindChildElem("Date");
                newInEx.setDate( atoi( MCD_2PCSZ(xmlInEx.GetChildData()) ));
                xmlInEx.FindChildElem("Item");
                newInEx.setItem( xmlInEx.GetChildData() );
                xmlInEx.FindChildElem("Amount");
                newInEx.setAmount( atof( MCD_2PCSZ(xmlInEx.GetChildData()) ));
                loadedInEx.push_back( newInEx );
            } else {
                xmlInEx.ResetChildPos();
                xmlInEx.FindChildElem("InExID");
                lastInExID = atoi( MCD_2PCSZ(xmlInEx.GetChildData()) );
            }
        }
        setBothInExLastID( inexFileName, lastInExID );
    }
    return loadedInEx;
}
void InExFile::addNewInEx( string inexFileName, InEx &newInEx ) {
    bool fileExists = xmlInEx.Load( inexFileName );
    if (!fileExists) {
        xmlInEx.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlInEx.AddElem("InEx");
    }
    xmlInEx.FindElem();
    xmlInEx.IntoElem();
    xmlInEx.AddElem( "NewInEx" );
    xmlInEx.IntoElem();
    xmlInEx.AddElem( "InExID", newInEx.getInExID() );
    xmlInEx.AddElem( "UserInExID", newInEx.getUserInExID() );
    xmlInEx.AddElem( "Date", newInEx.getDate() );
    xmlInEx.AddElem( "Item", newInEx.getItem() );
    xmlInEx.AddElem( "Amount", newInEx.getAmount_str() );
    xmlInEx.Save( inexFileName );
}

void InExFile::showAllInEx( vector<InEx> &allInEx ) {
    for( unsigned int i=0; i<allInEx.size(); i++ ) {
        allInEx[i].showInExInfo();
        cout<< "---------" <<endl;
    }
}
