#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include "Item.h"

//forward declare the class Character to prevent circular header dependency
class Character;

class Weapon : public Item {
private:
    int damage;

public:
    Weapon ();
    Weapon (string namegiven, int damageValue, int cost);
    int getDamage() const;
    virtual int getRange() const;
    string toString();
};



#endif // WEAPON_H
