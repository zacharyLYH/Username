#include <iostream>
#include <string>
#include "Header.h"
using namespace std;

int main(int argc, char const *argv[])
{
    Header v;
    string first = "Zachary"; string last = "Lee"; string middle = ""; string suffix = "";
    int firstTest[] = {1,1,0,0};
    v.clauseCounter(first,last,middle,suffix);
    cout<<"Test 1: ";
    for(int i = 0; i <= 3; i++){
        if(v.clause[i] != firstTest[i]){
            cout<<"Fail at %d"<< i <<endl;
            cout<< v.clause[i]<< " != "<< firstTest[i]<<endl;
            return 1;
        }
    }
    cout<<"Passed"<<endl;
    Header v1;
     first = "Yi Yao";  last = "Cheong";  middle = "";  suffix = "";
    int second[] = {2,1,0,0};
    v1.clauseCounter(first,last,middle,suffix);
    cout<<"Test 2: ";
    for(int i = 0; i <= 3; i++){
        if(v1.clause[i] != second[i]){
            cout<<"Fail at "<< i <<endl;
            cout<< v1.clause[i]<< " != "<< second[i]<<endl;
            return 1;
        }
    }
    cout<<"Passed"<<endl;
    Header v2;
     first = "Zachary";  last = "Lee";  middle = "Hi";  suffix = "";
    int third[] = {1,1,1,0};
    v2.clauseCounter(first,last,middle,suffix);
    cout<<"Test 3: ";
    for(int i = 0; i <= 3; i++){
        if(v2.clause[i] != third[i]){
            cout<<"Fail at "<< i <<endl;
            cout<< v2.clause[i]<< " != "<< third[i]<<endl;
            return 1;
        }
    }
    cout<<"Passed"<<endl;
    Header v3;
     first = "Zachary";  last = "Lee";  middle = "Hi";  suffix = "Jr";
    int fourth[] = {1,1,1,1};
    v3.clauseCounter(first,last,middle,suffix);
    cout<<"Test 4: ";
    for(int i = 0; i <= 3; i++){
        if(v3.clause[i] != fourth[i]){
            cout<<"Fail at "<< i <<endl;
            cout<< v3.clause[i]<< " != "<< fourth[i]<<endl;
            return 1;
        }
    }
    cout<<"Passed"<<endl;
    first = "Zachary";
    last = "Lee";
    Header v4;
    v4.twoClause(first , last);
    cout<<"Passed"<<endl;

    return 0;
}
