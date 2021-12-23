#include <iostream>
#include "Header.h"
using namespace std;

/*Checks to see if a given name violates the name formation rule:
    All names cannot contain a number of any character besides alphabets
    Middle and Suffixes cannot contain more than 1 string 
*/
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
                for(int i = 0; i < middle.length(); i++){//Suffix is not more than 1 word
                    if(middle[i]== ' '){
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
                for(int i = 0; i < suffix.length(); i++){//Suffix is not more than 1 word
                    if(suffix[i]== ' '){
                        return 1;
                    }
                }
            }
            return 0;
        }