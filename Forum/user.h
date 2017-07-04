#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>
#include <string.h>

using namespace std;
struct userList;
class user{
private:
	string userName;
	string password;
	string email;
public:
	user(){
		setUserName("");
		setPassword("");
		setEmail("");
	};
	user(string name, string password, string email){
		setUserName(name);
		setPassword(password);
		setEmail(email);
	};
private:
	void setUserName(string name);
	void setPassword(string password);
	void setEmail(string Email); 

public:
	void operator=(user user1){
		this->userName = user1.userName;
		this->password = user1.password;
		this->email = user1.email;
	}
	string getUserName();
	string getPassword();
	string getEmail();

};
