//Fadeev Eugene st128225@student.spbu.ru
//This code tests decepticon class.
#include <gtest/gtest.h>
#include "Transformer.h"
#include "Decepticon.h"
#include "Dinobot.h"


TEST(DecepticonTest, ConstructorAndGetters) {
    Weapon weapon("Fusion Cannon", 100);
    Decepticon decepticon("Megatron", 150, 10, 90, 85, weapon, "Leader", "Warrior");

    EXPECT_EQ(decepticon.getRank(), "Leader");
    EXPECT_EQ(decepticon.getRole(), "Warrior");
}


TEST(DecepticonTest, Setters) {
    Weapon weapon("Fusion Cannon", 100);
    Decepticon decepticon("Megatron", 150, 10, 90, 85, weapon, "Leader", "Warrior");
    
    decepticon.setRank("Commander");
    decepticon.setRole("Scout");
    
    EXPECT_EQ(decepticon.getRank(), "Commander");
    EXPECT_EQ(decepticon.getRole(), "Scout");
}


TEST(DecepticonTest, Actions) {
    Weapon weapon("Fusion Cannon", 100);
    Decepticon decepticon("Megatron", 150, 10, 90, 85, weapon, "Leader", "Warrior");

    EXPECT_TRUE(decepticon.defend());
    EXPECT_TRUE(decepticon.heal());
}



