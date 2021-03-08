#ifndef __FACTORY_TEST_HPP
#define __FACTORY_TEST_HPP

#include "gtest/gtest.h"
#include "../header/factory.hpp"

TEST(WepFactory, WepFactorySword){
	Factory f;
	Weapon* w = f.create(1);
	EXPECT_EQ(w->getAttack(), 25);
	EXPECT_EQ(w->getPhrase(), "WHACKED");
}

TEST(WepFactory, WepFactorySpear){
	Factory f;
        Weapon* w = f.create(2);
        EXPECT_EQ(w->getAttack(), 15);
        EXPECT_EQ(w->getPhrase(), "SHWOOOOMED");
}

TEST(WepFactory, WepFactoryAxe){
	Factory f;
        Weapon* w = f.create(3);
        EXPECT_EQ(w->getAttack(), 10);
        EXPECT_EQ(w->getPhrase(), "BONKED");
}

#endif
