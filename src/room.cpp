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
	system("clear");
	string temp;
	bool atk = false, def = false, abi = false;
	bool atk1 = false, def1 = false, abi1 = false;
	bool god = false;
	bool allyPrint = true;
	Enemy *target1, *target2;
	vector<Enemy*>::iterator iter;
	while(!clear()){
		//actions of the player
		while(!atk && !def && !abi && !god){
			cout << "   What do you want to do?   " << endl;
			cout << "( 1 ) Attack - deal " << p->weaponDamage() << " to 1 target." << endl << 
				"( 2 ) Defend - gain 10 health up to 100 health." << endl << 
				"( 3 ) Ability - deal damage to all enemies." << endl <<
				"( 4 ) Use Potion - You have: " << p->getPotion() << " potions." << endl << endl;
			outCurrent();
			cout << "YOUR PARTY:" << endl;
			cout << p->getName() << ": " << p->getHealth() << "HP || " << p->weaponDamage() << " ATK" << endl;
			cout << a->getName() << ": " << a->getHealth() << "HP || " << a->weaponDamage() << " ATK" << endl << endl;
			cout << "Enter a number: ";
			cin >> temp;
			system("clear");
			if(temp == "1"){
				int value = -1;
				atk = true;
				while(value == -1){
					cout << "Attack who?" << endl;
					for(int i = 0; i < enemies.size(); ++i){
						cout << "( " <<  i + 1 << " ) " << enemies.at(i)->getName() << " - " << enemies.at(i)->getHealth() << " HP" << endl;
					}
					cout << "Enter a number: ";
					cin >> temp;
					for(int i = 0; i < temp.size(); ++i){
						if(!isdigit(temp[i]))
							goto INVALID;
					}
					value = stoi(temp);
					--value;
					INVALID:
					if(value < enemies.size() && value >= 0){
						target1 = enemies.at(value);
					}
					else{
						cout << "Invalid input, try again." << endl;
						value = -1;
						sleep(1);
						system("clear");
					}
				}
			}
			else if(temp == "2"){
				def = true;
			}
			else if(temp == "3"){
				abi = true;
			}
			else if (temp == "4"){
				//ADD TEXT IN CONSUME
				p->consume();
				sleep(2);
			}
			else if(temp == "god"){
				god = true;
			}
			else{
				cout << "Invalid Input, try again." << endl;
				sleep(2);
			}	
			system("clear");
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
			sleep(1);
			atk = false;
		}
		else if(def){
			p->defend();
			sleep(1);
			def = false;
		}
		else if(abi){
			cout << p->getName() << " used Cleave!" << endl;
			for(auto x : enemies)
				p->ability(x);
			sleep(1);
			abi = false;
		}
		else if(god){
			cout << "~ THE GODS ARE BY YOUR SIDE ~" << endl;
			sleep(1);
			Ally* gods = new Ally("The Gods", 1);
			for(int i = 0; i < 195; ++i){
				gods->upgradeWeapon();
			}
			for(iter = enemies.begin(); iter != enemies.end(); ++iter){
				gods->attack(*iter);
				sleep(1);
			}
			delete gods;
		}
		//these will all be false if the ally is dead, picking sequence will not happen.
		if(atk1){
			a->attack(target2);
			sleep(1);
			atk1 = false;
		}
		else if(def1){
			a->defend();
			sleep(1);
			def1 = false;
		}
		else if(abi1){
			if(p->getHealth() < 100)
				a->ability(p);
			else
				a->ability(a);
			sleep(1);
			abi1 = false;
		}
		//check Afor dead targets, and remove them
		iter = enemies.begin();
		while(iter != enemies.end()){
			if((*iter)->getHealth() <= 0){
				int money = rand() % 30 + 1;
				cout << (*iter)->getName() << " is dead! You gained " << money << " gold!" << endl;
				p->setMoney(p->getMoney() + money);
				delete *iter;
				enemies.erase(iter);
				sleep(1);
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
			sleep(1);
			if(p->getHealth() <= 0){
				cout << "You died, game over." << endl;
				sleep(1);
				return false;
			}
			if(a->getHealth() <= 0 && allyPrint){
				cout << a->getName() << " is crippled beyond repair (can't fight anymore)." << endl;
				sleep(1);
				allyPrint = false;
			}
		}
		cout << endl;
	}
	cout << "Room cleared!" << endl;
	sleep(1);
	return true;
}

void Shop::inventory(Player* p){
	cout << "\nInventory: " << p->getMoney() << "g || " << p->getPotion() << " Potions\n" << endl;
}

void Shop::display(Player* p){
	string choice;
	bool done = false;
	system("clear");
	cout << "*You come across a merchant.*" << endl;
	sleep(1);
	while(!done){
		cout << "Greetings Traveler." << endl;
        	cout << "( 1 ) Buy Potions" << endl;
        	cout << "( 2 ) Sell Potions" << endl;
       		cout << "( 3 ) Upgrade Weapon" << endl;
        	cout << "( 4 ) Leave" << endl;
		inventory(p);
		choice = "";
		cout << "Enter a number: ";
		cin >> choice;
		int input = 0;
		if(choice == "1"){ 
			cout << "Each potion costs 50g. How many would you like?" << endl;
			cin >> input;
			if(input*50 > p->getMoney()){
				cout << "You do not have sufficient gold." << endl;
			}else{
				p->setMoney(p->getMoney() - input * 50);
				p->setPotion(p->getPotion() + input);
				cout << "*You now have " << p->getPotion() << " potions and " << p->getMoney() << " gold.*" << endl;
			}
		}else if(choice == "2"){
			cout << "30g for each potion. How many do you want to sell?" << endl;
			cin >> input;
			if(input > p->getPotion()){
				cout << "You do not have enough potions." << endl;
			}else{
				p->setPotion(p->getPotion()-input);
				p->setMoney(p->getMoney() + input * 30);
				cout << "*You now have " << p->getPotion() << " potions and " << p->getMoney() << " gold.*" << endl;
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
					cout << "*Your weapon feels stronger.*" << endl;
					cout << "*You now have " << p->getMoney() << " gold.*" << endl; 
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
		sleep(3);
		system("clear");
	}


}









