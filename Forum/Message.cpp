#include "stdafx.h"
#include "Message.h"
Message::Message(){
	answer = "";
}
Message::Message(string message, user author){
	setAnswer(message);
	setAuthor(author);
}
string Message::getAnswer(){
	return this->answer;
}
user Message::getAuthor(){ 
	return this->author; 
}
	void Message::setAnswer(string message){
		this->answer = message;
	}
	void Message::setAuthor(user author){
		this->author.operator=(author);
	}