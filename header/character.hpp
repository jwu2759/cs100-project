#ifndef __CHARACTER__HPP___
#define __CHARACTER__HPP___

#include "weapon.hpp"
#include "factory.hpp"

#include <bits/stdc++.h>
using namespace std;

class Character{
	protected:
		Weapon* w;
		int money = 100;
		int potion = 2;
		int currHealth = 100;

		std::string name;
	public:
		virtual void attack(Character* target) = 0;
		virtual void ability(Character* target) = 0;
		virtual void defend() = 0;
	
		int getHealth (){
			return currHealth;
		}
		
		void setHealth(int remHealth){
			currHealth = remHealth;
		}
		
		std::string getName(){
			return name;
		}
		
		std::string weaponPhrase(){
			return w->getPhrase();
		}
		
		int weaponDamage(){
			return w->getAttack();
		}
		//for shop
		int getMoney(){return money;}
		void setMoney(int x){money = x;}
		int getPotion(){return potion;}
		void setPotion(int x){potion = x;}
		void upgradeWeapon(){
			w->setAttack(w->getAttack()+5);
		}
		void consume(){
			if(potion == 0){
				cout << "You do not have any potions." << endl;
			}else{
				if(currHealth == 100 ){
					cout << "You are at full health already." << endl;
				}else if(currHealth <= 50){
					currHealth += 50;
                                	potion--;
        	                        cout << "*Your wounds begin to heal*" << endl;
	                                cout << "*You restored 50 hp*" << endl;
				}else{
					currHealth = 100;
					potion--;
					cout << "*Your wounds begin to heal*" << endl;
					cout << "*Your health was fully restored*" << endl;
				}
			}
		}
		~Character(){
			delete w;
		}


};

class Player : public Character{
	private:
		int abiBase = 5;
		string wish;
	public:
		int getAbiBase(){
			return abiBase;
		}
		const string& pWish(){
			return wish;
		}
		void setWish(const string& s){
			wish = s;
		}
		void upgradeAbi(){
			abiBase += 2;
		}
		Player (const string& userName, int wepType){
			name = userName;
			Factory wepMaker;
			w = wepMaker.create(wepType);	
		}
 
		virtual void attack(Character* target){
			//out some for of output like "WHAM, BOOM!"
			// I'll just subtract a certain amount rn
			if(!target) return;
			cout << name << " " << w->getPhrase() << " " << target->getName() << "!" << endl;
			target->setHealth( (target->getHealth()) - (w->getAttack()) );
			cout << target->getName() << " has " << target->getHealth() << " HP left!" << endl;
		}
			//random damage ability
		virtual void ability(Character* target){
			int damage = (rand() % 6) + abiBase;
                        target->setHealth( ((target->getHealth()) - damage) );
			cout << target->getName() << " has "<< target->getHealth() << " HP left!"  << endl;

		}

		virtual void defend(){
			cout << name << " is defending!" <<endl;

			if (currHealth < 95 ){
                                currHealth = currHealth + 5;
                                cout << name << "'s current health: " << currHealth << endl;
                        }
                        else if (currHealth < 100 ){
                                currHealth = 100;
                                cout << name << "'s current health: " << currHealth << endl;
                        }
                        else {
                                cout << name << " is already at max health!" << endl;
                        }
		}
		

};

class Enemy : public Character{
        private:
        public:	
		//not too sure if we want a username here or nah??
                Enemy (const string& userName, int wepType){
                        name = userName;
			Factory wepMaker;
                        w = wepMaker.create(wepType);
	
                }
 
                virtual void attack(Character* target){
                        //out some for of output like "WHAM, BOOM!"
                        //                        // I'll just subtract a certain amount rn
			if(!target) return;
			cout << name << " " << w->getPhrase() << " " << target->getName() << "!" << endl;
                        target->setHealth( (target->getHealth()) - (w->getAttack()) );
			cout << target->getName() << " has " << target->getHealth() << " HP left!" << endl;

		}
			//Enemy buff ability
		virtual void ability(Character* target){
                        w->setAttack( w->getAttack() + 3 );
                        cout << name << " is using their buff ability for permanent damage!" << endl;
			
		}
		
		virtual void defend(){
                        cout << name << " is defending!" <<endl;
			if (currHealth < 97 ){
                        	currHealth = currHealth + 3;
				cout << name << "'s current health: " << currHealth << endl;
			}
			else if (currHealth < 100 ){
				currHealth = 100;
                        	cout << name << "'s current health: " << currHealth << endl;
			}
			else {
				cout << name << " is already at max health!" << endl;
			}
                }

};

class Ally : public Character{
        private:
		int healBase = 15;
        public:
		int getHealBase(){
			return healBase;
		}
		void upgradeHeal(){
			healBase += 5;
		}
                Ally (const string& userName, int wepType){
                        name = userName;
			Factory wepMaker;
                        w = wepMaker.create(wepType);
                }
                virtual void attack(Character* target){
			if(!target) return;
			cout << name << " " << w->getPhrase() << " "<< target->getName() << "!" << endl;
                        target->setHealth( (target->getHealth()) - (w->getAttack()) );
			cout << target->getName() << " has " << target->getHealth() << " HP left!" << endl;
		}
			//ally heal ability
		virtual void ability(Character* target){
                        cout << name << " is using their heal ability on " << target->getName() << "!" << endl;
			if ( (target->getHealth()) < 100-healBase){
				target->setHealth( (target->getHealth() + healBase) );
			}
			else{
				target->setHealth(100);
			}
			cout << target->getName() << "'s current health: " << target->getHealth() << endl;
                }
		
		virtual void defend(){

			cout << name << " is defending!" <<endl;
                        if (currHealth < 90 ){
                                currHealth = currHealth + 10;
                                cout << name << "'s current health: " << currHealth << endl;
                        }
                        else if (currHealth < 100 ){
                                currHealth = 100;
                                cout << name << "'s current health: " << currHealth << endl;
                        }
                        else {
                                cout << name << " is already at max health!" << endl;
                        }
                }

};

#endif
