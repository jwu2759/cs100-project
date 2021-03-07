#include <bits/stdc++.h>
#include "../header/room.h"
#include "../header/character.hpp"
#include "../header/weapon.hpp"
#include "../header/factory.hpp"


int main(){
	Player* user = new Player("Kanon", 1);
	Ally* comp = new Ally("Kanon", 2);
	Battle* Battle1 = new Battle();
	Battle1->fight(user, comp);
	return 0;	
}
