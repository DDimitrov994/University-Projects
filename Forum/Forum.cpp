
#include "stdafx.h"
#include <iostream>
#include "Engine.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	Engine engine=Engine();
	string inputOption, username,password,email, message;
	int id;
	cout << "Welcome!\nList of commands:\nregister - registers a new account\nlogin - logs in user\nlogout - logs out user\npostquestion - posts a question\npostanswer - posts an answer\nviewall - view all entries\nend - exit\n";
	cout << "Please enter desired option:\n";
	cin >> inputOption;
	while (inputOption != "end"){
		if (inputOption == "register"){
			cout << "Enter username, password and email:\n";
			cin >> username >> password >> email;
			cout << engine.RegisterUser(username, password, email);
			inputOption.clear();
			cout << "Please enter desired option:\n";
			cin >> inputOption;
		}
		if (inputOption == "login"){
			cout << "Enter email and password:\n";
			cin >> email >> password;
			cout << engine.logInUser(email, password);
			inputOption.clear();
			cout << "Enter desired option:\n";
			cin >> inputOption;
		}
		if (inputOption == "logout"){
			cout << "Enter email:\n";
			cin >> email;
			cout << engine.logOutUser(email);
			inputOption.clear();
			cout << "Enter desired option:\n";
			cin >> inputOption;
		}

		if (inputOption == "postquestion"){
			cout << "username, password and email for author:\n";
			cin >> username >> password >> email;
			user temp(username, password, email);
			cout << "Enter Question:\n";
			string message;
			cin.clear();
			cin.sync();
			std::getline(cin, message);
			engine.PostQuestion(message,temp);
			inputOption.clear();
			cout << "Enter desired option:\n";
			cin >> inputOption;
		}
		if (inputOption == "postanswer"){
			cout << "username, password and email for author:\n";
			cin >> username >> password >> email;
			user temp(username, password, email);
			cout << "Enter question's number to which you want to answer:\n";
			cin >> id;
			cin.clear();
			cin.sync();
			cout << "Enter the answer:\n";
			getline(cin, message);
			engine.PostAnswer(id, message);
			inputOption.clear();
			cout << "Enter desired option:\n";
			cin >> inputOption;
		}
		if (inputOption == "viewall"){
			engine.ViewAllPosts();
			inputOption.clear();
			cout << "Enter desired option:\n";
			cin >> inputOption;
		}
	}
	return 0;
}

