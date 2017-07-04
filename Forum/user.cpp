#include "stdafx.h"
#include <string>
#include "user.h"
#include "List.h"
using namespace std;
void user::setUserName(string name) {
	this->userName = name;
};
void user::setPassword(string password) {
	this->password = password;
};
void user::setEmail(string Email) {
	this->email = Email;
};

	string user::getUserName() {
		return this->userName;
	};
	string user::getPassword() {
		return this->password;
	};
	string user::getEmail() {
		return this->email;
	};