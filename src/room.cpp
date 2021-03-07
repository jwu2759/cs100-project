#include "../header/room.h"

Room::Room(){
	nextRoom = nullptr;
}

void Room::setNext(Room* room){
	nextRoom = room;
}

Room* Room::getNext(){
	return nextRoom;
}

Battle::Battle(){
	//FIXME: CALL THE ENEMY CONSTRUCTOR AND MAKE THE ENEMY VECTOR WITH CREATED ENEMY OBJECTS
	int enemyMax = 5;
	int enemyCount = rand() % enemyMax;
	string enemyName;
	for(int i = 0; i < enemyCount; ++i){
		enemyName = "Ghost" + to_string(i + 1);
		enemies.push_back(new Enemy(enemyName, rand() % 3 + 1));
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
	bool atk = false, def = false;
	bool atk1 = false, def1 = false;
	Enemy* target1;
	Enemy* target2;
	vector<Enemy*>::iterator iter;
	while(!clear()){
		//actions of the player
		while(!atk && !def){
			cout << "What do you want to do?" << endl;
			cout << "( 1 ) Attack" << endl;
			cout << "( 2 ) Defend" << endl;
			cout << "( 3 ) Give Up" << endl;
			cin >> temp;
			if(temp == "1"){
				int value = -1;
				atk = true;
				while(value == -1){
					cout << "Attack who?" << endl;
					for(int i = 0; i < enemies.size(); ++i){
						cout << "( " <<  i + 1 << " ) " << enemies.at(i)->getName() << endl;
					}
					cin >> value;
					--value;
					if(value < enemies.size() && value >= 0){
						target1 = enemies.at(value);
					}
					else{
						cout << "Invalid input, try again." << endl;
						value = -1;
					}
				}
			}
			else if(temp == "2"){
				def = true;
			}
			else if(temp == "3"){
				cout << "You give up." << endl;
				return;
			}
		}
		//actions of the ally
			//randomly decide
		int allyChoice = rand() % 2 + 1;
		if(a->getHealth() > 0){
			if(allyChoice = 1){
				atk1 = true;
				target2 = enemies.at(rand() % enemies.size());
			}
			else if(allyChoice = 2){
				def1 = true;
			}
			// else if(allyChoice = 3){
			//	abi1 = true;
			// }
		}
		//team attacks first
		if(atk){
			p->attack(target1);
			if(target1->getHealth() <= 0){
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
		//these will all be false if the ally is dead, picking sequence will not happen.
		if(atk1){
			a->attack(target2);
			if(target2->getHealth() <= 0){
				iter = enemies.begin();
				while(*iter != target2){
					++iter;
				}
				enemies.erase(iter);
			}
			atk1 = false;
		}
		else if(def1){
			//FIXME: ADD SOME DEFENSE STRATEGY a->defend();
			def1 = false;
		}
		int targetNum;
		for(auto x : enemies){
			targetNum = rand() % 3;
			if(targetNum == 0)
				x->attack(p);
			else if(targetNum == 1)
				x->attack(a);
			else if(targetNum == 2)
				x->ability(x);
		}
	}
}
