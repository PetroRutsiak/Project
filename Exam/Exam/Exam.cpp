﻿#include <iostream>
#include <string>
#include <list>

enum HeroType
{
    Goblin,
    Orc,
    Dragon,
    Ogre,
    Skeleton,
    Troll,
    Vempire,
    Zombie,
    Bane,
    Basilisk,
    Beelzebub,
    Bigfoot,
    Boogeyman,
    Centaur,
    Chimera,
    Chuckie
};
std::string getTypeString(HeroType m_type)
{
    switch (m_type)
    {
    case Goblin:return "Goblin";
    case Orc: return "Orc";
    case Dragon: return "Dragon";
    case Ogre: return "Ogre";
    case Skeleton: return "Skeleton";
    case Troll: return "Troll";
    case Vempire: return "Vempire";
    case Zombie: return "Zombie";
    case Bane:return "Bane";
    case Basilisk:return "Basilisk";
    case Beelzebub:return "Beelzebub";
    case Bigfoot:return "Bigfoot";
    case Boogeyman:return "Boogeyman";
    case Centaur:return "Centaur";
    case Chimera:return "Chimera";
    case Chuckie:return "Chuckie";
    }
    return"Error!";
}

class Hero
{

    int id;
    std::string name;
    int health;
    int damage;
public:
    void setId(int newid)
    {
        id = newid;
    }
    void setName(std::string newname)
    {
        name = newname;
    }
    void setHP(int newhealth)
    {
        health = newhealth;
    }
    void setDamage(int newdamage)
    {
        damage = newdamage;
    }
    Hero (int id,int damage, int health,  std::string name)
    {
        this->id = id;
        this->damage = damage;
        this->name = name;
        this->health = health;
    }
    std::string getName()
    {
        return name;
    }
    int getID()
    {
        return id;
    }
    int getHealth()
    {
        return health;
    }
    int getDamage()
    {
        return damage;
    }
    void Print()
    {
        std::cout << this->getName() << " " << this->getID() << " " << this->getDamage() << " " << this->getHealth();
    }
};
class Player
{
    int id;
    int rank;
    std::string name;

public:
    int getID()
    {
        return id;
    }
    void setRank(int newrank)
    {
        rank = newrank;
    }
    int getRank()
    {
        return rank;
    }
    std::string getName()
    {
        return name;
    }
    Player(int id, int rank, std::string name)
    {
        this->id = id;
        this->rank = rank;
        this->name = name;
    }
    void Print()
    {
        std::cout << this->getName() << " " << this->getID() << " " << this->getRank();
    }

};
int main()
{
    Hero* Dragon = new Hero(786, 70, 100, "Centaur");
    Player* Dima = new Player(3, 7, " DimonTheSlayer");
    Dima->Print();
    return 0;
}
