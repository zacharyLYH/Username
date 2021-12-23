#include <iostream>
#include "Header.h"
using namespace std;

int clauseSummer(Header v){
    int ret = 0;
    for(int i = 0; i <= 3; i++){
        ret += v.clause[i];
    }
    return ret;
}

void getInputs(string &first, string &last, string &middle, string &suffix){
    cout << "First name: " ;
    getline(cin, first);
    cout << "Last name: " ;
    getline(cin, last);
    int yesNo;
    cout << "Do you have a middle name? (1 for YES, 0 for NO): " ;
    cin >> yesNo;
    if(yesNo == 1){
        cout<< "Please enter your middle name: " ;
        getline(cin, middle);
        cout<< '\n'; 
    } else{
        middle = "";
    }
    cout << "Do you have a suffix name? (1 for YES, 0 for NO): " ;
    cin >> yesNo;
    if(yesNo == 1){
        cout<< "Please enter your suffix name: " ;
        getline(cin, last);
        cout<< '\n'; 
    } else{
        suffix = "";
    }
}

int main(int argc, char const *argv[])
{
    cout << "\t===============================" <<endl;
    string first;
    string last;
    string middle;
    string suffix;
    getInputs(first, last, middle, suffix);
    cout<< "\n\n" ;
    cout << "\t===============================" <<endl;
    cout << "\tChecking if name is well formed " <<endl;
    cout << "\t===============================" <<endl;
    Header v;
    int result = v.takeName(first,last,middle,suffix);
    if(result == 1){
        cout << "Bad name given" << endl;
        return 0;
    }else{
        string space = " ";
        cout<< "Good name given" <<endl;
        cout<< "The entered name: "<< first+space+ last+space+ middle+space+ suffix+space << endl;//TESTING
        cout << "\t===============================" <<endl;
        cout << "\t     Generating a username     " <<endl;
        cout << "\t===============================" <<endl;
        v.clauseCounter(first, last, middle, suffix);
    }

    
}
