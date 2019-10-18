#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

class Item {
private:
    string name;
    int value;

public:
    Item ();
    Item (string namegiven, int cost);
    string getName() const;
    int getValue() const;
    virtual string toString();

};


#endif // ITEM_H
