#include"RPG.h"

void displayStats(RPG player1, RPG player2)
{

}

void displayEnd(RPG player1, RPG player2)
{

}

void gameLoop(RPG * player1, RPG * player2)
{

}

int main()
{
    string name = "NPC";
    int health = 0;
    int strength = 10;
    int defense = 10;
    string type = "mage";

    RPG rpga = RPG();
    RPG rpgb = RPG(name, health, strength, defense, type);

    cout << rpgb.isAlive() << endl;
    cout << rpga.isAlive() << endl;

    rpga.updateHealth(20);

    cout << rpga.getHealth()<< endl;

    return 0;
    
}