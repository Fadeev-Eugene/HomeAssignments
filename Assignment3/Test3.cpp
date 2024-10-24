//Fadeev Eugene st128225@student.spbu.ru
//This code tests dinobot, vehicle and weapon classes.
#include <gtest/gtest.h>
#include "Transformer.h"
#include "Dinobot.h"


TEST(DinobotTest, ConstructorAndGetters) {
    Weapon weapon("Tail Whip", 60); 
    Dinobot dinobot("Grimlock", 200, 8, 95, 60, weapon, "Leader", "Warrior");

    EXPECT_EQ(dinobot.getRank(), "Leader");
    EXPECT_EQ(dinobot.getRole(), "Warrior");
}


TEST(DinobotTest, Setters) {
    Weapon weapon("Tail Whip", 60);
    Dinobot dinobot("Grimlock", 200, 8, 95, 60, weapon, "Leader", "Warrior");

    dinobot.setRank("Second-in-command");
    dinobot.setRole("Scout");

    EXPECT_EQ(dinobot.getRank(), "Second-in-command");
    EXPECT_EQ(dinobot.getRole(), "Scout");
}


TEST(DinobotTest, Actions) {
    Weapon weapon("Tail Whip", 60);
    Dinobot dinobot("Grimlock", 200, 8, 95, 60, weapon, "Leader", "Warrior");

    EXPECT_TRUE(dinobot.defend());
    EXPECT_TRUE(dinobot.heal());
}


TEST(VehicleTest, ConstructorAndGetters) {
    Vehicle vehicle("Car", 120);

    EXPECT_EQ(vehicle.getName(), "Car");
    EXPECT_EQ(vehicle.getSpeed(), 120);
}


TEST(VehicleTest, Setters) {
    Vehicle vehicle("Car", 120);

    vehicle.setName("Bike");
    vehicle.setSpeed(80);

    EXPECT_EQ(vehicle.getName(), "Bike");
    EXPECT_EQ(vehicle.getSpeed(), 80);
}


TEST(WeaponTest, ConstructorAndGetters) {
    Weapon weapon("Sword", 100);

    EXPECT_EQ(weapon.getType(), "Sword");
    EXPECT_EQ(weapon.getDamage(), 100);
}


TEST(WeaponTest, Setters) {
    Weapon weapon("Sword", 100);

    weapon.setType("Axe");
    weapon.setDamage(80);

    EXPECT_EQ(weapon.getType(), "Axe");
    EXPECT_EQ(weapon.getDamage(), 80);
}

