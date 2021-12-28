#include <iostream>
#include "Header.h"

void Header::receipt(string username, string name){
    cout << "\n============================="<<endl;
    cout<<"Summary: "<<endl;
    cout<<"NAME: "<<name<<endl;
    cout<<"USERNAME: "<<username;
    cout << "\n============================="<<endl;
}