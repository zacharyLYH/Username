#include <fstream>
#include <algorithm>
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

void Header::write(string username, string name){
    fstream my_file;
	transform(username.begin(), username.end(), username.begin(), ::tolower);
	transform(name.begin(), name.end(), name.begin(), ::tolower);
	my_file.open("my_file.txt", ios::app);	
	my_file << username <<" - "<<name<<endl;
	my_file.close();
}