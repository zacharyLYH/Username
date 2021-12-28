#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include "Header.h"
using namespace std;

string removeSpace(string name){
    string ret = name;
    ret.erase(remove(ret.begin(), ret.end(), ' '), ret.end());
    return ret;
}

int clauseSummer(Header v, int j){//Takes a Header object and the number of names to sum
    int ret = 0;
    for(int i = 0; i <= j-1; i++){
        ret += v.clause[i];
    }
    return ret;
}

void getInputs(string &first, string &last, string &middle, string &suffix){
    cout << "First name: " ;
    getline(cin, first);
    if(first == "admin"){
        Header v;
        v.admin();
        exit;//exists program 
    }
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

int main(int argc, char const *argv[]){

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
        cout<< "The entered name: "<< first+space+ last+space+ middle+space+ suffix+space << endl;//fails when middle is empty but suffix is filled
        cout << "\t===============================" <<endl;
        cout << "\t     Generating a username     " <<endl;
        cout << "\t===============================" <<endl;
        v.clauseCounter(first, last, middle, suffix);
        v.sumOfClause = clauseSummer(v,4);
    }
    first = removeSpace(first);
    cout<<first<<endl;
    last = removeSpace(last);
    cout<<last<<endl;
    if(clauseSummer(v,2) == 2 && middle == "" && suffix == ""){//Zachary Lee       
        v.twoClause(first, last);
    }else if(clauseSummer(v,2) == 3 && middle == "" && suffix == ""){//Lee Yi Hong
        string newFirst;
        for(int i = 0; i <= first.size() ; i++){
            if(newFirst == " "){
                //skip
            }else{
                newFirst += first[i];
            }
        }
        v.twoClause(newFirst,last);
    }else if(clauseSummer(v,3) == 3 && middle != "" && suffix == ""){//John H. Smith

    }else if(clauseSummer(v,3) == 3 && middle == "" && suffix != ""){//John Smith Jr.

    }else if(clauseSummer(v,3) == 4 && middle != "" && suffix != ""){//John H. Smith Jr.

    }
    
}
