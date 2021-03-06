#ifndef __CHARACTER_TEST_HPP__
#define __CHARACTER_TEST_HPP__

#include "gtest/gtest.h"

#include "../header/character.hpp"
#include "../header/weapon.hpp"
#include "../header/factory.hpp"

TEST(CharacterTest, PlayerNameCheck){
std::string ryan = "Ryan";
int weapon = 1;
Character* MyMan = new Player (ryan, weapon);

EXPECT_EQ(MyMan->getName(),"Ryan" );
}

#endif
