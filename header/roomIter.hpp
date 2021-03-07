#ifndef __ROOM_ITER__
#define __ROOM_ITER__
#include "room.h"

class RoomIter{
	private:
		Room* currRoom = nullptr;
		Player* p = nullptr;
		Ally* a = nullptr;
	public:
		RoomIter(Room* r, Player* p, Ally* a){
			currRoom = r;
			this->p = p;
			this->a = a;
		}
		bool isDone(){
			return currRoom == nullptr;
		}
		void execute(){
			if(dynamic_cast<Battle*>(currRoom)){
				Battle* b = dynamic_cast<Battle*>(currRoom);
				b->fight(p,a);
			}
			else if(dynamic_cast<Story*>(currRoom)){
				Story* s = dynamic_cast<Story*>(currRoom);
				cout << s->getStory() << endl;
			}
		}
		void next(){
			Room* temp = currRoom;
			currRoom = currRoom->getNext();
		}
};

#endif
