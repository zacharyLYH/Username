#include <iostream>
#include "Header.h"
using namespace std;


int Header::takeName(string first, string last, string middle, string suffix){

            for(int i = 0; i < first.length(); i++){
                if(isalpha(first[i])== false && first[i] != ' '){
                    return 1;
                }
            }
            for(int i = 0; i < last.length(); i++){
                if(isalpha(last[i])== false && first[i] != ' '){
                    return 1;
                }
            }
            if(!middle.empty()){
                for(int i = 0; i < middle.length(); i++){
                    if(isalpha(middle[i])== false){
                        return 1;
                    }
                }
            }
            if(!suffix.empty()){
                for(int i = 0; i < suffix.length(); i++){
                    if(isalpha(suffix[i])== false){
                        return 1;
                    }
                }
            }
            return 0;
        }