#ifndef __CHARACTER__HPP___
#define __CHARACTER__HPP___

#include "weapon.hpp"
#include "factory.hpp"

#include <iostream>

using namespace std;

class Character{
	protected:
		Weapon* w;
		int money;
		int maxHealth = 100;
		int currHealth;

		std::string name;
	public:
		virtual int attack(Character* target) = 0;
		int getCurrHealth (){
			return currHealth;
		}

};

class Player : public Character{
	private:
	public:
		Player (string& userName, int& wepType){
			name = userName;
			Factory wepMaker;
			w = wepMaker.create(wepType);	
		}
 
		virtual int attack(Character* target){
			//out some for of output like "WHAM, BOOM!"
			// I'll just subtract a certain amount rn
			cout << name << " " << w->getPhrase() << target->name;
			target->currHealth = (target->currHealth) - (w->getAttack());
		}

};

class Enemy : public Character{
        private:
        public:	
		//not too sure if we want a username here or nah??
                Enemy (string& userName, int& wepType){
                        name = userName;
			Factory wepMaker;
                        w = wepMaker.create(wepType);
	
                }
 
                virtual int attack(Character* target){
                        //out some for of output like "WHAM, BOOM!"
                        //                        // I'll just subtract a certain amount rn
              		cout << name << " " << w->getPhrase() << target->name;
			target->currHealth = (target->currHealth) - (w->getAttack());
		}
};

class Ally : public Character{
        private:
        public:
                Ally (string& userName, int& wepType){
                        name = userName;
			Factory wepMaker;
                        w = wepMaker.create(wepType);
                }

                virtual int attack(Character* target){
             		cout << name << " " << w->getPhrase() << target->name;                       	target->currHealth = (target->currHealth) - (w->getAttack()) ;		
		}
};
