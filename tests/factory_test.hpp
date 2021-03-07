#ifndef __FACTORY_TEST_HPP
#define __FACTORY_TEST_HPP

#include "gtest/gtest.h"
#include "../src/factory.hpp"

TEST(WepFactory, WepFactorySword){
	Factory f;
	Weapon w* = f.create(1);
	EXPECT_EQ(w->getAttack(), 20);
	EXPECT_EQ(w->getPhrase(), "WHACKED");
	delete w;
}

TEST(WepFactory, WepFactorySpear){
	Factory f;
        Weapon w* = f.create(2);
        EXPECT_EQ(w->getAttack(), 15);
        EXPECT_EQ(w->getPhrase(), "SCHWOOOOMED");
	delete w;
}

TEST(WepFactory, WepFactoryAxe){
	Factory f;
        Weapon w* = f.create(3);
        EXPECT_EQ(w->getAttack(), 10);
        EXPECT_EQ(w->getPhrase(), "BONKED");
	delete w;
}

#endif
