#ifndef __CHARACTER_TEST_HPP__
#define __CHARACTER_TEST_HPP__

#include "gtest/gtest.h"

#include "../header/character.hpp"
#include "../header/weapon.hpp"
#include "../header/factory.hpp"

TEST(CharacterTest, PlayerNameCheck){

Character* MyMan = new Player ("Ryan", 1);

EXPECT_EQ(MyMan->getName(),"Ryan" );
delete MyMan;
}


TEST(CharacterTest, PlayerHealthCheck){
	std::string ryan = "Ryan";
	int weapon = 1;
	Character* MyMan = new Enemy (ryan, weapon);

EXPECT_EQ(MyMan->getHealth(),100 );
	delete MyMan;
}

TEST(CharacterTest, PlayerHealthCheck2){
        std::string ryan = "Ryan";
        int weapon = 1;
	Character* MyMan = new Player (ryan, weapon);
	MyMan->setHealth(90);

EXPECT_EQ(MyMan->getHealth(),90 );
	delete MyMan;
}

TEST(WeaponTest, WeaponPhraseCheck1){
	std::string karan = "Karan";
	int weapon = 2;

	Character* MyMan = new Player (karan, weapon);

EXPECT_EQ(MyMan->weaponPhrase(),"SHWOOOOMED" );
	delete MyMan;

}

TEST(WeaponTest, WeaponDamageCheck1){
        std::string karan = "Karan";
        int weapon = 2;

        Character* MyMan = new Player (karan, weapon);

EXPECT_EQ(MyMan->weaponDamage(),15 );
	delete MyMan;
}

TEST(WeaponTest, WeaponPhraseCheck2){
        std::string karan = "Karan";
        int weapon = 3;

        Character* MyMan = new Player (karan, weapon);

EXPECT_EQ(MyMan->weaponPhrase(),"BONKED" );
	delete MyMan;
}

TEST(WeaponTest, WeaponDamageCheck2){
        std::string karan = "Karan";
        int weapon = 3;

        Character* MyMan = new Player (karan, weapon);


EXPECT_EQ(MyMan->weaponDamage(),3 );
	delete MyMan;
}

TEST(WeaponTest, WeaponPhraseCheck3){
        std::string karan = "Karan";
        int weapon = 1;

        Character* MyMan = new Player (karan, weapon);

EXPECT_EQ(MyMan->weaponPhrase(),"WHACKED" );
	delete MyMan;
}

TEST(WeaponTest, WeaponDamageCheck3){
        std::string karan = "Karan";
        int weapon = 1;

        Character* MyMan = new Player (karan, weapon);


EXPECT_EQ(MyMan->weaponDamage(), 25 );
	delete MyMan;
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
	delete MyMan;
	delete enemy;
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
	delete MyMan;
	delete enemy;
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
	delete MyMan;
        delete enemy;
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
	delete MyMan;
        delete enemy;
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
	delete MyMan;
        delete enemy;
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

EXPECT_EQ(MainCh->getHealth(), 75 );
	delete MyMan;
        delete MainCh;
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
	delete MyMan;
        delete MainCh;
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
	delete mc;
        delete enemy;
}

TEST(DefendTest, DefendCheck){
	std::string ryan = "Ryan";
	int weapon = 1;
	Character* MyMan = new Player (ryan, weapon);


	MyMan->defend();

EXPECT_EQ(MyMan->getHealth(), 100 );
	delete MyMan;
}

TEST(DefendTest, DefendCheck2){
        std::string ryan = "Ryan";
        int weapon = 1;
        Character* MyMan = new Player (ryan, weapon);
	
	MyMan->setHealth(94);
        MyMan->defend();

EXPECT_EQ(MyMan->getHealth(), 99 );
	delete MyMan;
}

TEST(DefendTest, DefendCheck3){
        std::string ryan = "Ryan";
        int weapon = 1;
        Character* MyMan = new Player (ryan, weapon);

        MyMan->setHealth(96);
        MyMan->defend();

EXPECT_EQ(MyMan->getHealth(), 100 );
	delete MyMan;
}

TEST(DefendTest, DefendCheck4){
        std::string ryan = "Jason";
        int weapon = 1;
        Character* MyMan = new Ally (ryan, weapon);
	
        MyMan->setHealth(72);
        MyMan->defend();

EXPECT_EQ(MyMan->getHealth(), 82 );
	delete MyMan;
}

TEST(DefendTest, DefendCheck5){
        std::string ryan = "Jason";
        int weapon = 1;
        Character* MyMan = new Ally (ryan, weapon);

        MyMan->setHealth(1);
        MyMan->defend();

EXPECT_EQ(MyMan->getHealth(), 11 );
	delete MyMan;
}

TEST(DefendTest, DefendCheck6){
        std::string ryan = "Jason";
        int weapon = 1;
        Character* MyMan = new Ally (ryan, weapon);

        MyMan->setHealth(92);
        MyMan->defend();

EXPECT_EQ(MyMan->getHealth(), 100 );
	delete MyMan;
}

TEST(DefendTest, DefendCheck7){
        std::string ryan = "Jason";
        int weapon = 1;
        Character* MyMan = new Ally (ryan, weapon);

        MyMan->setHealth(100);
        MyMan->defend();

EXPECT_EQ(MyMan->getHealth(), 100 );
	delete MyMan;
}

TEST(DefendTest, DefendCheck8){
        std::string ryan = "Karan";
        int weapon = 1;
        Character* MyMan = new Enemy (ryan, weapon);

        MyMan->setHealth(100);
        MyMan->defend();

EXPECT_EQ(MyMan->getHealth(), 100 );
	delete MyMan;
}

TEST(DefendTest, DefendCheck9){
        std::string ryan = "Karan";
        int weapon = 1;
        Character* MyMan = new Enemy (ryan, weapon);

        MyMan->setHealth(99);
        MyMan->defend();

EXPECT_EQ(MyMan->getHealth(), 100 );
	delete MyMan;
}

TEST(DefendTest, DefendCheck10){
        std::string ryan = "Karan";
        int weapon = 1;
        Character* MyMan = new Enemy (ryan, weapon);

        MyMan->setHealth(73);
        MyMan->defend();

EXPECT_EQ(MyMan->getHealth(), 76 );
	delete MyMan;
}

#endif
