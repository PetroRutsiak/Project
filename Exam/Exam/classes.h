#include <string>

class Hero
{
    int ID;
    std::string Name;
    int Health;
    int Damage;
public:
    int GetId() { return ID; }
    std::string GetName() { return Name; }
    int GetHP() { return Health; }
    int GetDamage() { return Damage; }

    int setHP(int hp)
    {
        this->Health = hp;
    }

    Hero(int id, std::string name, int hp, int damage)
        :ID(ID), Name(name), Health(hp), Damage(damage) {}
    Hero() {}
};
class Player
{
    int ID;
    std::string Name;
    int Rank;
public:
    int GetId() { return ID; }
    std::string GetName() { return Name; }
    int GetRank() { return Rank; }

    void SetRank(int newRank) {
        if (newRank > 0)
            Rank = newRank;
        else Rank = 0;
    }


    Player(int id, std::string name, int rank)
        :ID(id), Name(name), Rank(rank) {}
    Player() {}
};
class Team
{
public:
    std::string Name;
    Hero HeroList[5];
    Player PlayerList[5];
    Team(std::string name) :Name(name) {}
    Team(std::string name, Hero heroList[5], Player playerList[5]) :Name(name) {
        for (int i = 0; i < 5; i++)
        {
            HeroList[i] = heroList[i];
            PlayerList[i] = playerList[i];
        }
    }
    Team() {}
};