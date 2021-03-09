#ifndef __ROOM_H__
#define __ROOM_H__


#include <bits/stdc++.h>
#include "../header/character.hpp"


using namespace std;

class Room{
	private:
		Room* nextRoom = nullptr;
	public:
		Room();
		Room(Room* r);
		virtual ~Room() = default;
		void setNext(Room* r);
		Room* getNext();
		virtual bool execute(Player* p, Ally* a) = 0;
};

class Battle : public Room{
	private:
		vector<Enemy*> enemies;
		bool clear();	//returns if room is cleared, if enemies is empty return true
		string BattleText;	//add more strings as needed for Battle.	
		void outCurrent(){
			cout << "- ENEMIES REMAINING -" << endl;
			for(int i = 0; i < enemies.size(); ++i){
				Enemy* e = enemies.at(i);
				cout << e->getName() << ": " << e->getHealth() << " HP" << " || " << e->weaponDamage() << " ATK" << endl;
			}
			cout << endl;
		}
		void levelUp(Player* p, Ally* a){
			int prevDamage = p->weaponDamage();
			p->upgradeWeapon();
			cout << p->getName() << "'s weapon has been upgraded! " << prevDamage << "->" << p->weaponDamage() << "ATK" << endl;
			sleep(1);	
			int prevAbi = p->getAbiBase();
			p->upgradeAbi();
			cout << p->getName() << "'s cleave damage has been increased! " << prevAbi << "->" << p->getAbiBase() << "ATK" << endl;
			sleep(1);	
			int allyDamage = a->weaponDamage();
			a->upgradeWeapon();
			cout << a->getName() << "'s weapon has been upgraded! " << allyDamage << "->" << a->weaponDamage() << "ATK" << endl;
			sleep(1);	
			int healPrev = a->getHealBase();
			a->upgradeHeal();
			cout << a->getName() << "'s ability healing has been increased! " << healPrev << "->" << a->getHealBase() << "HP" << endl;
			sleep(4);	
		}
	public:
		Battle(int);
		~Battle();
		bool fight(Player* p, Ally* a);	//call clear in a while loop, in while loop, sequence of fighting happens
		bool execute(Player* p, Ally* a){
			bool pass = fight(p,a);
			string input;
			while(!pass){
				cout << "Restart from where you left off?" << endl << "( 1 ) Yes" << endl << "( 2 ) No" << endl;
				cin >> input;
				if(input == "1"){
					p->setHealth(100);
					a->setHealth(100);
					pass = fight(p,a);
				}
				else if(input == "2"){
					cout << "GAME OVER" << endl;
					return false;
				}
				else
					cout << "Invalid input, try again." << endl;
			}
			//REWARD PLAYER
			levelUp(p,a);
			return true;
		}
};

class Story : public Room{
	private:
		string storyText;
	public:
		Story(const string& story){
			storyText = story;
		}	
		const string& getStory(){
			return storyText;
		}
		bool execute(Player* p, Ally* a){
			system("clear");
			string temp;
			cout << getStory() << endl;
			do{
				cout << '\n' << "Press ENTER to continue...";
			} while(cin.get() != '\n');
			return true;
		}
};

class Shop : public Room{
	private:
		void inventory(Player* p);
	public:
		void display(Player* p);
		bool execute(Player* p, Ally* a){
			display(p);
			return true;
		}
};

#endif
