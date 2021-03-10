#include <bits/stdc++.h>
#include "../header/room.h"
#include "../header/character.hpp"
#include "../header/weapon.hpp"
#include "../header/factory.hpp"
#include "../header/roomIter.hpp"

int main(){
	srand(time(0));
	std::string userName;
	std::string allyName;
	cout << "Welcome to The Mountain\n\nBefore we begin, please enter your name: " ;
	getline(cin,userName);
	cout << "Please enter the name of your best friend: ";
	getline(cin,allyName);


	Player* user = new Player(userName, 1);
	Ally* comp = new Ally(allyName, 2);
	Story* game = new Story(
		{"March 14, 4801 AE: Eternal darkness has ravaged the skies.", 
		"The sun hasn’t risen in months. The corn stalks in the field have shriveled into twigs.\n",
		"At the bottom of the land, you and " + comp->getName() + " stare up at the void in the sky.",
		"Despite the vastness of the void, The Mountain's magnitude seemed to dominate the world.",
		"Being ten thousand meters tall, The Mountain loomed over the small mountain village where you currently stand.",
		"Legend has it that The Mountain could grant any one wish for every brave soul who dared escalate the gargantuan elevation.",
		"Although countless climbers have started the climb to peak, not a single soul has returned to tell the tale. \n", 
		comp->getName() + " coughing incessantly, " + comp->getName() + " is getting progressively more ill every day.  Just like their mother, who had passed away from the same fatal disease. \n",
		comp->getName() + ": Come on " + user->getName() + ", we can’t just stay here, do you really just want to rot away like this?",
		"I’ve already lost my mom to this world...",
		"The longer I sit around and do nothing, the sooner my whole family and entire village will die of starvation.",
		"I can’t let that happen. We have nothing left to lose! Don’t you want your wish too?"}, 
	new Wish(user->getName() + " (to yourself): What was my wish?", 
	new Story({user->getName() + ": You know " + comp->getName() + ", you’re right, how could I give up on that! I’ve wanted this for as long as I can remember...",
		user->getName() + ": Okay... To the Mountain... as long as we got each other's backs, we can take anything on."}, 
	new Story({"***THE JOURNEY TO THE MOUNTAIN HAS BEGUN***"}, 
	new Story({user->getName() +  ": Hey " + comp->getName() + ", careful. Look ahead... You see those other guys over there? They’re definitely bandits.", 
	"We need to be on guard, so get your weapon ready. This’ll be our first fight. You set?",
	comp->getName() + ": Yeah, I’m ready. I’ll do whatever it takes to save my village."},
 	new Battle(3,
	new Story({comp->getName() + ": *Coughs* Excuse me...Oh check that out, it’s a shop!"},
	new Shop(
	new Story({comp->getName() + ": That was a lot tougher than I thought it would be. I now understand how so many people have died before us.",
	user->getName() + ": Definitely. I’m glad we were able to take that large group of enemies down, it shows that we have a chance of making it to the top!",
	"Though far off, we’ve come a long way already in regards to reaching the top.", 
	user->getName() + ": Woah, " + comp->getName() + ", are you alright? You don’t look so good...You’re coughing out blood.",
	comp->getName() + ": Huh...My Mother started coughing out blood on the day she passed..." + user->getName() + ", we need to get to the top so I can get that one wish.",
	user->getName() + ": Planning to wish for good health?",
	comp->getName() + ": Nah...I might not make it, but I have to make sure my village does.",
	"I need to use that wish to provide food for everyone.", 
	user->getName() + ": WATCH OUT! SOMEONE’S BEHIND YOU!"},
	new Battle(4, 
	new Shop(
	new Story({comp->getName() + ": The top is so close, we can do this " + user->getName() + "!", 
	user->getName() + ": Yeah! I see it! I can’t believe we made it this far. We can secure our wishes!",
	"All we have to do is clear these last enemies, then we’ll be at the top!"}, 
	new Battle(5, 
	new Story({comp->getName() + ": Oh my god, " + user->getName() + " we made it to the top. But...I don’t see anything here?? Do you?", 
	"\t" + user->getName() + " There’s a note, hammered down in the ground over there.",
	"The note reads:\n\t**IN ORDER TO GAIN SOMETHING, YOU MUST LOSE SOMETHING**",
	user->getName() + " realizes that the only way to get their wish is to kill someone...,", 
	"*" + user->getName() + " turns their head towards " + comp->getName() + " with murderous intent*\n"}, 
	new AllyBattle(
	new Story({"After waiting nearly a week at the cold Mountain Top, nothing had happened...",
	"No wish was granted. The stories, the legends, the myths, the rumors were all lies. There was never any wish.",
	"Eternal darkness has ravaged the skies. The sun hasn’t risen in months.",
	"The corn stalks in the field have shriveled into twigs.",
	"This never-ending cycle of despair continues..."}, nullptr) ) ) ) ) ) ) ) ) ) ) ) ) ) ) );
	RoomIter iter(game);
	while(!iter.isDone()){
		if(!iter.execute(user,comp))
			break;
		iter.next();
	}
	delete user;
	delete comp;
	delete game;
	return 0;	
}
