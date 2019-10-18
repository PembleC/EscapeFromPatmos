#include "Armor.h"
#include <string>

using namespace std;

Armor::Armor()
    : Item()
{
    protection = 0;
}

Armor::Armor (string namegiven, int protectionvalue, int cost)
    : Item(namegiven, cost)
{
    protection = protectionvalue;
}

string Armor::toString(){
    string itemDescription = "";

    itemDescription += Item::toString();
    itemDescription += " Protection: ";
    itemDescription += to_string(getProtection());

    return itemDescription;
}

int Armor::getProtection() const{
    return protection;
}
