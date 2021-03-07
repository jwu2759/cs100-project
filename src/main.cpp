#include <bits/stdc++.h>
#include "../header/room.h"
#include "../header/character.hpp"
#include "../header/weapon.hpp"
#include "../header/factory.hpp"
#include "../header/roomIter.hpp"

int main(){
	srand(time(0));
	Player* user = new Player("Kanon", 1);
	Ally* comp = new Ally("Qroobz", 2);
	Story* Story1 = new Story("Wow good story this is fantastic.");
	Battle* Battle1 = new Battle();
	Story* Story2 = new Story("Nvm this story sux 0/10 would not play again.");
	RoomIter iter(Story1, user, comp);
	Story1->setNext(Battle1);
	Battle1->setNext(Story2);
	while(!iter.isDone()){
		iter.execute();
		iter.next();
	}
	return 0;	
}
