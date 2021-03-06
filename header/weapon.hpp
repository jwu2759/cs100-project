#ifndef __WEAPON_HPP__
#define __WEAPON_HPP__

class Weapon{
	private:
		int attack;
	public:
		Weapon(int x){attack = x;}
		~Weapon();
		int getAttack(){return attack;}
		int setAttack(int x){attack = x;}
};

#endif
