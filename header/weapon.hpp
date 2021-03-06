#ifndef __WEAPON_HPP__
#define __WEAPON_HPP__

#include <string>
#include <unistd.h>

class Weapon{
	protected:
		int attack;
		std::string phrase;
	public:
		
		virtual ~Weapon() = default;
		
		int getAttack(){return attack;}
		const std::string& getPhrase(){return phrase;}
		int setAttack(int num){ attack = num; }

};

class baseSword : public Weapon{


	public:
		baseSword(){
			attack = 25;
			phrase = "WHACKED";
		}


};

class baseSpear : public Weapon{


        public:
                baseSpear(){
			attack = 15;
			phrase = "SHWOOOOMED";
		}

};

class baseAxe : public Weapon{


        public:
                baseAxe(){
			attack = 3;
			phrase = "BONKED";
		}


};

#endif
