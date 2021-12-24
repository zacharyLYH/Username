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

string Header::twoClause(string first, string last){
    int j = 7;
    string ret;
    bool satisfied = false;
    while(!satisfied){
        if(first.size() >= 8){//use first name predominantly
            for(int i = 0; i <= 7; i++){
              ret[i] = first[i];
            }
            if(checkExist(ret) == true){
              //send to user 
              return ret;
            }
            for(int i = 0; i <= 7; i++){
              ret[j] = last[i];
              j--;
              if(checkExist(ret) == true){
                //send to user 
                return ret;
              }
            }
        }else if(last.size() >= 8){//use last name predominantly
            ret = first;
            for(int i = 0; i <= last.size() && ret.size() != 8 ; i++){
                ret += last[i];
            }
            if(checkExist(ret) == true){
              //send to user 
              return ret;
            }
            for(int i = 0; i <= 7; i++){
            }
        }      
    }
}