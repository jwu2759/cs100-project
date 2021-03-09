#ifndef __ROOM_H__
#define __ROOM_H__


#include <bits/stdc++.h>
#include "../header/character.hpp"


using namespace std;

class Room{
	protected:
		Room* nextRoom = nullptr;
	public:
		Room();
		Room(Room* r);
		virtual ~Room(){
			if(nextRoom)
				delete nextRoom;
		}
		void setNext(Room* r);
		Room* getNext();
		virtual bool execute(Player* p, Ally* a) = 0;
};

class Battle : public Room{
	private:
		vector<Enemy*> enemies;
		bool clear();	//returns if room is cleared, if enemies is empty return true
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
			do{
				cout << "";
			} while(cin.get() != '\n');
			do{
				cout << '\n' << "Press ENTER to continue...";
			} while(cin.get() != '\n');
		}
	public:
		Battle(int, Room*);
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

class AllyBattle : public Room{
		void levelUp(Player* p){
			int prevDamage = p->weaponDamage();
			p->upgradeWeapon();
			cout << p->getName() << "'s weapon has been upgraded! " << prevDamage << "->" << p->weaponDamage() << "ATK" << endl;
			sleep(1);	
			int prevAbi = p->getAbiBase();
			p->upgradeAbi();
			cout << p->getName() << "'s cleave damage has been increased! " << prevAbi << "->" << p->getAbiBase() << "ATK" << endl;
			do{
				cout << "";
			} while(cin.get() != '\n');
			do{
				cout << '\n' << "Press ENTER to continue...";
			} while(cin.get() != '\n');
		}
	public:
		AllyBattle(Room* r){
			nextRoom = r;
		}
		bool fight(Player* p, Ally* a);
		bool execute(Player* p, Ally* a){
			bool f = fight(p,a);
			levelUp(p);
			system("clear");
			cout << "*You drive your blade deep into the throat of " << a->getName() << "*" << endl;
			sleep(2);
			cout << "You let out a horrendous cry as you strangle the remaining fragments of life your best friend has left" << endl << endl;
			sleep(1);
			cout << a->getName() << ":" << endl;
			cout << "\t..." << endl;
			sleep(2);
			cout << "\t\t.." << endl;
			sleep(2);
			cout << "\t\t\t." << endl << endl;
			sleep(3);
			cout << p->getName() << ": GIVE ME MY WISH!!! GIVE ME " << p->pWish() << "!!!!!" << endl;
			do{
				cout << '\n' << "Press ENTER to continue...";
			} while(cin.get() != '\n');
			return true;
		}
};

class Story : public Room{
	private:
		vector<string> storyText;
	public:
		Story(const vector<string>& story, Room* r){
			storyText = story;
			nextRoom = r;
		}	
		const vector<string>& getStory(){
			return storyText;
		}
		virtual bool execute(Player* p, Ally* a){
			vector<string> temp = storyText;
			system("clear");
			for(int i = 0; i < temp.size(); ++i){
				cout << temp.at(i) << endl;
				sleep(1);
			}
			do{
				cout << '\n' << "Press ENTER to continue...";
			} while(cin.get() != '\n');
			return true;
		}
};

class Wish : public Room{
	//Wish ONLY gets input
	string wishText;
	void getWish(Player* p){
		string temp;
		cout << "Type your wish: ";
		getline(cin,temp);
		p->setWish(temp);
	}
	public:
	Wish(const string& s, Room* r){
		nextRoom = r;
		wishText = s;
	}
	bool execute(Player* p, Ally* a){
		system("clear");
		cout << wishText << endl;
		sleep(1);
		getWish(p);
		string temp = p->getName() + " (to yourself): Right..." + p->pWish() + " is my wish...";
		cout << temp << endl;
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
		Shop(Room* r){
			nextRoom = r;
		}
		void display(Player* p);
		bool execute(Player* p, Ally* a){
			display(p);
			do{
				cout << "";
			} while(cin.get() != '\n');
			return true;
		}
};

#endif
