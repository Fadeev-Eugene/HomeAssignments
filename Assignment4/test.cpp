#include <gtest/gtest.h>
#include "Transformer.h"
#include "Autobot.h"
#include "Decepticon.h"
#include "Dinobot.h"
#include "Weapon.h"
#include "Vehicle.h"


TEST(TransformerTest, DefaultConstructor) {
    Transformer t;
    EXPECT_EQ(t.getName(), "Unknown");
    EXPECT_EQ(t.getHealth(), 100);
    EXPECT_EQ(t.getLevel(), 1);
    EXPECT_EQ(t.getStrength(), 10);
    EXPECT_EQ(t.getPerception(), 10);
    EXPECT_EQ(t.getWeapon().getType(), "Standart gun");
    EXPECT_EQ(t.getWeapon().getDamage(), 5);
    EXPECT_EQ(t.getVehicle(), nullptr);
}


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


TEST(TransformerTest, GreaterThanOperator) {
    Transformer t1("Transformer1", 100, 1, 50, 20, Weapon());
    Transformer t2("Transformer2", 100, 1, 40, 20, Weapon());
    EXPECT_TRUE(t1 > t2);
}


TEST(TransformerTest, LessThanOperator) {
    Transformer t1("Transformer1", 100, 1, 30, 20, Weapon());
    Transformer t2("Transformer2", 100, 1, 40, 20, Weapon());
    EXPECT_TRUE(t1 < t2);
}


TEST(TransformerTest, SetGetName) {
    Transformer t;
    t.setName("Bumblebee");
    EXPECT_EQ(t.getName(), "Bumblebee");
}


TEST(TransformerTest, SetGetHealth) {
    Transformer t;
    t.setHealth(150);
    EXPECT_EQ(t.getHealth(), 150);
}


TEST(TransformerTest, SetGetLevel) {
    Transformer t;
    t.setLevel(10);
    EXPECT_EQ(t.getLevel(), 10);
}


TEST(TransformerTest, SetGetStrength) {
    Transformer t;
    t.setStrength(90);
    EXPECT_EQ(t.getStrength(), 90);
}


TEST(TransformerTest, SetGetPerception) {
    Transformer t;
    t.setPerception(60);
    EXPECT_EQ(t.getPerception(), 60);
}


TEST(TransformerTest, SetGetWeapon) {
    Transformer t;
    Weapon weapon("Cannon", 70);
    t.setWeapon(weapon);
    EXPECT_EQ(t.getWeapon().getType(), "Cannon");
    EXPECT_EQ(t.getWeapon().getDamage(), 70);
}


TEST(TransformerTest, AssignGetVehicle) {
    Transformer t;
    Vehicle v("Truck", 5);
    t.assignVehicle(&v);
    EXPECT_EQ(t.getVehicle()->getName(), "Truck");
    EXPECT_EQ(t.getVehicle()->getSpeed(), 5);
    
}


TEST(TransformerTest, Transform) {
    Transformer t;
    EXPECT_TRUE(t.transform());
}


TEST(TransformerTest, Attack) {
    Transformer t;
    EXPECT_TRUE(t.attack());
}


TEST(TransformerTest, OutputOperator) {
    Weapon weapon("Laser", 50);
    Transformer t("Optimus Prime", 200, 5, 80, 70, weapon);

    std::ostringstream output;
    output << t;

    std::string expected_output =
        "Transformer: Optimus Prime\n"
        "Health: 200\n"
        "Level: 5\n"
        "Strength: 80\n"
        "Perception: 70\n"
        "Weapon: Laser (Damage: 50) \n";

    EXPECT_EQ(output.str(), expected_output);
}


TEST(AutobotTest, DefaultConstructor) {
    Autobot a;
    EXPECT_EQ(a.getName(), "Unknown");
    EXPECT_EQ(a.getHealth(), 100);
    EXPECT_EQ(a.getLevel(), 1);
    EXPECT_EQ(a.getStrength(), 10);
    EXPECT_EQ(a.getPerception(), 10);
    EXPECT_EQ(a.getWeapon().getType(), "Standart gun");
    EXPECT_EQ(a.getWeapon().getDamage(), 5);
    EXPECT_EQ(a.getRank(), "No rank");
    EXPECT_EQ(a.getRole(), "No role");
    EXPECT_EQ(a.getVehicle(), nullptr);
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
    Autobot a;
    a.setRank("Warrior");
    EXPECT_EQ(a.getRank(), "Warrior");
}


TEST(AutobotTest, SetGetRole) {
    Autobot a;
    a.setRole("Scout");
    EXPECT_EQ(a.getRole(), "Scout");
}


TEST(AutobotTest, Defend) {
    Autobot a;
    EXPECT_TRUE(a.defend());
}


TEST(AutobotTest, Heal) {
    Autobot a;
    EXPECT_TRUE(a.heal());
}


TEST(AutobotTest, OutputOperator) {
    Weapon weapon("Laser", 50);
    Autobot a("Optimus Prime", 200, 5, 80, 70, weapon, "Commander", "Leader");

    std::ostringstream output;
    output << a;

    std::string expected_output =
        "Autobot: Optimus Prime\n"
        "Health: 200\n"
        "Level: 5\n"
        "Strength: 80\n"
        "Perception: 70\n"
        "Weapon: Laser (Damage: 50) \n"
        "Rank: Commander\n"
        "Role: Leader\n";

    EXPECT_EQ(output.str(), expected_output);
}


TEST(DecepticonTest, DefaultConstructor) {
    Decepticon d;
    EXPECT_EQ(d.getName(), "Unknown");
    EXPECT_EQ(d.getHealth(), 100);
    EXPECT_EQ(d.getLevel(), 1);
    EXPECT_EQ(d.getStrength(), 10);
    EXPECT_EQ(d.getPerception(), 10);
    EXPECT_EQ(d.getWeapon().getType(), "Standart gun");
    EXPECT_EQ(d.getWeapon().getDamage(), 5);
    EXPECT_EQ(d.getRank(), "No rank");
    EXPECT_EQ(d.getRole(), "No role");
    EXPECT_EQ(d.getVehicle(), nullptr);
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
    Decepticon d;
    d.setRank("Warrior");
    EXPECT_EQ(d.getRank(), "Warrior");
}


TEST(DecepticonTest, SetGetRole) {
    Decepticon d;
    d.setRole("Scout");
    EXPECT_EQ(d.getRole(), "Scout");
}


TEST(DecepticonTest, Defend) {
    Decepticon d;
    EXPECT_TRUE(d.defend());
}


TEST(DecepticonTest, Heal) {
    Decepticon d;
    EXPECT_TRUE(d.heal());
}


TEST(DecepticonTest, OutputOperator) {
    Weapon weapon("Plasma Cannon", 60);
    Decepticon d("Megatron", 300, 7, 95, 80, weapon, "Leader", "Warrior");

    std::ostringstream output;
    output << d;

    std::string expected_output =
        "Decepticon: Megatron\n"
        "Health: 300\n"
        "Level: 7\n"
        "Strength: 95\n"
        "Perception: 80\n"
        "Weapon: Plasma Cannon (Damage: 60) \n"
        "Rank: Leader\n"
        "Role: Warrior\n";

    EXPECT_EQ(output.str(), expected_output);
}



TEST(DinobotTest, DefaultConstructor) {
    Dinobot d;
    EXPECT_EQ(d.getName(), "Unknown");
    EXPECT_EQ(d.getHealth(), 100);
    EXPECT_EQ(d.getLevel(), 1);
    EXPECT_EQ(d.getStrength(), 10);
    EXPECT_EQ(d.getPerception(), 10);
    EXPECT_EQ(d.getWeapon().getType(), "Standart gun");
    EXPECT_EQ(d.getWeapon().getDamage(), 5);
    EXPECT_EQ(d.getRank(), "No rank");
    EXPECT_EQ(d.getRole(), "No role");
    EXPECT_EQ(d.getVehicle(), nullptr);
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
    Dinobot d;
    d.setRank("Leader");
    EXPECT_EQ(d.getRank(), "Leader");
}


TEST(DinobotTest, SetGetRole) {
    Dinobot d;
    d.setRole("Defense");
    EXPECT_EQ(d.getRole(), "Defense");
}


TEST(DinobotTest, Defend) {
    Dinobot d;
    EXPECT_TRUE(d.defend());
}


TEST(DinobotTest, Heal) {
    Dinobot d;
    EXPECT_TRUE(d.heal());
}


TEST(DinobotTest, OutputOperator) {
    Weapon weapon("Flame Thrower", 75);
    Dinobot d("Grimlock", 400, 10, 120, 50, weapon, "Commander", "Frontline");

    std::ostringstream output;
    output << d;

    std::string expected_output =
        "Dinobot: Grimlock\n"
        "Health: 400\n"
        "Level: 10\n"
        "Strength: 120\n"
        "Perception: 50\n"
        "Weapon: Flame Thrower (Damage: 75) \n"
        "Rank: Commander\n"
        "Role: Frontline\n";

    EXPECT_EQ(output.str(), expected_output);
}

TEST(VehicleTest, DefaultConstructor) {
    Vehicle v;
    EXPECT_EQ(v.getName(), "Standart Car");
    EXPECT_EQ(v.getSpeed(), 5);
}

TEST(VehicleTest, ParameterizedConstructor) {
    Vehicle v("Sports Car", 120);
    EXPECT_EQ(v.getName(), "Sports Car");
    EXPECT_EQ(v.getSpeed(), 120);
}

TEST(VehicleTest, SetGetName) {
    Vehicle v;
    v.setName("Truck");
    EXPECT_EQ(v.getName(), "Truck");
}

TEST(VehicleTest, SetGetSpeed) {
    Vehicle v;
    v.setSpeed(80);
    EXPECT_EQ(v.getSpeed(), 80);
}

TEST(VehicleTest, GreaterThanOperator) {
    Vehicle v1("Car1", 100);
    Vehicle v2("Car2", 50);
    EXPECT_TRUE(v1 > v2);
}

TEST(VehicleTest, LessThanOperator) {
    Vehicle v1("Car1", 100);
    Vehicle v2("Car2", 150);
    EXPECT_TRUE(v1 < v2);
}

TEST(VehicleTest, OutputOperator) {
    Vehicle v("Motorbike", 90);

    std::ostringstream output;
    output << v;

    std::string expected_output = "Name: Motorbike\nSpeed: 90";
    EXPECT_EQ(output.str(), expected_output);
}

TEST(WeaponTest, DefaultConstructor) {
    Weapon w;
    EXPECT_EQ(w.getType(), "Standart gun");
    EXPECT_EQ(w.getDamage(), 5);
}

TEST(WeaponTest, ParameterizedConstructor) {
    Weapon w("Laser Cannon", 50);
    EXPECT_EQ(w.getType(), "Laser Cannon");
    EXPECT_EQ(w.getDamage(), 50);
}

TEST(WeaponTest, SetGetType) {
    Weapon w;
    w.setType("Plasma Rifle");
    EXPECT_EQ(w.getType(), "Plasma Rifle");
}

TEST(WeaponTest, SetGetDamage) {
    Weapon w;
    w.setDamage(80);
    EXPECT_EQ(w.getDamage(), 80);
}

TEST(WeaponTest, GreaterThanOperator) {
    Weapon w1("Weapon1", 100);
    Weapon w2("Weapon2", 50);
    EXPECT_TRUE(w1 > w2);
}

TEST(WeaponTest, LessThanOperator) {
    Weapon w1("Weapon1", 30);
    Weapon w2("Weapon2", 60);
    EXPECT_TRUE(w1 < w2);
}

TEST(WeaponTest, OutputOperator) {
    Weapon w("Rocket Launcher", 150);

    std::ostringstream output;
    output << w;

    std::string expected_output = "Type: Rocket Launcher\nDamage: 150";
    EXPECT_EQ(output.str(), expected_output);
}
