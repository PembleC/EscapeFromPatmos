#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include "Item.h"
#include "Character.h"

using namespace std;

enum Direction {
    NORTH, EAST, SOUTH, WEST
};

class Room
{

private:
    string name;
    bool visited;
    bool exit;
    bool locked;
    Item* thing;
    Character* person;
    Room* neighbors[4];

public:
    Room();
    Room(string locName, bool islocked, bool isTheExit);
    Room(string locName, bool islocked, bool isTheExit, Item* thingHere);
    Room(string locName, bool islocked, bool isTheExit, Item* thingHere, Character* personHere);
    bool hasNeighbor(Direction dir) const;
    Room* getNeighbor(Direction dir);
    void setNeighbor(Direction dir, Room* neighborLoc);
    void visit();
    bool isVisited() const;
    bool isExit() const;
    bool isLocked() const;
    void unlockDoor();
    string getName() const;
    string getDescription();

    bool hasItem();
    Item* getItem();
    bool hasCharacter();
    Character* getCharacter();
    void removeCharacter();

};

#endif // ROOM_H
