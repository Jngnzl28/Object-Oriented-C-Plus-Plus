#include"RPG.h"



void displayStats(RPG player1, RPG player2)
{
    printf("%s Health: %i   %s Health: %i",player1.getName().c_str(), player1.getHealth(), player2.getName().c_str(), player2. getHealth());
}

void displayEnd(RPG player1, RPG player2)
{
    printf("%s defeated %s! Good game!");
}

void gameLoop(RPG * player1, RPG * player2)
{
    while((*player1).isAlive() || (*player2).isAlive())
    {
        displayStats((*player1), (*player2));
        printf("%s's turn.",(*player1).getHealth());
        (*player1).useSkill(player2);
        printf("-------------------------------------\n");
        
        printf("%s's turn.",(*player2).getHealth());
        (*player2).useSkill(player1);
        printf("-------------------------------------\n");
    }

}

int main()
{
    RPG p1 = RPG("Wiz", 70, 45, 15,"mage");
    RPG p2 = RPG();
    
    printf("%s Current Stats:\n",p1.getName().c_str());
    printf("Health: %i\t Strength: %i\t Defense: %i\n", p1.getHealth(), p1.getStrength(), p1.getDefense());
    
    gameLoop(&p1, &p2);
    displayEnd(p1, p2);
    
    return 0;
    
}

