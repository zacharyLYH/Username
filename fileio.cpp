#include <fstream>
#include "Header.h"

bool Header::checkExist(string checkExistUsername){
	string line;
    fstream my_file;
	my_file.open("my_file.txt", ios::in);
	while(getline(my_file, line)){
		if(line == checkExistUsername){
			return false;
		}
	}
	return true;
}

void Header::write(string username, string name){//need to add more logic
    fstream my_file;
	my_file.open("my_file.txt", ios::out);
    //find appropriate line to add username and name
	my_file << username <<" - "<<name<<endl;
	my_file.close();
	
}