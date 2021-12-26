#include <iostream>
#include <fstream>
#include "Header.h"

bool Header::sendtoUser(string username, string givenName){
    int reg = 0;
    cout<<"\n\nWe've generated a username based on the given name: "<<givenName<<endl;
    cout<<"============="<<username<<"============="<<endl;
    cout<<"Enter 1 if you accept, or 0 if you don't!\t";
    cin >> reg;
    if(reg == 0){
        return false;
    }else if(reg == 1){
        return true;
    }else{
        cout<<"Invalid value, please reselect!\n\n"<<endl;
        return sendtoUser(username,givenName);
    }
}