#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

#include "weapon.hpp"

class Factory{
	public:
		Weapon* create(int x){
			switch(x){
				case 1: return new baseSword();
				case 2: return new baseSpear();
				case 3: return new baseAxe();
				
			}
		}
};


#endif

