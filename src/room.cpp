#include "room.h"

Room::Room(){
	nextRoom = nullptr;
}

void Room::setNext(Room* room){
	nextRoom = room;
}

Room* Room::getNext(){
	return nextRoom;
}

Shop::Shop(){
}
Shop::Shop(string text);
void Shop::addChoice(Item i);
void Shop::displayOptions();
void Shop::upgradeWeapon(Character* c);

Battle::Battle(){
	//FIXME: CALL THE ENEMY CONSTRUCTOR AND MAKE THE ENEMY VECTOR WITH CREATED ENEMY OBJECTS
}
bool Battle::clear(){	//returns if room is cleared, if enemies is empty return true
	return enemies.empty();
}
void Battle::fight(Player* p, Ally* a){	//call clear in a while loop, in while loop, sequence of fighting happens
	string temp;
	bool atk = false, def = false, abi = false;
	bool atk1 = false, def1 = false, abi1 = false;
	Enemy* target1;
	Enemy* target2;
	vector<Enemy*>::iterator iter;
	while(!clear()){
		//actions of the player
		while(!atk && !def && !abi){
			cout << "What do you want to do?" << endl;
			cout << "( 1 ) Attack" << endl;
			cout << "( 2 ) Defend" << endl;
			cout << "( 3 ) Ability" << endl;
			cin >> temp;
			if(temp == "1"){
				int value = -1;
				atk = true;
				while(value == -1){
					cout << "Attack who?" << endl;
					for(int i = 0; i < enemies.size(); ++i){
						cout << "( " <<  i + 1 << " ) " << enemies.at(i).name << endl;
					}
					cin >> value;
					--value;
					if(value >= enemies.size()){
						cout << "Invalid input, try again." << endl;
						value = -1;
					}
					else{
						target1 = enemies.at(i);
					}
				}
			}
			else if(temp == "2"){
				def = true;
			}
			else if(temp == "3"{
				abi = true;
			}
		}
		//actions of the ally
			//randomly decide
		int allyChoice = rand() % 3 + 1;
		if(allyChoice = 1){
			atk1 = true;
			target2 = enemies.at(rand() % enemies.size());
		}
		else if(allyChoice = 2){
			def1 = true;
		}
		else if(allyChoice = 3){
			abi1 = true;
		}
		//team attacks first
		if(atk){
			p->attack(target1);
			if(target1->currHealth <= 0){
				iter = enemies.begin();
				while(*iter != target1){
					++iter;
				}
				enemies.erase(iter.begin());
			}
			atk = false;
		}
		else if(def){
			//FIXME: DEFEND USING THE DEFEND FUNCTION.
			def = false;
		}
		else if(abi){
			//FIXME: IMPLEMENT VIRTUAL ABILITY FUNCTION BASED ON FUNCTION CREATED IN CHARACTER
			abi = false;
		}
		//then allyy
		//FIXME: IMPLEMENT THE ENEMY ATTACKING SYSTEM
	}
}

string Story::getStory();
void Story::setStory();
