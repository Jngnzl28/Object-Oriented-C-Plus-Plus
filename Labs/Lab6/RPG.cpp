#include "RPG.h"


RPG::RPG()
{
    this->name="NPC";
    this->health=100;
    this->strength=10;
    this->defense=10;
    this->type="warrior";
    this->skills[0]="slash";
    this->skills[1]="parry";
}

RPG::RPG(string name, int health, int strength, int defense, string type)
{
    this->name=name;
    this->health=health;
    this->strength=strength;
    this->defense=defense;
    this->type=type;
    setSkills();
}

void RPG::setSkills()
{
    if (type == "mage")
    {
        skills[0]="fire";
        skills[1]="thunder";
    } else if (type == "thief")
    {
        skills[0]="pilfer";
        skills[1]="jab";
    } else if (type == "archer")
    {
        skills[0]="parry";
        skills[1]="crossbow_attack";
    } else
    {
        skills[0]="slash";
        skills[1]="parry";
    }
    
}

void RPG::printAction(string skill, RPG opponent)
{
    printf("%s used %s on %s\n", name.c_str(), skill.c_str(), opponent.getName().c_str());
}

void RPG::updateHealth(int new_health)
{
    health = new_health;
}

bool RPG::isAlive() const
{
    return health != 0;
}

string RPG::getName() const
{
    return name;
}

int RPG::getHealth() const
{
    return health;
}

int RPG::getStrength() const
{
    return strength;
}

int RPG::getDefense() const
{
    return defense;
}

void RPG::attack(RPG * opponent)
{
    int opp_health = (*opponent).getHealth();
    int opp_def = (*opponent).getDefense();
    if(strength-opp_def > 0)
    {
        int new_health = opp_health - (strength - opp_def);
        (*opponent).updateHealth(new_health);
    }
    else
    {
        int new_health = opp_health;
        (*opponent).updateHealth(new_health);
    }
    

    
}

void RPG::useSkill(RPG * opponent)
{
    // use a for loop to display player skills
    for(int i = 0;i <SKILL_SIZE; i++)
    {
        printf("Skill %i: %s\n", i, skills[i].c_str());
    }
    
    //create an int called chosen_skill_index
    int chosen_skill_index;

    //print 
    printf("Choose a skill to use: Enter 0 or 1\n");

    //get user input to get chosen skill
    cin >> chosen_skill_index;
    
    //assigns chosen skill into a string called chosen_skill
    string chosen_skill = skills[chosen_skill_index];
    
    //call printAction(string, RPG) and use chosen_skill and (*opponent)
    //as the parameters
    printAction(chosen_skill,(*opponent));
    
    //call to attack the opponent
    attack(opponent);
}