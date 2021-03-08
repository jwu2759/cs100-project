#include "../header/room.h"

using namespace std;

Room::Room(){
	nextRoom = nullptr;
}

Room::Room(Room* r){
	if(r != this)
		nextRoom = r;
	else{
		cout << "INVALID ROOM" << endl;
		exit(1);
	}
}

void Room::setNext(Room* room){
	nextRoom = room;
}

Room* Room::getNext(){
	return nextRoom;
}

Battle::Battle(){
	//FIXME: CALL THE ENEMY CONSTRUCTOR AND MAKE THE ENEMY VECTOR WITH CREATED ENEMY OBJECTS
	int enemyMax = 7;
	int enemyCount = rand() % enemyMax + 1;
	string enemyName;
	int n1 = 0, n2 = 0, n3 = 0;
	for(int i = 0; i < enemyCount; ++i){
		int title = rand() % 3;
		string name;
		if(title == 0){
			name = "Cheesy";
			++n1;
			enemyName = name + " " + to_string(n1);
		}
		else if(title == 1){
			name = "Gordita";
			++n2;
			enemyName = name + " " + to_string(n2);
		}
		else if(title == 2){
			name = "Crunch";
			++n3;
			enemyName = name + " " + to_string(n3);
		}
		enemies.push_back(new Enemy(enemyName, 3));
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
bool Battle::fight(Player* p, Ally* a){	//call clear in a while loop, in while loop, sequence of fighting happens
	string temp;
	bool atk = false, def = false, abi = false;
	bool atk1 = false, def1 = false, abi1 = false;
	bool allyPrint = true;
	Enemy *target1, *target2;
	vector<Enemy*>::iterator iter;
	while(!clear()){
		//actions of the player
		while(!atk && !def && !abi){
			cout << "What do you want to do?" << endl;
			cout << "\t( 1 ) Attack" << endl;
			cout << "\t( 2 ) Defend" << endl;
			cout << "\t( 3 ) Ability" << endl;
			cin >> temp;
			if(temp == "1"){
				int value = -1;
				atk = true;
				while(value == -1){
					cout << "Attack who?" << endl;
					for(int i = 0; i < enemies.size(); ++i){
						cout << "\t( " <<  i + 1 << " ) " << enemies.at(i)->getName() << endl;
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
				abi = true;
			}
			else{
				cout << "Invalid Input, try again." << endl;
			}
		}
		//actions of the ally
			//randomly decide
		if(a->getHealth() > 0){
			int allyChoice = rand() % 3;
			if(allyChoice == 0){
				atk1 = true;
				target2 = enemies.at(rand() % enemies.size());
			}
			else if(allyChoice == 1){
				def1 = true;
			}
			else if(allyChoice == 2){
				abi1 = true;
			}
		}
		//team attacks first
		if(atk){
			p->attack(target1);
			atk = false;
		}
		else if(def){
			p->defend();
			def = false;
		}
		else if(abi){
			cout << p->getName() << " used Cleave!" << endl;
			for(auto x : enemies)
				p->ability(x);
			abi = false;
		}
		//these will all be false if the ally is dead, picking sequence will not happen.
		if(atk1){
			a->attack(target2);
			atk1 = false;
		}
		else if(def1){
			a->defend();
			def1 = false;
		}
		else if(abi1){
			if(p->getHealth() < 100)
				a->ability(p);
			else
				a->ability(a);
			abi1 = false;
		}
		//check Afor dead targets, and remove them
		iter = enemies.begin();
		while(iter != enemies.end()){
			if((*iter)->getHealth() <= 0){
				delete *iter;
				enemies.erase(iter);
			}	
			else{
				++iter;
			}
		}
		int targetNum;
		for(iter = enemies.begin(); iter != enemies.end(); ++iter){
			targetNum = rand() % 4;
			if(targetNum == 0)
				(*iter)->attack(p);
			else if(targetNum == 1 && a->getHealth() > 0)
				(*iter)->attack(a);
			else if(targetNum == 2)
				(*iter)->ability(*iter);
			else if(targetNum == 3)
				(*iter)->defend();
			if(p->getHealth() <= 0){
				cout << "You died, game over." << endl;
				return false;
			}
			if(a->getHealth() <= 0 && allyPrint){
				cout << a->getName() << " is crippled beyond repair (can't fight anymore)." << endl;
				allyPrint = false;
			}
		}
	}
	cout << "Room cleared!" << endl;
	return true;
}


void Shop::display(Player* p){
	string choice;
	bool done = false;
	cout << "*You come across a merchant.*" << endl;
	while(!done){
		cout << "Greetings Traveler." << endl;
        	cout << "( 1 ) Buy Potions" << endl;
        	cout << "( 2 ) Sell Potions" << endl;
       		cout << "( 3 ) Upgrade Weapon" << endl;
        	cout << "( 4 ) Leave" << endl;
		choice = "";
		cin >> choice;
		int input = 0;
		cout << "*You currently have " << p->getMoney() << " gold.*" << endl;
		if(choice == "1"){ 
			cout << "Each potion costs 50g. How many would you like?" << endl;
			cin >> input;
			if(input*50 > p->getMoney()){
				cout << "You do not have sufficient gold." << endl;
			}else{
				p->setMoney(p->getMoney() - input * 50);
				p->setPotion(p->getPotion() + input);
			}
		}else if(choice == "2"){
			cout << "30g for each potion. How many do you want to sell?" << endl;
			cin >> input;
			if(input > p->getPotion()){
				cout << "You do no thave enough potions." << endl;
			}else{
				p->setPotion(p->getPotion()+input);
				p->setMoney(p->getMoney() + input * 30);
			}
		}else if(choice == "3"){
			cout << "It costs 300g to upgrade your weapon. Are you sure you want to upgrade?" << endl;
			cout << "( 1 ) Yes" << endl;
			cout << "( 2 ) No" << endl;
			cin >> input;
			if(input == 1){
				if(p->getMoney() > 300){
					p->setMoney(p->getMoney()-300);
					p->upgradeWeapon();
					done = true;
				}else{
					cout << "You do not have sufficient gold." << endl;
				}
			}
		}else if(choice == "4"){
			cout << "Goodbye." << endl;
			done = true;
		}else{
			cout << "Invalid input, try again." << endl;
		}
	}


}









