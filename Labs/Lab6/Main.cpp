#include"RPG.h"


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
