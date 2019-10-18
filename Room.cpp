#include "Room.h"


Room::Room()
{
    name = "?";
    visited = false;
    locked = false;
    exit = false;

    thing = nullptr;
    person = nullptr;

    for(int i = 0; i < 4; i++){
        neighbors[i] = nullptr;
    }
}

Room::Room(string locName, bool islocked, bool isTheExit){
    name = locName;
    visited = false;
    locked = islocked;
    exit = isTheExit;

    thing = nullptr;
    person = nullptr;

    for(int i = 0; i < 4; i++){
        neighbors[i] = nullptr;
    }
}

Room::Room(string locName, bool islocked, bool isTheExit, Item* thingHere){
    name = locName;
    visited = false;
    locked = islocked;
    exit = isTheExit;

    thing = thingHere;
    person = nullptr;

    for(int i = 0; i < 4; i++){
        neighbors[i] = nullptr;
    }
}

Room::Room(string locName, bool islocked, bool isTheExit, Item* thingHere, Character* personHere){
    name = locName;
    visited = false;
    locked = islocked;
    exit = isTheExit;

    thing = thingHere;
    person = personHere;

    for(int i = 0; i < 4; i++){
        neighbors[i] = nullptr;
    }
}

bool Room::hasNeighbor(Direction dir) const{
    if(neighbors[dir] != nullptr)
        return true;
    else
        return false;
}

Room* Room::getNeighbor(Direction dir){
    if(hasNeighbor(dir) == true)
        return neighbors[dir];
    else
        return nullptr;

}

void Room::setNeighbor(Direction dir, Room *neighborLoc){
    neighbors[dir] = neighborLoc;
}

void Room::visit(){
    visited = true;
}

bool Room::isVisited() const{
    if(visited == true)
        return true;
    else
        return false;
}

bool Room::isExit() const {
    if(exit == true)
        return true;

    else
        return false;
}

bool Room::isLocked() const {
 if (locked == true)
     return true;
 else
     return false;
}

void Room::unlockDoor() {
    locked = false;
}

string Room::getName() const{
    return name;
}

bool Room::hasItem(){
    if(thing != nullptr)
        return true;
    else
        return false;
}

Item* Room::getItem() {
    return thing;
}

bool Room::hasCharacter(){
    if(person != nullptr)
        return true;
    else
        return false;
}

Character* Room::getCharacter() {
    return person;
}

void Room::removeCharacter(){
    person = nullptr;
}

string Room::getDescription(){
    string description = "";

    string directs[4] = {"north","east","south","west"};

    if (isVisited() == true)
        description += "Bread crumbs... ";
    else
        description += " ";

    if(hasItem() == true && isVisited() == false){
        description += "*** You found " + getItem()->getName() += " ***   ";
        description += "You placed it in your inventory, press [i] to view. \n";
    }

    description += " Door(s): ";

    for (int i = 0; i < 4; i++){
        if(getNeighbor(static_cast<Direction>(i)) != nullptr)
            description += directs[i] + " ";
        else
            description += "";
    }

    return description;

}

