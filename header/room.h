#ifndef __ROOM_H__
#define __ROOM_H__

#include "item.h"
#include "CharacterList.h"
#include "Character.h"


using namespace std;

class Room{
	private:
		Room* nextRoom;
	public:
		Room();
		void setNext(Room* r);
		Room* getNext();
};

class Shop : public Room{
	private:
		string ShopText;
		vector<Item> shopChoices;
	public:
		Shop();
		Shop(string text);
		void addChoice(Item i);
		void displayOptions();
		void upgradeWeapon(Character* c);
};

class Battle : public Room{
	private:
		vector<Enemy*> enemies;
		bool clear();	//returns if room is cleared, if enemies is empty return true
		string BattleText;	//add more strings as needed for Battle.
	public:
		Battle();
		void fight(Player* p, Ally* a);	//call clear in a while loop, in while loop, sequence of fighting happens
};

class Story : public Room{
	private:
		string StoryText;
	public:
		string getStory();
		void setStory();
}

#endif
