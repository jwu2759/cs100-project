#ifndef __CHARACTER_TEST_HPP__
#define __CHARACTER_TEST_HPP__

#include "gtest/gtest.h"

#include "../header/character.hpp"
#include "../header/weapon.hpp"
#include "../header/factory.hpp"

TEST(CharacterTest, PlayerNameCheck){
//std::string ryan = "Ryan";
//int weapon = 1;
Character* MyMan = new Player ("Ryan", 1);

EXPECT_EQ(MyMan->getName(),"Ryan" );
}


TEST(CharacterTest, PlayerHealthCheck){
	std::string ryan = "Ryan";
	int weapon = 1;
	Character* MyMan = new Enemy (ryan, weapon);

EXPECT_EQ(MyMan->getHealth(),100 );
}

TEST(CharacterTest, PlayerHealthCheck2){
        std::string ryan = "Ryan";
        int weapon = 1;
	Character* MyMan = new Player (ryan, weapon);
	MyMan->setHealth(90);

EXPECT_EQ(MyMan->getHealth(),90 );
}

TEST(WeaponTest, WeaponPhraseCheck1){
	std::string karan = "Karan";
	int weapon = 2;

	Character* MyMan = new Player (karan, weapon);

EXPECT_EQ(MyMan->weaponPhrase(),"SHWOOOOMED" );

}

TEST(WeaponTest, WeaponDamageCheck1){
        std::string karan = "Karan";
        int weapon = 2;

        Character* MyMan = new Player (karan, weapon);

EXPECT_EQ(MyMan->weaponDamage(),15 );
}

TEST(WeaponTest, WeaponPhraseCheck2){
        std::string karan = "Karan";
        int weapon = 3;

        Character* MyMan = new Player (karan, weapon);

EXPECT_EQ(MyMan->weaponPhrase(),"BONKED" );

}

TEST(WeaponTest, WeaponDamageCheck2){
        std::string karan = "Karan";
        int weapon = 3;

        Character* MyMan = new Player (karan, weapon);


EXPECT_EQ(MyMan->weaponDamage(),3 );
}

TEST(WeaponTest, WeaponPhraseCheck3){
        std::string karan = "Karan";
        int weapon = 1;

        Character* MyMan = new Player (karan, weapon);

EXPECT_EQ(MyMan->weaponPhrase(),"WHACKED" );
}

TEST(WeaponTest, WeaponDamageCheck3){
        std::string karan = "Karan";
        int weapon = 1;

        Character* MyMan = new Player (karan, weapon);


EXPECT_EQ(MyMan->weaponDamage(), 25 );
}


TEST(AttackTest, AttackCheck1){
std::string ryan = "Ryan";
std::string karan = "Karan";
int weapon = 2;

int weapon2 = 3;

Character* MyMan = new Player (karan, weapon);
Character* enemy = new Enemy (ryan, weapon2);

MyMan->attack(enemy);

EXPECT_EQ(enemy->getHealth(), 85 );
}

TEST(AttackTest, AttackCheck2){
std::string ryan = "Ryan";
std::string karan = "Karan";
int weapon = 1;

int weapon2 = 3;

Character* MyMan = new Player (karan, weapon);
Character* enemy = new Enemy (ryan, weapon2);

MyMan->attack(enemy);

EXPECT_EQ(enemy->getHealth(), 75 );
}

TEST(AttackTest, AttackCheck3){
std::string ryan = "Ryan";
std::string karan = "Karan";
int weapon = 1;

int weapon2 = 3;

Character* MyMan = new Player (karan, weapon);
Character* enemy = new Enemy (ryan, weapon2);

enemy->attack(MyMan);

EXPECT_EQ(MyMan->getHealth(), 97 );
}

TEST(AttackTest, AttackCheck4){
std::string ryan = "Ryan";
std::string jason = "Jason";
int weapon = 2;

int weapon2 = 3;

Character* MyMan = new Ally (jason, weapon);
Character* enemy = new Enemy (ryan, weapon2);

enemy->attack(MyMan);

EXPECT_EQ(MyMan->getHealth(), 97 );
}

TEST(AbilityTest, AbilityCheck1){
std::string ryan = "Ryan";
std::string karan = "Karan";
int weapon = 1;

int weapon2 = 3;

Character* MyMan = new Player (karan, weapon);
Character* enemy = new Enemy (ryan, weapon2);

MyMan->ability(enemy);

EXPECT_EQ(enemy->getHealth(), 94 );
}


TEST(AbilityTest, AbilityCheck2){
std::string jason = "Jason";
std::string karan = "Karan";
int weapon = 1;

int weapon2 = 3;

Character* MyMan = new Ally (jason, weapon);
Character* MainCh = new Player (karan, weapon2);

MainCh->setHealth(60);

MyMan->ability(MainCh);

EXPECT_EQ(MainCh->getHealth(), 70 );
}

TEST(AbilityTest, AbilityCheck3){
std::string jason = "Jason";
std::string karan = "Karan";
int weapon = 1;

int weapon2 = 3;

Character* MyMan = new Ally (jason, weapon);
Character* MainCh = new Player (karan, weapon2);


MyMan->ability(MainCh);

EXPECT_EQ(MainCh->getHealth(), 100 );
}

TEST(AbilityTest, AbilityCheck4){
std::string mc1 = "Jason";
std::string mc2 = "ryan";
int weapon = 1;

int weapon2 = 3;

Character* enemy = new Enemy (mc1, weapon2);
Character* mc = new Player (mc2, weapon);

enemy->ability(mc);
enemy->attack(mc);

EXPECT_EQ(mc->getHealth(), 94 );
}


#endif
