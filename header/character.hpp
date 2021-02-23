#ifndef __CHARACTER__HPP___
#define __CHARACTER__HPP___

#include "weapon.hpp"

#include <iostream>

using namespace std;

class Character{
	protected:
		Weapon* w;
		int money;
		int maxHealth = 100;
		int currHealth;
		int atkAmount;
		std::string name;
	public:
		virtual int attack(Character* target) = 0;
};

class Player : public Character{
	private:
	public:
		Player (string& userName, string& wepType){
			name = userName;
			w = new Weapon(wepType);	
			atkAmount = w->getAttack();		
			atkPhrase = w->getPhrase();	
		}
 
		virtual int attack(Character* target){
			//out some for of output like "WHAM, BOOM!"
			// I'll just subtract a certain amount rn
			cout << name << " " << atkPhrase << target->name;
			target->currHealth = target->currHealth - atkAmount; //
		}

};

class Enemy : public Character{
        private:
        public:	
		//not too sure if we want a username here or nah??
                Enemy (string& userName, string& wepType){
                        name = userName;
                        w = new Weapon(wepType);
                        atkAmount = w->getAttack();
                        atkPhrase = w->getPhrase();
                }
 
                virtual int attack(Character* target){
                        //out some for of output like "WHAM, BOOM!"
                        //                        // I'll just subtract a certain amount rn
              		cout << name << " " << atkPhrase << target->name;
			target->currHealth = target->currHealth - atkAmount;        
		}
};

class Ally : public Character{
        private:
        public:
                Ally (string& userName, string& wepType){
                        name = userName;
                        w = new Weapon(wepType);
                        atkAmount = w->getAttack();
                        atkPhrase = w->getPhrase();
                }

                virtual int attack(Character* target){
             		cout << name << " " << atkPhrase << target->name;                       	target->currHealth = target->currHealth - atkAmount
		}
};
