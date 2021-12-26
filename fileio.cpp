#include <fstream>
#include "Header.h"

bool Header::checkExist(string checkExistUsername){
	string line;
    fstream my_file;
	my_file.open("my_file.txt", ios::in);
	while(getline(my_file, line)){
		if (line.find(checkExistUsername) != string::npos){
			return false;
		}
	}
	my_file.close();
	return true;
}

void Header::write(string username, string name){//need to add more logic
    fstream my_file;
	string line;
	my_file.open("my_file.txt", ios::out);
	my_file << username <<" - "<<name<<endl;
	my_file.close();
}