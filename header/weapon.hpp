#ifndef __WEAPON_HPP__
#define __WEAPON_HPP__

#include <string>

class Weapon{
	protected:
		int attack;
		std::string phrase;
	public:
		
		virtual ~Weapon() = default;
		
		int getAttack(){return attack;}
		std::string getPhrase(){return phrase;}


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
			attack = 10;
			phrase = "BONKED";
		}


};

#endif
