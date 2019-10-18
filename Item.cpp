#include "Item.h"
#include <string>
// #include <iostream>

using namespace std;

Item::Item () {
    name = "IDK?";
    value = 0;
}

Item::Item (string namegiven, int cost){
    name = namegiven;
    value = cost;
}

string Item::getName() const{
    return name;
}

int Item::getValue() const{
    return value;
}

string Item::toString() {
    string itemDescription = "";

    itemDescription = getName();
    itemDescription += " (value: ";
    itemDescription += to_string(getValue());
    itemDescription += ")";

    return itemDescription;
}

