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
	Battle* Battle1 = new Battle(3);
	Story* Story2 = new Story("Nvm this story sux 0/10 would not play again.");
	Shop* shop = new Shop();
	Battle* Battle2 = new Battle(4);
	RoomIter iter(Story1);
	Story1->setNext(Battle1);
	Battle1->setNext(Story2);
	Story2->setNext(shop);
	shop->setNext(Battle2);
	while(!iter.isDone()){
		if(!iter.execute(user,comp))
			break;
		iter.next();
	}
	delete user;
	delete comp;
	delete Story1;
	delete Battle1;
	delete Story2;
	delete shop;
	delete Battle2;
	return 0;	
}
