#pragma once

#include "stdafx.h"
#include "List.h"
#include <iostream>

using namespace std;


class Engine{
	userList *userHeader;
	postList *postHeader = NULL;
	int postID = 0;
	string loggedUsers[1000];
	int loggedCounter;
public:
	Engine();
	void PostQuestion(string question, user author);
	void PostAnswer(int questionID, string answer);
	void ViewAllPosts();
	userList *FindUser(string email);
	void DeleteUser(string email);
	string RegisterUser(string name, string password, string email);
	string logInUser(string email, string password);
	string logOutUser(string email);

private:
	void CreateUser(string name, string password, string email);
};