#ifndef ARMOR_H
#define ARMOR_H

#include "Item.h"

using namespace std;

class Armor : public Item {
private:
    int protection;

public:
    Armor ();
    Armor (string namegiven, int protectionValue, int cost);
    int getProtection() const;
    string toString();
};


#endif // ARMOR_H
