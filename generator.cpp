#include <iostream>
#include <fstream>
#include "Header.h"
using namespace std;

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

void Header::twoClause(string first, string last){
    string givenName = first + " " + last;
    int j = 7;
    string ret = "aaaaaaaa";
    if(first.size() >= 8){//use first name predominantly
        for(int i = 0; i <= 7; i++){
          ret[i] = first[i];
        }
        if(checkExist(ret) == true && sendtoUser(ret, givenName)){
          write(ret, givenName);
          return;  
        }
        for(int i = 0; i <= 7; i++){
          ret[j] = last[i];
          j--;
          if(checkExist(ret) == true && sendtoUser(ret, givenName)){
            write(ret, givenName);
            break;
            return;  
          }
        }
    }else if(last.size() >= 8){//use last name predominantly
        ret = first;
        for(int i = 0; i <= last.size() && ret.size() != 8 ; i++){
            ret = last[i];
        }
        if(checkExist(ret) == true && sendtoUser(ret, givenName)){
          write(ret, givenName);
          return;  
        }
        for(int i = 0; i <= 7; i++){
          for(int j = 0; j <= i; j++){
            ret[i] = first[j];
          }
          ret[i] = last[j];
          if(checkExist(ret) == true && sendtoUser(ret, givenName)){
            write(ret, givenName);
            break;
            return;  
          }
        }
    }
      int firstSize = first.size()-1;
      int lastSize = last.size();
      int lastTraverser = 0;
      while(lastSize != 0){
          for(int i = 0; i <= 7; i++){//fill up to first size only. 
            if(i <= firstSize){
                ret[i] = first[i];
            }else{
                ret[i] = last[lastTraverser];
                lastTraverser++;
            }          
          }
          if(checkExist(ret) == true && sendtoUser(ret, givenName)){
            write(ret, givenName);
            break;
            return;
          }
        lastTraverser = 0;
        firstSize--;
        lastSize--;
      }
      cout<<"\n\nHello there, it seems like we're having trouble assigning you a username at this moment."<<endl;
      cout<<"An admin with admin functions will assist you"<<endl;
}
