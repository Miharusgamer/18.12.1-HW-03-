#include "User.h"

#include <filesystem>
#include <fstream>

User::User() {
	readUser();
}

User::~User() {
	writeUser();
}

void User::setName(const std::string& name){
	_name = name;
}

void User::setLogin(const std::string& login){
	_login = login;
}

void User::setPass(const std::string& pass){
	_pass = pass;
}

const std::string& User::getName() const{
	return _name;
}

const std::string& User::getLogin() const{
	return _login;
}

const std::string& User::getPass() const{
	return _pass;
}

void User::readUser() {
	std::fstream file(userFile, std::ios::in);

	auto permissions =std::filesystem::perms::group_all | 
		std::filesystem::perms::others_all;
	std::filesystem::permissions(userFile, permissions, std::filesystem::perm_options::remove);

	const std::string delimiter = ":";
	if (file.is_open()) {
		std::string line;
		std::string name;
		std::string value;

		while (std::getline(file, line)) {
	   		size_t delimiterPosition = line.find(delimiter);
			if (delimiterPosition > 0) {
				name = line.substr(0, delimiterPosition);
				value = line.substr(delimiterPosition + 1);

				if (name == "Name") {
					_name = value;
				}
				else if (name == "Login") {
					_login = value;
				}
				else if (name == "Pass") {
					_pass = value;
				}
			}
	   	}
	}
	file.close();
}

void User::writeUser() const {
	std::fstream file(userFile, std::ios::out);
	file << "Name:" << _name << "\n";
	file << "Login:" << _login << "\n";
	file << "Pass:" << _pass << "\n";
	file.close();
}
