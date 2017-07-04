#pragma once
#include <iostream>
#include "user.h"
#include <string>
#include "Message.h"
using namespace std;


struct answerList{
	Message mess;
	struct answerList *next;
}typedef answerList;


class Post{
	int ID;
	string question;
	answerList *answers=new answerList;
	user author;
public:
	Post();
	Post(string message, user Author, int ID);
private:
	void setPost(string message);
	void setAuthor(user Author);
	void setID(int ID);

public:
	void postAnswer(string message);
	int getPostId();
	string getPost();
	user getAuthor(int id);
	answerList* getAnswers();
};