// Race.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

class Unit{
public:
	string name;
	int level = 1;
	int attackPoints;
	int health;
public:
	Unit(){
	};
	Unit(int attack, int health){
		setName("");
		setAttackPoints(attack);
		setHealth(health);
	}
	virtual void ATTACK(Unit *defender){
	}
	virtual void levelUp(){
	}
	string getName(){
		return this->name;
	}
	int getAttackPoints(){
		return this->attackPoints;
	}
	int getHealth(){
		return this->health;
	}
	int getLevel(){
		return this->level;
	}
	void incLevel(){
		this->level++;
	}
	void setName(string name){
		this->name = name;
	}
	void setAttackPoints(int attack){
		this->attackPoints = attack;
	}
	void setHealth(int health){
		this->health = health;
	}

};

class Human : public Unit{
public:
	Human() :Unit(2, 30){
		this->name = "Pesho Picha";
	}
	virtual void ATTACK(Unit *defender){
		if (this->getHealth() >= 10)
			defender->health=defender->health- this->attackPoints;
		else defender->health=defender->health- this->attackPoints-5;
		cout << this->getName() << " Attacked successfully " << defender->getName()<<"\n";
	}
	void levelUp(){
		incLevel();
		this->setHealth(this->getHealth() + 2);
		this->setAttackPoints(this->getAttackPoints() + 2);
	}
};

class Elf : public Unit{
public:
	Elf() :Unit(4, 20){
		this->name = "Minka Elfkata";
	}
	virtual void ATTACK(Unit *defender){
		if (this->getHealth() >= 10){
			defender->health = defender->health - this->attackPoints;
		}
		else defender->health=defender->health-this->attackPoints-2;
		cout << this->getName() << " Attacked successfully " << defender->getName()<<"\n";
	}
	void levelUp(){
		incLevel();
		this->setHealth(this->getHealth() + 5);
		this->setAttackPoints(this->getAttackPoints() + 1);
	}
};

class Engine{
	int turn = 1;
	bool isDead;
	int playerAttsequence = 0;
	int AIAttsequence = 0;
public:
	Unit *Create(string choice){
		isDead = false;
		if (choice == "human")
			return new Human();
		if (choice == "elf")
			return new Elf();
	}
	void STATUS(Unit unit){
		cout << "Unit stats:\n";
		cout << "Name: " << unit.getName() << "\n";
		cout << "Health: " << unit.getHealth() << "\n";
		cout << "Attack: " << unit.getAttackPoints() << "\n";

	}
	bool getDeathStatus(){
		return isDead;
	}
	void run(string input, Unit *player, Unit *AI){
		string in = input;
		cout << "T U R N " << turn << "\n";
		if (in == "attack"){
			player->ATTACK(AI);
			playerAttsequence++;
		}
		if (in == "pass"){
			player->setHealth(player->getHealth() + 2);
		}
		srand(time(NULL));
		int chance = rand() % 4;
			if (AI->getHealth() > 20){
				if (chance == 0)
					AI->setHealth(AI->getHealth() + 2);
				else {
					AI->ATTACK(player);
					AIAttsequence++;
				}
			}
			if (AI->getHealth() > 10 & AI->getHealth()<20){
				if (chance == 0 | chance == 1)
					AI->setHealth(AI->getHealth() + 2);
				else {
					AI->ATTACK(player);
					AIAttsequence++;
				}
			}
			if (AI->getHealth() < 10){
				if (chance == 0 | chance == 1 | chance == 2)
					AI->setHealth(AI->getHealth() + 2);
				else {
					AI->ATTACK(player);
					AIAttsequence++;
				}
			}
			if (playerAttsequence == 3){
				playerAttsequence = 0;
				player->levelUp();
			}
			if (AIAttsequence == 3){
				AIAttsequence = 0;
				AI->levelUp();
			}
			if (AI->getHealth() <= 0){
				cout << "AI is dead.\n";
				isDead = true;
			}
			if (player->getHealth() <= 0){
				cout << "Player is dead.\n";
				isDead = true;
			}
			STATUS(*player);
			STATUS(*AI);
			turn++;

	}

};

int _tmain(int argc, _TCHAR* argv[])
{

	Engine engine;
	string userPlayer, AIPlayer;
	string input;
	cout << "Hello!\nChoose type of hero!\nValid options:\n1.human\n2.elf\n";
	cin >> userPlayer;
	cout << "Hero Name:\n";
	string name;
	cin >> name;
	Unit *player = engine.Create(userPlayer);
	player->setName(name);
	cout << "Player created!\n";
	srand(time(NULL));
	if (rand() % 2 == 0)
		AIPlayer = "human";
	else AIPlayer = "elf";
	Unit *AI = engine.Create(AIPlayer);
	cout << "AI player " << AIPlayer << "created!\n";
	cout << "Commands:\n1.attack - attacks the AI.\n2.pass - passes the current turn.\n3.end - ends the current turn.\n4.exit - exits the program.\n";
	cout << "Enter command:\n";
	cin >> input;
	while (input != "exit"){
		engine.run(input,player, AI);
		if (engine.getDeathStatus() == true)
			break;
		cout << "Enter command:\n";
		cin >> input;
	}
	system("pause");
	return 0;
}

