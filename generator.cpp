#include <iostream>
#include <fstream>
#include "Header.h"
using namespace std;

int count_digit(int number) {
   int count = 0;
   while(number != 0) {
      number = number / 10;
      count++;
   }
   return count;
}

void errormsg(){
      cout<<"\n\nHello there, it seems like we're having trouble assigning you a username at this moment."<<endl;
      cout<<"An admin with admin functions will assist you"<<endl;
}

bool validateGeneratedUsernames(string usr){
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

void Header::clauseCounter(string first, string last, string middle, string suffix){
    int ffirst = 1;
    int llast = 1;
    int mmiddle = 0;
    int ssuffix = 0;
    for(int i = 0; i <= first.length()-1 ; i++){
        if(first[i] == ' '){
           storeNum(++ffirst, 0);
        }
    }
    for(int i = 0; i <= last.length()-1 ; i++){
        if(last[i] == ' '){
          storeNum(++llast, 1);
        }
    }
    if(middle.length()!=0){
      mmiddle = 1;
      storeNum(1,2);
      for(int i = 0; i <= middle.length()-1 ; i++){
        if(middle[i] == ' '){
          storeNum(++mmiddle, 2);
        }
      }
    }
    if(suffix.length() != 0){
      ssuffix = 1;
      storeNum(1,3);
      for(int i = 0; i <= suffix.length()-1 ; i++){
        if(suffix[i] == ' '){
          storeNum(++ssuffix, 3);
        }
      }
    }
}

void Header::twoClause(string first, string last, bool cameFromOthers){
    string givenName = first + " " + last;
    string ret = "aaaaaaaa";
    bool success = false;
    if(last.size() + first.size() >= 8){//DEBUG WHAT IS FIRST AND LAST FOR LAST NAME DOMINATE
        int firstSize = first.size()-1;
        int lastSize = last.size();
        int firstTraverser = 0;
        while(firstSize != 0 || !success){
            for(int i = 0; i <= 7; i++){
              if(i <= lastSize){
                  ret[i] = last[i];
              }else{
                  ret[i] = first[firstTraverser];
                  firstTraverser++;
              }          
            }
            cout<<"first: "<<ret<<endl;
            if(!validateGeneratedUsernames(ret)){
              break;
              return;
            }
            cout<<"first"<<endl;
            if(checkExist(ret) == true && sendtoUser(ret, givenName)){
              write(ret, givenName);
              receipt(ret, givenName);
              success = true;
              break;
              return;
            }
          firstTraverser = 0;
          firstSize--;
          lastSize--;
        }
        int firstSize2 = first.size()-1;
        int lastSize2 = last.size();
        int lastTraverser = 0;
        while(lastSize2 != 0 || !success){
            for(int i = 0; i <= 7; i++){//fill up to first size only. 
              if(i <= firstSize2){
                  ret[i] = first[i];
              }else{
                  if(lastTraverser <= last.size()){
                      ret[i] = last[lastTraverser];
                      lastTraverser++;
                  }
              }          
            }
            if(!validateGeneratedUsernames(ret)){
              break;
              return;
            }
            cout<<"second"<<endl;
            if(checkExist(ret) == true && sendtoUser(ret, givenName)){            
              write(ret, givenName);
              receipt(ret, givenName);
              success = true;
              break;
              return;
            }
          lastTraverser = 0;
          firstSize--;
          lastSize2--;
        }
      }else if(givenName.size()-1<= 7){
        int missing = 8 - givenName.size();
        string date[3];
        string input;
        string birthday;
        cout<<"Your name is too short for the 8 letter username standard.";
        cout<<" We'll need your birthday. Please enter exactly your birthday (numerically) eg. 09/13/1999: " ;
        cin >> input;
        //ADD A VALIDATOR FOR BIRTHDATE
        int skip = 0;
        for(int i = 0; i<=input.size(); i++){
          if(isdigit(input[i])){
              date[skip] = input[i];
              birthday += input[i];
          }else{
              skip++;
          }
        }
        ret += first + last;
        //BIRTHDATE CONFIG NOT NEARLY VERSATILE ENOUGH
        while(int j = 3 != 0 || !success){
            if(8-birthday.size() <= 2){
              ret += first + last;
              ret[6] = date[0][0];
              ret[7] = date[0][1];
            }else if(8-birthday.size() <= 4){
              ret += first + last;
              ret[4] = date[0][0];
              ret[5] = date[0][1];
              ret[6] = date[1][0];
              ret[7] = date[1][1];
            }else if(8-birthday.size() <= 6){
              ret += first + last;
              ret[2] = date[0][0];
              ret[3] = date[0][1];
              ret[4] = date[1][0];
              ret[5] = date[1][1];
              ret[6] = date[2][2];
              ret[7] = date[2][3];
            }else{

            }
            if(!validateGeneratedUsernames(ret)){
              break;
              return;
            }
            if(checkExist(ret) == true && sendtoUser(ret, givenName)){
              write(ret, givenName);
              receipt(ret, givenName);
              success = true;
              break;
              return;
            }
            j--;
        }
      }
    if(!success && cameFromOthers == false){
        errormsg();
    } 
}

void Header::threeClause(string first, string last, string middle){
    twoClause(first, last, true);
    string givenName = first + " " + last + " " + middle;
    string ret = "aaaaaaaa";
    bool success = false;
    if(givenName.length()-2 >= 8){

    }else if(givenName.length()-2 <= 8){

    }
}