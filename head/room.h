#ifndef __ROOM_H__
#define __ROOM_H__

#include<bits/stdc++.h>
#include "item.h"
#include "CharacterList.h"

using namespace std;

class Room{
	private:
		vector<Room*> choices;
	public:
		Room();
		void addChoice(Room* r);
		vector<Room*> getChoices();	//replaces displayChoices, returns entire vector

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
		void upgradeWeapon(Character c);
};

class Battle : public Room{
	private:
		CharacterList enemies;
		bool clear();	//returns if room is cleared, if enemies is empty return true
		string BattleText;	//add more strings as needed for Battle.
	public:
		void fight(CharacterList* team);	//call clear in a while loop, in while loop, sequence of fighting happens
		
};

class Story : public Room{
	private:
		string StoryText;
	public:
		string getStory();
		void setStory();
};

#endif
