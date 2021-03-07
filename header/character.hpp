#ifndef __CHARACTER__HPP___
#define __CHARACTER__HPP___

#include "weapon.hpp"
#include "factory.hpp"

#include <iostream>
#include <string>

using namespace std;

class Character{
	protected:
		Weapon* w;
		int money;

		int currHealth = 100;

		std::string name;
	public:
		virtual void attack(Character* target) = 0;
		virtual void ability(Character* target) = 0;
	
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
		

};

class Player : public Character{
	private:
	public:
		Player (const string& userName, int wepType){
			name = userName;
			Factory wepMaker;
			w = wepMaker.create(wepType);	
		}
 
		virtual void attack(Character* target){
			//out some for of output like "WHAM, BOOM!"
			// I'll just subtract a certain amount rn
			cout << name << " " << w->getPhrase() << " " << target->getName() << "!" << endl;
			target->setHealth( (target->getHealth()) - (w->getAttack()) );
		}
			//random damage ability
		virtual void ability(Character* target){
			int rand = (w->getAttack() % 20) + 10 ;
			cout << name << " is charing their attack ability!" << endl;
			cout << "Amount charged: " << rand << endl;
                        target->setHealth( ((target->getHealth()) - rand) );
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
			cout << name << " " << w->getPhrase() << " " << target->getName() << "!" << endl;
                        target->setHealth( (target->getHealth()) - (w->getAttack()) );

		}
			//Enemy buff ability
		virtual void ability(Character* target){
                        w->setAttack( w->getAttack() + 3 );
                        cout << name << " is using their buff ability for permanent damage!" << endl;
		}

};

class Ally : public Character{
        private:
        public:
                Ally (const string userName, int wepType){
                        name = userName;
			Factory wepMaker;
                        w = wepMaker.create(wepType);
                }

                virtual void attack(Character* target){
			cout << name << " " << w->getPhrase() << " "<< target->getName() << "!" << endl;
                        target->setHealth( (target->getHealth()) - (w->getAttack()) );
		}
			//ally heal ability
		virtual void ability(Character* target){
                        cout << name << " is using their heal ability on " << target->getName() << "!" << endl;
			if ( (target->getHealth()) < 90){
				target->setHealth( (target->getHealth() + 10) );
			}
			else{
				target->setHealth(100);
			}
                }

};

#endif
