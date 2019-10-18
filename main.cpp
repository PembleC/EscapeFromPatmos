#include <iostream>
#include <stdio.h>
#include "Room.h"
#include "Character.h"
#include <unistd.h>
#include <time.h>
#include <cstdlib>

using namespace std;

const int NUM_LOCATIONS = 18;
const int NUM_ITEMS = 10;
const int NUM_WEAPONS = 10;
const int NUM_ENEMIES = 10;
const int NUM_ARMORS = 10;

// UPDATED VERSION 5/18/18
// Added ! to end the game.
// UPDATED VERSION 6/11/18
// Can't fix name
// UPDATED VERSION 8/15/18
// Fixed the escaping battles

// UPLOADED TO GITHUB 10/17/19

void buildMap(Room allLocations[], Item allItems[], Weapon allWeapons[], Character allEnemies[], Armor allArmors[]) {


    //========================= ITEMS ==============================//

    Item key1("a small key", 5);
    Item key2("a golden key", 10);
    Item diamond("a flawless diamond", 100);
    Item coal("a lump of coal", 1);
    Item bread("a loaf of bread", 1);
    Item coin1("a coin purse", 20);
    Item coin2("a coin purse", 25);


    allItems[0] = key1;
    allItems[1] = key2;
    allItems[2] = diamond;
    allItems[3] = coal;
    allItems[4] = bread;
    allItems[5] = coin1;
    allItems[6] = coin2;


    //========================= WEAPONS =========================//


    Weapon butterKnife("butter knife", 5, 1);
    Weapon woodSword("wooden sword", 15, 10);
    Weapon woodMace("wooden mace", 12, 15);
    //Weapon jesusSpear("Spear of Destiny", 18, 50);


    allWeapons[0] = butterKnife;
    allWeapons[1] = woodSword;
    allWeapons[2] = woodMace;


    //========================= ARMORS =========================//


    Armor leather("leather armor", 5, 10);
    Armor chainMail("chain mail armor", 15, 40);

    // Armor-class codeName("GameName", protection, value)


    allArmors[0] = leather;
    allArmors[1] = chainMail;



    //========================= ENEMIES =========================//

    Character skeleton("skeleton", 10);

    Character armedSkeleton("an armed skeleton", 10);
    armedSkeleton.aquire(&allWeapons[0]);
    armedSkeleton.equip(0);

    Character vilemyr("Vilemyr", 50);
    vilemyr.aquire(&allWeapons[2]);
    vilemyr.equip(0);

    allEnemies[0] = skeleton;
    allEnemies[1] = armedSkeleton;
    allEnemies[2] = vilemyr;


    // ============= Create Rooms ============ //

    allLocations[0] = Room(" a special room", 0, 0, &allItems[0]);
    allLocations[1] = Room(" The Secret Cave of Patmos", 0, 0, &allItems[4]);
    allLocations[2] = Room(" a musty passage", 0, 0);
    allLocations[3] = Room(" a collapsed cavern", 0, 0);
    allLocations[4] = Room(" an empty hallway", 0, 0);
    allLocations[5] = Room(" a lifeless room", 0, 0, &allItems[5], &allEnemies[0]);
    allLocations[6] = Room(" a smelly tunnel", 0, 0);
    allLocations[7] = Room(" the shores of an underground lake", 0, 0);
    allLocations[8] = Room(" an abandoned prison", 0, 0, &allWeapons[1]);
    allLocations[9] = Room(" a winding path", 0, 0, &allArmors[0]);
    allLocations[10] = Room(" an open space", 1, 0);
    allLocations[11] = Room(" Vilemyr's house", 0, 0, &allItems[6] ,&allEnemies[2]);
    allLocations[12] = Room(" a passage to the surface", 1, 0);
    allLocations[13] = Room(" the thief's hideout", 0, 0, &allItems[1], &allEnemies[1]);
    allLocations[14] = Room(" a fallen castle", 0, 0);
    allLocations[15] = Room(" a decayed treasury", 0, 0, &allItems[2]);
    allLocations[16] = Room(" the surface", 0, 1);
    allLocations[17] = Room(" a dead end", 0, 0, &allItems[3]);

    // ============ Create Map ============= //

    allLocations[0].setNeighbor(EAST, &allLocations[4]);

    allLocations[1].setNeighbor(SOUTH, &allLocations[2]);

    allLocations[2].setNeighbor(NORTH, &allLocations[1]);
    allLocations[2].setNeighbor(EAST, &allLocations[6]);
    allLocations[2].setNeighbor(SOUTH, &allLocations[3]);

    allLocations[3].setNeighbor(NORTH, &allLocations[2]);
    allLocations[3].setNeighbor(EAST, &allLocations[7]);
    allLocations[3].setNeighbor(SOUTH, &allLocations[4]);

    allLocations[4].setNeighbor(NORTH, &allLocations[3]);
    allLocations[4].setNeighbor(EAST, &allLocations[8]);
    allLocations[4].setNeighbor(WEST, &allLocations[0]);

    allLocations[5].setNeighbor(NORTH, &allLocations[8]);

    allLocations[6].setNeighbor(EAST, &allLocations[10]);
    allLocations[6].setNeighbor(SOUTH, &allLocations[7]);
    allLocations[6].setNeighbor(WEST, &allLocations[2]);

    allLocations[7].setNeighbor(NORTH, &allLocations[6]);
    allLocations[7].setNeighbor(SOUTH, &allLocations[8]);
    allLocations[7].setNeighbor(WEST, &allLocations[3]);

    allLocations[8].setNeighbor(NORTH, &allLocations[7]);
    allLocations[8].setNeighbor(SOUTH, &allLocations[5]);
    allLocations[8].setNeighbor(WEST, &allLocations[4]);

    allLocations[9].setNeighbor(EAST, &allLocations[13]);
    allLocations[9].setNeighbor(SOUTH, &allLocations[10]);

    allLocations[10].setNeighbor(NORTH, &allLocations[9]);
    allLocations[10].setNeighbor(EAST, &allLocations[14]);
    allLocations[10].setNeighbor(SOUTH, &allLocations[11]);
    allLocations[10].setNeighbor(WEST, &allLocations[6]);

    allLocations[11].setNeighbor(NORTH, &allLocations[10]);
    allLocations[11].setNeighbor(SOUTH, &allLocations[12]);

    allLocations[12].setNeighbor(NORTH, &allLocations[11]);
    allLocations[12].setNeighbor(EAST, &allLocations[16]);

    allLocations[13].setNeighbor(WEST, &allLocations[9]);

    allLocations[14].setNeighbor(EAST, &allLocations[17]);
    allLocations[14].setNeighbor(SOUTH, &allLocations[15]);
    allLocations[14].setNeighbor(WEST, &allLocations[10]);

    allLocations[15].setNeighbor(NORTH, &allLocations[14]);

    allLocations[16].setNeighbor(WEST, &allLocations[12]);

    allLocations[17].setNeighbor(WEST, &allLocations[14]);


}

void startGame() {

    cout << "Welcome to ... " << endl << endl
         << "           The Escape from Patmos" << endl
         << "              By Carson Pemble" << endl << endl << endl;

    cout << "Use the [N], [E], [S], [W] keys and [enter] to pass through the doors: " << endl
         << "North, East, South, West." << endl << endl
         << "As you enter each room, you leave behind a trail of bread crumbs" << endl
         << "to mark where you have been."
         << " Your mission is to escape the maze!" << endl
         << endl;

    sleep(7);

    cout << "If you need help, type [H] and then press [enter]. It will bring up a help menu. " << endl;

    sleep(3);

    cout << endl << "Do you understand? Are you ready to begin? " << endl
         << "Enter [Y] or [N] : ";

    string start = "";
    cin >> start;

    if(start == "y" || start == "Y" || start == "Yes" || start == "yes" || start == "YES")
        sleep(1);

    else {
        while (start != "y" || start != "Y" || start != "Yes" || start != "yes" || start != "YES"){

            sleep (3);
            cout << endl << " Are you ready now? " << endl
                 << "Enter [Y] or [N] : ";

            cin >> start;

            if (start == "y" || start == "Y" || start == "Yes" || start == "yes" || start == "YES")
                break;
        }
    }


    cout << endl;

}

string createCharacterName() {

    cout << "What is your character's name? "<< endl;
    string playerName;

    //getline(cin, playerName);
    cin >> playerName;

    sleep(1);

    cout << endl << "You want your character to be named " << playerName << "?" << endl
         << "Enter [Y] or [N] : ";

    string choice = "";
    cin >> choice;

    if(choice == "y" || choice == "Y" || choice == "Yes" || choice == "yes" || choice == "YES")
        sleep(1);

    else {
        while (choice != "y" || choice != "Y" || choice != "Yes" || choice != "yes" || choice != "YES"){

            cout << endl << "What is your character's name? " << endl;

            //getline(cin, playerName);
            cin >> playerName;

            cout << endl << "You want your character to be named " << playerName << "?" << endl
                 << "Enter [Y] or [N] : ";

            cin >> choice;

            if (choice == "y" || choice == "Y" || choice == "Yes" || choice == "yes" || choice == "YES")
                break;
        }
    }

    cout << endl << "Good luck out there " << playerName << "! ... You'll need it."<< endl << endl << endl;

    sleep(2);

    return playerName;
}

void printHelp() {
    cout << endl << endl
         << " ----- HELP ----- " << endl
         << endl << "QUEST: You are trapped in a cave! You need to escape by" << endl
         << "passing through doors and ultimately finding the surface." << endl << endl
         << "CONTROLS: " << endl
         << "Press [N] to move North." <<endl
         << "Press [E] to move East." << endl
         << "Press [S] to move South." << endl
         << "Press [W] to move West." << endl << endl
         << "Press [I] to open your inventory." << endl
         << "Press [E] to equip items (when inside your inventory)." << endl
         << "Press [C] to close your inventory (when inside your inventory)." << endl << endl
         << "Press [H] to open this help menu." << endl
         << "Press [!] to give up!" << endl << endl
         << "Bread crumbs will remind you if you have been in that room before." << endl
         << "You can unlock locked doors by finding the corresponding key." << endl << endl
         << "     Currently you are in...  " << endl;

}

void openInventory (Character& player){

    cout << endl << endl;
    player.print();

    cout << "You can equip weapons and armors by pressing [E]" << endl
         << "or you can close your inventory by pressing [C]" << endl << endl
         << "Choose E or C: ";

    char choiceInsideInventory;
    cin >> choiceInsideInventory;

    if(choiceInsideInventory == 'E' || choiceInsideInventory == 'e'){
        cout << endl << "What item would you like to equip? " << endl
             << "Insert the item number [#] beside your desired item." << endl
             << "Equip Item #: ";
        int itemNumber;
        cin >> itemNumber;

        if(player.equip(itemNumber - 1)){
            sleep(1);
            cout << endl << "Your item has been equiped "<< endl;
        }

        else
            cout << endl << "That item can NOT be equiped "<< endl;
    }
}

Direction charToDir(char choiceDirection){

    Direction  dir;

    if (choiceDirection == 'n')
        dir = NORTH;

    if (choiceDirection == 'e')
        dir = EAST;

    if (choiceDirection == 's')
        dir = SOUTH;

    if (choiceDirection == 'w')
        dir = WEST;

    return dir;
}

bool surviveEnemy(Room* currentRoom, Character& player) {

    string enemyName = currentRoom->getCharacter()->getName();

    cout << "You encountered "
         << enemyName << "!" << endl;

    cout << "Do you want to try to run away?" << endl
         << "Y or N: ";

    char choice;
    cin >> choice;

    sleep(2);

    srand(static_cast<unsigned int>(time(NULL)));
    int randomDice = rand()%4 + 1;

    if (toupper(choice) == 'Y' && randomDice == 1){

            cout << endl << "You Escaped Safely..." << endl;
            return true;
        }


    else {

        cout << "The escape failed ... " << endl;
        sleep(1);

        cout << endl << enemyName << " sees you and begins to attack you!" << endl;
        sleep(2);

        while(currentRoom->getCharacter()->getHealthPoints() > 0){

            // ======== Enemies Turn ========== //

            string enemyWeapon = currentRoom->getCharacter()->getWeapon()->getName();
            cout << enemyName << " hits you with " << enemyWeapon << "." << endl;

            int damagetaken = currentRoom->getCharacter()->getWeapon()->getDamage();

            if (damagetaken > 4) {
                srand(static_cast<unsigned int>(time(NULL)));
                int randomEnemyDICE = rand()%4 + 1;
                damagetaken = damagetaken - randomEnemyDICE;

                if(damagetaken < 0)
                    damagetaken = 0;

            }

            cout << "You take " << damagetaken << " points of damage" << endl;
            player.takeDamage(damagetaken);

            sleep(2);

            cout << "You now have " << player.getHealthPoints() << " health points. " << endl << endl;

            // ======== Your Turn ============ //

            sleep(2);

            cout << "To attack press [A]... always deals " << player.getWeapon()->getDamage()
                 << " points of damage." << endl
                 << "Or roll for a special attack press [R]... could deal more or less damage." << endl
                 << "A or R: ";

            char choice2;
            cin >> choice2;

            if (toupper(choice2) == 'A'){
                cout << endl << "You hit " << enemyName << " with " << player.getWeapon()->getName() << "." << endl;

                int damagetaken2 = player.getWeapon()->getDamage();
                cout << enemyName << " takes " << damagetaken2 << " points of damage." << endl;
                currentRoom->getCharacter()->takeDamage(damagetaken2);

                sleep(2);
                cout << enemyName << " now has " << currentRoom->getCharacter()->getHealthPoints() << " health points. " << endl << endl;
            }


            else if (toupper(choice2) == 'R'){

                srand(static_cast<unsigned int>(time(NULL)));
                int randomDICE = rand()%6 + 1;
                int randomGorB = rand()%2 + 1;

                string chance = "good";

                if (randomGorB == 1) {
                    chance = "bad";
                    cout << "You rolled a bad : "<< randomDICE << "    (subtracts "<< randomDICE << " from your attack)" << endl;
                }

                else
                    cout << "You rolled a good : "<< randomDICE << "    (adds "<< randomDICE << " to your attack)" << endl;


                sleep(2);

                cout << "You hit " << enemyName << " with " << player.getWeapon()->getName() << "." << endl;

                int damagetaken2 = 0;

                if(chance == "good")
                    damagetaken2 = player.getWeapon()->getDamage() + randomDICE;

                else if (chance == "bad"){
                    damagetaken2 = player.getWeapon()->getDamage() - randomDICE;

                    if(damagetaken2 < 0)
                        damagetaken2 = 0;
                }


                cout << enemyName << " now takes " << damagetaken2 << " points of damage." << endl;
                currentRoom->getCharacter()->takeDamage(damagetaken2);

                sleep(2);
                cout << enemyName << " now has " << currentRoom->getCharacter()->getHealthPoints() << " health points. " << endl << endl;
            }

            else if(toupper(choice2) == 'I'){
                openInventory(player);
            }

            else if(toupper(choice2) == 'H'){
                printHelp();
            }

            sleep(2);

            if (player.getHealthPoints() <= 0){
                return false;
                break;
            }
        }

        cout << "You killed " << currentRoom->getCharacter()->getName() << "!" << endl
             << "You can now safely look around the room. " << endl << endl;

        sleep(1);

        return true;
    }

}

int main() {

    system("clear");
    time_t start,end;
    cout << endl;

    startGame();

    Room allLocations [NUM_LOCATIONS];
    Item allItems [NUM_ITEMS];
    Weapon allWeapons [NUM_WEAPONS];
    Character allEnemies [NUM_ENEMIES];
    Armor allArmors [NUM_ARMORS];

    buildMap(allLocations, allItems, allWeapons, allEnemies, allArmors);

    Character player1(createCharacterName());
    //Character player1("YOU");                                    // speed run option



    // ================= Square One =============== //

    Room* currentLocation = &allLocations[1];

    cout << "  --- it all fades to black ---  " << endl << endl << endl;

    sleep(4);

    system("clear");

    cout << "You wake up feeling dizzy." << endl;
    sleep(3);
    cout << "You can't remember how you got here." << endl;
    sleep(3);
    cout << "All you know is that you need to get out of here and find the surface." << endl;
    sleep(3);
    cout << endl << " You currently seem to be in";

    // ================= Main Game Loop =============== //

    time(&start);

    while(currentLocation != &allLocations[16]){


        if (currentLocation->hasCharacter()) {
            bool alive = surviveEnemy(currentLocation, player1);

            if (alive == false && player1.getHealthPoints() < 0)
                break;

            else
                currentLocation->removeCharacter();
        }

        if (currentLocation == &allLocations[10]
                && currentLocation->isVisited() == false){
            currentLocation->unlockDoor();
            cout << "You unlocked this door with \"a small key\"!" << endl
                 << "You entered,";
        }

        if (currentLocation == &allLocations[12]
                && currentLocation->isVisited() == false){
            currentLocation->unlockDoor();
            cout << "You unlocked this door with \"a golden key\"!" << endl
                 << "You entered,";
        }

        cout << currentLocation->getName() << "." << endl;
        sleep(1);
        cout << currentLocation->getDescription() << endl;

        if(currentLocation->hasItem() && currentLocation->isVisited() == false)
            player1.aquire(currentLocation->getItem());

        currentLocation->visit();

        // ======================= Non-Directional Options ====================== //

        char choice = '@';

        while (choice != 'n' && choice != 'e' && choice != 's' && choice != 'w'){

            cin >> choice;
            choice = static_cast<char>(tolower(choice));

            if (choice == 'h'){
                printHelp();
                cout << currentLocation->getName() << "." << endl;
                cout << currentLocation->getDescription() << endl;
            }

            if (choice == 'i') {
                openInventory(player1);

                sleep(1);
                cout << endl << endl << "You are currently in...  " << endl;
                cout << currentLocation->getName() << "." << endl;
                cout << currentLocation->getDescription() << endl;
            }

            if(choice == '!')
                break;
        }


        // Normal (unlocked)        * works *
        if (currentLocation->hasNeighbor(charToDir(choice)) == true
                && currentLocation->getNeighbor(charToDir(choice))->isLocked() == false)
            currentLocation = currentLocation->getNeighbor(charToDir(choice));

        // 1st Locked w/o key       * works *
        else if (currentLocation->hasNeighbor(charToDir(choice)) == true
                 && currentLocation->getNeighbor(charToDir(choice))->isLocked() == true
                 && currentLocation == &allLocations[6] && player1.hasItem(&allItems[0]) == false)
            cout << "This door seems to be locked by a small lock. Try to find the key." << endl
                 << "You are still in:";

        // 2nd Locked w/o key       * works *
        else if (currentLocation->hasNeighbor(charToDir(choice)) == true
                 && currentLocation->getNeighbor(charToDir(choice))->isLocked() == true
                 && currentLocation == &allLocations[11] && player1.hasItem(&allItems[1]) == false)
            cout << "This door has a golden lock on it. Try to find the key" << endl
                 << "You are still in:";

        // 1st Locked w/ key        * works *
        else if (currentLocation->hasNeighbor(charToDir(choice)) == true
                 && currentLocation->getNeighbor(charToDir(choice))->isLocked() == true
                 && currentLocation == &allLocations[6] && player1.hasItem(&allItems[0]))
            currentLocation = currentLocation->getNeighbor(charToDir(choice));

        // 2nd Locked w/ key        * works *
        else if (currentLocation->hasNeighbor(charToDir(choice)) == true
                 && currentLocation->getNeighbor(charToDir(choice))->isLocked() == true
                 && currentLocation == &allLocations[11] && player1.hasItem(&allItems[1]))
            currentLocation = currentLocation->getNeighbor(charToDir(choice));

    }

    time(&end);


    if(player1.getHealthPoints() > 0) {

        cout << endl << "#################################" << endl << endl
             << "             YOU ESCAPED!      " << endl;

        int elapsedTime = static_cast<int>(difftime(end,start));

        int totalValue = player1.getTotalValue();

        int score = totalValue + ((2000 - elapsedTime));

        cout << endl<< "  Your Final Score is: " << score << endl << endl
             << "#################################" << endl << endl;

        sleep(2);

        cout << "Current High Score..." << endl
             << "1. Tim Nye: 1547" << endl
             << "2. Ash Champagne: 1521" << endl
             << "3. Josh Sullenger: 1105" << endl
             << "4. Amy Rodriguez: 903" << endl
             << "5. Byron Theissen: 858" << endl
             << "  (Max Score: 2100)  " << endl << endl;

        // Carson Scores around 1950

        cout << "Thank you for playing!" << endl << endl;
    }

    else {
        cout << endl << "#################################" << endl << endl
             << "           YOU DIED      " << endl << endl
             << "#################################" << endl;
    }
}
