#include "stdafx.h"
#include "Post.h"
Post::Post(){
}
Post::Post(string message, user Author, int ID){
	answers = NULL;
	setPost(message);
	setAuthor(Author);
	setID(ID);
}
	void Post::setPost(string message){
		this->question = message;
	}
	void Post::setAuthor(user Author){
		this->author.operator=(Author);
	}
	void Post::setID(int ID){
		this->ID = ID;
	}

	void Post::postAnswer(string message){
		answerList *t = answers;
		if (t == NULL){
			t = new answerList;
			t->next = NULL;
			t->mess = Message(message, this->author);
			answers = t;
		}
		else{
			while (t->next != NULL)
				t = t->next;
			t->next = new answerList;
			t = t->next;
			t->next = NULL;
			t->mess = Message(message, this->author);
		}
	}
	int Post::getPostId(){
		return this->ID;
	}
	string Post::getPost(){
		return this->question;
	}
	user Post::getAuthor(int id){
		return this->author;
	}
	answerList* Post::getAnswers(){
		return this->answers;
	}