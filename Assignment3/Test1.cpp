//Fadeev Eugene st128225@student.spbu.ru
//This code tests transformer and autobot classes.


#include <gtest/gtest.h>
#include "Transformer.h"
#include "Autobot.h"
#include "Decepticon.h"
#include "Dinobot.h"


TEST(TransformerTest, ConstructorAndGetters) {
    Weapon weapon("Blaster", 50);
    Transformer transformer("Optimus", 100, 5, 80, 60, weapon);
    
    EXPECT_EQ(transformer.getName(), "Optimus");
    EXPECT_EQ(transformer.getHealth(), 100);
    EXPECT_EQ(transformer.getLevel(), 5);
    EXPECT_EQ(transformer.getStrength(), 80);
    EXPECT_EQ(transformer.getPerception(), 60);
    EXPECT_EQ(transformer.getWeapon().getType(), "Blaster");
}


TEST(TransformerTest, Setters) {
    Weapon weapon("Sword", 30);
    Transformer transformer("Bumblebee", 90, 3, 70, 50, weapon);
    
    transformer.setName("Megatron");
    transformer.setHealth(120);
    transformer.setLevel(6);
    transformer.setStrength(90);
    transformer.setPerception(75);
    Weapon newWeapon("Cannon", 100);
    transformer.setWeapon(newWeapon);

    EXPECT_EQ(transformer.getName(), "Megatron");
    EXPECT_EQ(transformer.getHealth(), 120);
    EXPECT_EQ(transformer.getLevel(), 6);
    EXPECT_EQ(transformer.getStrength(), 90);
    EXPECT_EQ(transformer.getPerception(), 75);
    EXPECT_EQ(transformer.getWeapon().getType(), "Cannon");
}


TEST(TransformerTest, AssignVehicle) {
    Weapon weapon("Blaster", 50);
    Transformer transformer("Optimus", 100, 5, 80, 60, weapon);

    Vehicle vehicle("Truck", 100);
    transformer.assignVehicle(&vehicle);

    EXPECT_EQ(transformer.getVehicle(), &vehicle);
}


TEST(TransformerTest, TransformAndAttack) {
    Weapon weapon("Blaster", 50);
    Transformer transformer("Optimus", 100, 5, 80, 60, weapon);

    EXPECT_TRUE(transformer.transform());
    EXPECT_TRUE(transformer.attack());
}


TEST(AutobotTest, ConstructorAndGetters) {
    Weapon weapon("Laser Gun", 50); 
    Autobot autobot("Optimus Prime", 100, 5, 80, 70, weapon, "Commander", "Leader");
    EXPECT_EQ(autobot.getRank(), "Commander");
    EXPECT_EQ(autobot.getRole(), "Leader");
}


TEST(AutobotTest, Setters) {
    Weapon weapon("Laser Gun", 50);
    Autobot autobot("Optimus Prime", 100, 5, 80, 70, weapon, "Commander", "Leader");
    
    autobot.setRank("Scout");
    autobot.setRole("Warrior");

    EXPECT_EQ(autobot.getRank(), "Scout");
    EXPECT_EQ(autobot.getRole(), "Warrior");
}


TEST(AutobotTest, Actions) {
    Weapon weapon("Laser Gun", 50);
    Autobot autobot("Optimus Prime", 100, 5, 80, 70, weapon, "Commander", "Leader");

    EXPECT_TRUE(autobot.defend());
    EXPECT_TRUE(autobot.heal());
}


