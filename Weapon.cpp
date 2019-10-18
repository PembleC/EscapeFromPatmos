#include "Weapon.h"
#include "Character.h"

Weapon::Weapon()
    : Item()
{
    damage = 0;
}

Weapon::Weapon(string namegiven, int damageValue, int cost)
    :Item (namegiven, cost)
{
    damage = damageValue;
}

int Weapon::getDamage() const{
    return damage;
}

int Weapon::getRange() const{
    return 0;
}

string Weapon::toString(){
    string itemDescription = "";

    itemDescription += Item::toString();
    itemDescription += " Damage: ";
    itemDescription += to_string(getDamage());

    return itemDescription;
}

