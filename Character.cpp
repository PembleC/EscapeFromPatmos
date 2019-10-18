#include <iostream>
#include <cassert>


#include "Character.h"

using namespace std;


Character::Character() {
    name = " ??? ";
    healthPoints = 100;

    weapon = new Weapon("Bare Hands", 1, 0);
    armor = new Armor("Skin", 0, 0);
}

Character::Character(const std::string& nameVal)
{
    name = nameVal;
    healthPoints = 100;


    weapon = new Weapon("Bare Hands", 1, 0);
    armor = new Armor("Skin", 0, 0);
}

Character::Character(const std::string& nameVal, int health)
{
    name = nameVal;
    healthPoints = health;


    weapon = new Weapon("Bare Hands", 1, 0);
    armor = new Armor("Skin", 0, 0);
}

void Character::print() const
{
    cout << name << endl;
    cout << "Health: " << healthPoints << endl;
    cout << "Armor: " << armor->toString() << endl;
    cout << "Weapon: " << weapon->toString() << endl;
    cout << "Inventory: " << endl;
    cout << "-----------------------------------" << endl;
    for(int i = 0; i < INVENTORY_SIZE; i++) {
        if(inventory[i] != nullptr) {
            cout << "[" << i+1 << "] " << inventory[i]->toString() << endl;
        }
    }
    cout << "-----------------------------------" << endl;
}

int Character::getHealthPoints() const
{
    return healthPoints;
}

void Character::takeDamage(int amount)
{

    if (amount <= getArmor()->getProtection())
        return;

    int damageTaken = amount - getArmor()->getProtection();
    healthPoints = getHealthPoints() - damageTaken;
}


bool Character::aquire(Item* item)
{
    for(int i = 0; i < INVENTORY_SIZE; i++) {
        if(inventory[i] == nullptr) {
            inventory[i] = item;
            return true;
        }
    }
    return false;
}

bool Character::hasItem(Item *item){
    bool answer = false;
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        if (inventory[i] != nullptr && inventory[i] == item)
              answer = true;
    }
    return answer;
}

bool Character::equip(int itemNumber)
{
    if (inventory[itemNumber] == nullptr)
        return false;

    if (dynamic_cast<Weapon*>(inventory[itemNumber]) != nullptr){
        weapon = static_cast<Weapon*>(inventory[itemNumber]);
        return true;
    }

    if (dynamic_cast<Armor*>(inventory[itemNumber]) != nullptr){
        armor = static_cast<Armor*>(inventory[itemNumber]);
        return true;
    }

    else
        return false;
}


Weapon* Character::getWeapon()
{
    return weapon;
}

Armor* Character::getArmor()
{
    return armor;
}

string Character::getName() const
{
    return name;
}

int Character::getTotalValue() const{

    int valuePoints = 0;

    for(int i = 0; i < INVENTORY_SIZE; i++) {
        if(inventory[i] != nullptr) {
            valuePoints += inventory[i]->getValue();
        }
    }

    return valuePoints;
}
