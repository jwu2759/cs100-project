#ifndef __POTION_HPP__
#define __POTION_HPP__

#include "character.hpp"


class Potion{
	private:
		int num;
	public:
		Potion(){
			num = 3;
		}
		~Potion(){}
		void consume(Character* c){
			if(num <= 0){
				cout << "You do not have any potions." << endl;
				return;
			}else{
				num--;
				c->setHealth(c->getHealth()+25);
			}
		}
		void sell(Character* c, int x){
			if(num - x <= 0){
				cout << "You do not have enough potions." << endl;
				return;
			}else{
				num -= x;
				c->setMoney(c->getMoney()+50);
			}
		}
};

#endif
