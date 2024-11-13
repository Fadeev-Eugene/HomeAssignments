#include <gtest/gtest.h>
#include "Transformer.h"
#include "Autobot.h"
#include "Decepticon.h"
#include "Dinobot.h"
#include "Weapon.h"
#include "Vehicle.h"


TEST(TransformerTest, ParameterizedConstructor) {
    Weapon weapon("Laser", 50);
    Transformer t("Optimus Prime", 200, 5, 80, 70, weapon);
    
    EXPECT_EQ(t.getName(), "Optimus Prime");
    EXPECT_EQ(t.getHealth(), 200);
    EXPECT_EQ(t.getLevel(), 5);
    EXPECT_EQ(t.getStrength(), 80);
    EXPECT_EQ(t.getPerception(), 70);
    EXPECT_EQ(t.getWeapon().getType(), "Laser");
    EXPECT_EQ(t.getWeapon().getDamage(), 50);
}


TEST(TransformerTest, SetGetName) {
    Weapon weapon("Laser", 50);
    Transformer t("Optimus Prime", 200, 5, 80, 70, weapon);
    t.setName("Bumblebee");
    EXPECT_EQ(t.getName(), "Bumblebee");
}


TEST(TransformerTest, SetGetHealth) {
    Weapon weapon("Laser", 50);
    Transformer t("Optimus Prime", 200, 5, 80, 70, weapon);
    t.setHealth(150);
    EXPECT_EQ(t.getHealth(), 150);
}


TEST(TransformerTest, SetGetLevel) {
    Weapon weapon("Laser", 50);
    Transformer t("Optimus Prime", 200, 5, 80, 70, weapon);
    t.setLevel(10);
    EXPECT_EQ(t.getLevel(), 10);
}


TEST(TransformerTest, SetGetStrength) {
    Weapon weapon("Laser", 50);
    Transformer t("Optimus Prime", 200, 5, 80, 70, weapon);
    t.setStrength(90);
    EXPECT_EQ(t.getStrength(), 90);
}


TEST(TransformerTest, SetGetPerception) {
    Weapon weapon("Laser", 50);
    Transformer t("Optimus Prime", 200, 5, 80, 70, weapon);
    t.setPerception(60);
    EXPECT_EQ(t.getPerception(), 60);
}


TEST(TransformerTest, SetGetWeapon) {
    Weapon weapon1("Laser", 50);
    Transformer t("Optimus Prime", 200, 5, 80, 70, weapon1);
    Weapon weapon2("Cannon", 70);
    t.setWeapon(weapon2);
    EXPECT_EQ(t.getWeapon().getType(), "Cannon");
    EXPECT_EQ(t.getWeapon().getDamage(), 70);
}


TEST(TransformerTest, AssignGetVehicle) {
    Weapon weapon("Laser", 50);
    Transformer t("Optimus Prime", 200, 5, 80, 70, weapon);
    Vehicle v("Truck", 5);
    t.assignVehicle(&v);
    EXPECT_EQ(t.getVehicle()->getName(), "Truck");
    EXPECT_EQ(t.getVehicle()->getSpeed(), 5);
    
}


TEST(TransformerTest, Transform) {
    Weapon weapon("Laser", 50);
    Transformer t("Optimus Prime", 200, 5, 80, 70, weapon);
    EXPECT_TRUE(t.transform());
}


TEST(TransformerTest, Attack) {
    Weapon weapon("Laser", 50);
    Transformer t("Optimus Prime", 200, 5, 80, 70, weapon);
    EXPECT_TRUE(t.attack());
}


TEST(AutobotTest, ParameterizedConstructor) {
    Weapon weapon("Laser", 50);
    Autobot a("Optimus Prime", 200, 5, 80, 70, weapon, "Commander", "Leader");
    
    EXPECT_EQ(a.getName(), "Optimus Prime");
    EXPECT_EQ(a.getHealth(), 200);
    EXPECT_EQ(a.getLevel(), 5);
    EXPECT_EQ(a.getStrength(), 80);
    EXPECT_EQ(a.getPerception(), 70);
    EXPECT_EQ(a.getWeapon().getType(), "Laser");
    EXPECT_EQ(a.getWeapon().getDamage(), 50);
    EXPECT_EQ(a.getRank(), "Commander");
    EXPECT_EQ(a.getRole(), "Leader");
}


TEST(AutobotTest, SetGetRank) {
    Weapon weapon("Laser", 50);
    Autobot a("Optimus Prime", 200, 5, 80, 70, weapon, "Commander", "Leader");
    a.setRank("Warrior");
    EXPECT_EQ(a.getRank(), "Warrior");
}


TEST(AutobotTest, SetGetRole) {
    Weapon weapon("Laser", 50);
    Autobot a("Optimus Prime", 200, 5, 80, 70, weapon, "Commander", "Leader");
    a.setRole("Scout");
    EXPECT_EQ(a.getRole(), "Scout");
}


TEST(AutobotTest, Defend) {
    Weapon weapon("Laser", 50);
    Autobot a("Optimus Prime", 200, 5, 80, 70, weapon, "Commander", "Leader");
    EXPECT_TRUE(a.defend());
}


TEST(AutobotTest, Heal) {
    Weapon weapon("Laser", 50);
    Autobot a("Optimus Prime", 200, 5, 80, 70, weapon, "Commander", "Leader");
    EXPECT_TRUE(a.heal());
}


TEST(DecepticonTest, ParameterizedConstructor) {
    Weapon weapon("Plasma Cannon", 60);
    Decepticon d("Megatron", 300, 7, 95, 80, weapon, "Leader", "Warrior");
    
    EXPECT_EQ(d.getName(), "Megatron");
    EXPECT_EQ(d.getHealth(), 300);
    EXPECT_EQ(d.getLevel(), 7);
    EXPECT_EQ(d.getStrength(), 95);
    EXPECT_EQ(d.getPerception(), 80);
    EXPECT_EQ(d.getWeapon().getType(), "Plasma Cannon");
    EXPECT_EQ(d.getWeapon().getDamage(), 60);
    EXPECT_EQ(d.getRank(), "Leader");
    EXPECT_EQ(d.getRole(), "Warrior");
}


TEST(DecepticonTest, SetGetRank) {
    Weapon weapon("Plasma Cannon", 60);
    Decepticon d("Megatron", 300, 7, 95, 80, weapon, "Leader", "Warrior");
    d.setRank("Warrior");
    EXPECT_EQ(d.getRank(), "Warrior");
}


TEST(DecepticonTest, SetGetRole) {
    Weapon weapon("Plasma Cannon", 60);
    Decepticon d("Megatron", 300, 7, 95, 80, weapon, "Leader", "Warrior");
    d.setRole("Scout");
    EXPECT_EQ(d.getRole(), "Scout");
}


TEST(DecepticonTest, Defend) {
    Weapon weapon("Plasma Cannon", 60);
    Decepticon d("Megatron", 300, 7, 95, 80, weapon, "Leader", "Warrior");
    EXPECT_TRUE(d.defend());
}


TEST(DecepticonTest, Heal) {
    Weapon weapon("Plasma Cannon", 60);
    Decepticon d("Megatron", 300, 7, 95, 80, weapon, "Leader", "Warrior");
    EXPECT_TRUE(d.heal());
}


TEST(DinobotTest, ParameterizedConstructor) {
    Weapon weapon("Flame Thrower", 75);
    Dinobot d("Grimlock", 400, 10, 120, 50, weapon, "Commander", "Frontline");

    EXPECT_EQ(d.getName(), "Grimlock");
    EXPECT_EQ(d.getHealth(), 400);
    EXPECT_EQ(d.getLevel(), 10);
    EXPECT_EQ(d.getStrength(), 120);
    EXPECT_EQ(d.getPerception(), 50);
    EXPECT_EQ(d.getWeapon().getType(), "Flame Thrower");
    EXPECT_EQ(d.getWeapon().getDamage(), 75);
    EXPECT_EQ(d.getRank(), "Commander");
    EXPECT_EQ(d.getRole(), "Frontline");
}


TEST(DinobotTest, SetGetRank) {
    Weapon weapon("Flame Thrower", 75);
    Dinobot d("Grimlock", 400, 10, 120, 50, weapon, "Commander", "Frontline");
    d.setRank("Leader");
    EXPECT_EQ(d.getRank(), "Leader");
}


TEST(DinobotTest, SetGetRole) {
    Weapon weapon("Flame Thrower", 75);
    Dinobot d("Grimlock", 400, 10, 120, 50, weapon, "Commander", "Frontline");
    d.setRole("Defense");
    EXPECT_EQ(d.getRole(), "Defense");
}


TEST(DinobotTest, Defend) {
    Weapon weapon("Flame Thrower", 75);
    Dinobot d("Grimlock", 400, 10, 120, 50, weapon, "Commander", "Frontline");
    EXPECT_TRUE(d.defend());
}


TEST(DinobotTest, Heal) {
    Weapon weapon("Flame Thrower", 75);
    Dinobot d("Grimlock", 400, 10, 120, 50, weapon, "Commander", "Frontline");
    EXPECT_TRUE(d.heal());
}

TEST(VehicleTest, ParameterizedConstructor) {
    Vehicle v("Sports Car", 120);
    EXPECT_EQ(v.getName(), "Sports Car");
    EXPECT_EQ(v.getSpeed(), 120);
}

TEST(VehicleTest, SetGetName) {
    Vehicle v("Sports Car", 120);
    v.setName("Truck");
    EXPECT_EQ(v.getName(), "Truck");
}

TEST(VehicleTest, SetGetSpeed) {
    Vehicle v("Sports Car", 120);
    v.setSpeed(80);
    EXPECT_EQ(v.getSpeed(), 80);
}


TEST(WeaponTest, ParameterizedConstructor) {
    Weapon w("Laser Cannon", 50);
    EXPECT_EQ(w.getType(), "Laser Cannon");
    EXPECT_EQ(w.getDamage(), 50);
}

TEST(WeaponTest, SetGetType) {
    Weapon w("Laser Cannon", 50);
    w.setType("Plasma Rifle");
    EXPECT_EQ(w.getType(), "Plasma Rifle");
}

TEST(WeaponTest, SetGetDamage) {
    Weapon w("Laser Cannon", 50);
    w.setDamage(80);
    EXPECT_EQ(w.getDamage(), 80);
}

