#include <fstream>
#include "Header.h"

void Header::read(string &readTo){
    fstream my_file;
	my_file.open("my_file.txt", ios::in);
    //
	my_file.close();

}

bool Header::checkExist(string checkExistUsername){

}

void Header::write(string username, string name){//need to add more logic
    fstream my_file;
	my_file.open("my_file.txt", ios::out);
    //find appropriate line to add username and name
	my_file << username <<" - "<<name<<endl;
	my_file.close();
	
}