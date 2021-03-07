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
};

class Battle : public Room{
	private:
		vector<Enemy*> enemies;
		bool clear();	//returns if room is cleared, if enemies is empty return true
		string BattleText;	//add more strings as needed for Battle.
	public:
		Battle();
		~Battle();
		void fight(Player* p, Ally* a);	//call clear in a while loop, in while loop, sequence of fighting happens
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
};

class Shop : public Room{};

#endif
