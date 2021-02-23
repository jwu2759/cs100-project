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
	int enemyMax = 10;
	int enemyCount = rand() % enemyMax;
	string enemyName;
	for(int i = 0; i < enemyCount; ++i){
		enemyName = "Ghost" + to_string(i + 1);
		enemies.push_back(new Enemy(enemyName, "FIXME: WEAPON NAME"));
	}
}
Battle::~Battle(){
	for(int i = 0; i < enemies.size(); ++i){
		delete enemies.at(i);
	}
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
		if(a->currHealth > 0){
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
		}
		//team attacks first
		if(atk){
			p->attack(target1);
			if(target1->currHealth <= 0){
				iter = enemies.begin();
				while(*iter != target1){
					++iter;
				}
				enemies.erase(iter);
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
		//these will all be false if the ally is dead, picking sequence will not happen.
		if(atk1){
			a->attack(target2);
			if(target2->currHealth <= 0){
				iter = enemies.begin();
				while(*iter != target2){
					++iter;
				}
				enemies.erase(iter);
			}
			atk1 = false;
		}
		else if(def1){
			a->defend();
			def1 = false;
		}
		else if(abi1){
			a->ability();	//FIXME: SHOULD I PASS IN THE ENEMY VECTOR?
			abi1 = false;
		}
		//then allyy
		//FIXME: IMPLEMENT THE ENEMY ATTACKING SYSTEM
		//FOR EVERY ENEMY IN ENEMIES
			// PICK A TARGET
			// ATTACK THAT TARGET
		int enemyTarget;
		for(int i = 0; i < enemies.size(); ++i){
			enemyTarget = rand() % 2;
			if(enemyTarget == 1){	//attack the player
				enemies.at(i)->attack(p);
			}
			else if(enemyTarget == 2)	//attack the ally
				enemies.at(i)->attack(a);
			}
			if(p->currHealth <= 0){
				cout << "YOU DIED, GAME OVER." << endl;
				exit(1);
			}
			if(a->currHealth <= 0){
				cout << a->name << " HAS DIED." << endl;
			}
		}
	}
}

string Story::getStory();
void Story::setStory();
