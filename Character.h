#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

#include "Item.h"
#include "Armor.h"
#include "Weapon.h"


class Character
{
public:

    Character();
    Character(const std::string& nameVal);
    Character(const std::string& nameVal, int health);

    void print() const;
    int getHealthPoints() const;
    string getName() const;
    void takeDamage(int amount);
    void attack(Character& target);
    bool aquire(Item* item);
    bool hasItem(Item* item);
    bool equip(int itemNumber);
    Weapon* getWeapon();
    Armor* getArmor();
    int getTotalValue() const;

private:
    std::string name;
    int healthPoints;

    //Pointers to the currently equiped weapon/armor
    Weapon* weapon;
    Armor* armor;

    //Inventory is an array of 10 pointers to Items
    const static int INVENTORY_SIZE = 10;
    Item* inventory[INVENTORY_SIZE] = {0};

    //Default armor/weapon
    Armor skin = Armor("Skin", 0, 0);
    Weapon hands = Weapon("Bare Hands", 1, 0);
};

#endif // CHARACTER_H
