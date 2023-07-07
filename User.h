#pragma once

#include <string>

constexpr auto userFile = "/home/miha/tmp/data/user.data";

class User final {
public:
	User();
	~User();

	void setName(const std::string& name);
	void setLogin(const std::string& login);
	void setPass(const std::string& pass);

	const std::string& getName() const;
	const std::string& getLogin() const;
	const std::string& getPass() const;

private:
	std::string _name;
	std::string _login;
	std::string _pass;

	void readUser();
	void writeUser() const;

};

