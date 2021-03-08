#ifndef __ROOM_ITER__
#define __ROOM_ITER__
#include "room.h"

class RoomIter{
	private:
		Room* currRoom = nullptr;
	public:
		RoomIter(Room* r){
			currRoom = r;
		}
		bool isDone(){
			return currRoom == nullptr;
		}
		void execute(Player* p, Ally* a){
			currRoom->execute(p,a);
		}
		void next(){
			Room* temp = currRoom;
			currRoom = currRoom->getNext();
		}
};

#endif
