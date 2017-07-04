#include <iostream>
#include "user.h"
using namespace std;
class Message{
	string answer;
	user author;
public:
	Message();
	Message(string message, user author);
	string getAnswer();
	user getAuthor();

private:
	void setAnswer(string message);
	void setAuthor(user author);

};