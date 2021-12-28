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

string Header::returnUsername(string name){
	string line; 
	fstream my_file;
	my_file.open("my_file.txt", ios::in);
	if(checkExist(name)){
		while(getline(my_file, line)){
		if (line.find(name) != string::npos){
			break;
			}
		}
	}
	string temp = "aaaaaaaa";
	for(int i = 0; i <= 7; i++){
		temp[i] = line[i];
	}
	return temp;
}

void Header::write(string username, string name){//need to add more logic
    fstream my_file;
	string line;
	my_file.open("my_file.txt", ios::app);	
	my_file << username <<" - "<<name<<endl;//SET TO LOWER CASE
	my_file.close();
}