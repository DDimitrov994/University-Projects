#include "stdafx.h"
#include "Engine.h"

Engine::Engine(){
	for (int i = 0; i < 1000; i++)
		loggedUsers[i] = "\0";
	loggedCounter = 0;

	userHeader = NULL;
}
	void Engine::PostQuestion(string question, user author){
		for (int i = 0; i < loggedCounter; i++)
			if (author.getEmail() == loggedUsers[i]){
				postList *temp = postHeader;
				if (postHeader == NULL){
					postHeader = new postList;
					temp = postHeader;
					temp->next = NULL;
					temp->posts = Post(question, author, postID);
					postID++;
				}
				else{
					while (temp->next != NULL){
						temp = temp->next;
					}
					temp->next = new postList;
					temp = temp->next;
					temp->next = NULL;
					temp->posts = Post(question, author, postID);
					postID++;
				}
			}
			else{ cout << "User not logged.\n"; }
	}
	void Engine::PostAnswer(int questionID, string answer){
		postList *temp;
		temp = postHeader;
		while (temp != NULL){
			if (temp->posts.getPostId() == questionID){
				temp->posts.postAnswer(answer);
			}
			temp = temp->next;
		}
	}
	void Engine::ViewAllPosts(){
		postList *t = postHeader;
		while (t != NULL){
			cout << t->posts.getPost() << "\n";
			answerList *tempAns = t->posts.getAnswers();
			while (tempAns != NULL){
				cout << tempAns->mess.getAnswer() << "\n";
				tempAns = tempAns->next;
			}
			t = t->next;
		}
	}

	void Engine::CreateUser(string name, string password, string email){
		userList *t = userHeader;
		if (t == NULL){
			t = new userList;
			t->next = NULL;
			t->userData = user(name, password,email);
			userHeader = t;
		}
		else{
			while (t->next != NULL)
				t = t->next;
			t->next = new userList;
			t = t->next;
			t->next = NULL;
			t->userData = user(name, password,email);
		}
//		currUser = currUser->next;
	}

	userList *Engine::FindUser(string email){
		userList *t = userHeader;
		if (t == NULL)
			return NULL;
		while (t != NULL){
			if (t->userData.getEmail() == email)
				return t;
			t = t->next;
		}
		return NULL;
	}
	void Engine::DeleteUser(string email){
		userList *t = userHeader;
		if (userHeader->userData.getEmail() == email)
			userHeader = userHeader->next;
		while (t->next != NULL){
			if (t->next->userData.getEmail() == email){
				t->next = t->next->next;
				break;
			}
			t = t->next;
		}
	}
	string Engine::RegisterUser(string name, string password, string email){
		if (name.size() == 0 | password.size() == 0 | email.size() == 0)
			return "Invalid input data!\n";
		if (FindUser(email) != NULL)
			return "User with this email exists!\n";
		else{
			CreateUser(name, password, email);
			return "User registered!\n";
		}
	}
	string Engine::logInUser(string email, string password){
		if (FindUser(email) == NULL)
			return "User with this email does not exist.\n";
		if (FindUser(email)->userData.getPassword() == password){
			for (int i = 0; i < loggedCounter; i++){
				if (loggedUsers[i] == email)
					return "User already logged.\n";
			}
			loggedUsers[loggedCounter] = email;
			loggedCounter++;
			return "User logged successfuly.\n";
		}


	}
	string Engine::logOutUser(string email){
		for (int i = 0; i < loggedCounter; i++)
			if (loggedUsers[i] == email){
				for (int j = i; j < loggedCounter; j++)
					loggedUsers[j] = loggedUsers[j + 1];
				loggedCounter--;
				return "User logged out.";
			}
		return "No user logged in with that email.";
	}