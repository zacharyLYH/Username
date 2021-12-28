#include <iostream>
#include "Header.h"
using namespace std;

bool validateGeneratedUsername(string usr){
      int validate = 0;
      for(int i = 0; i <= 7; i++){
        if(isalpha(usr[i])){
            validate++;
        }
      }
      if(validate != 8){
        return false;
      }
      return true;
}

int changeUsername(Header v, string name){
    if(v.checkExist(name) == true){
        string oriUsrName = v.returnUsername(name);
        string newUsrName = "aaaaaaaa";
        cout<<"\nTo go back, type precisely EXIT. Imprecise spelling will be treated as an intended username input.";
        cout<<"\nUsername found. Prescribed username was: "<< oriUsrName <<endl;
        cout<<"\nEnter desired new username: ";
        cin >> newUsrName;
        if(newUsrName == "EXIT"){
            return 1;
        }else if(!validateGeneratedUsername(newUsrName)){
            cout << "Bad username given. Names must be exactly 8 characters long. Retrying."<<endl;
            changeUsername(v, name);
        }else if(!v.checkExist(newUsrName)){
            cout<<"This username "<<newUsrName<<" has been taken. Please reselect another username."<<endl;
            changeUsername(v, name);
        } else {
            v.write(newUsrName, name);
            v.receipt(newUsrName, name);
        }
    }else{
        cout<<"No such name is in our database. Please check the spelling."<<endl;
        return 1;
    }
    return 0;
}

int deleteUsername(Header v, string username){
    if(v.checkExist(username) == true){

    }
}

void Header::admin(){
    int operation = 0;
    Header v;
    cout<<"What operation would you be performing today?"<<endl;
    cout<<"1)Changing username\n2)Delete a user\n"<<endl;
    cin >> operation;
    if(operation == 1){
        string name;
        cout<<"Enter name of person: ";
        cin >> name;
        if(changeUsername(v, name) == 1){
            admin();
        }
    }else if(operation == 2){
        string username;
        cout<<"Enter the username to delete: ";
        cin >> username;
        if(deleteUsername(v, username) == 1){
            admin();
        }
    }

}