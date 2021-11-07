#include <iostream>
#include <string>
#include <list>
#include <ctime>
#include <chrono>
#include <thread>
#include <algorithm>
#include <cstdlib>

std::string getHeroName(int number)
{
    switch (number)
    {
    case 0: return "Abaddon";
    case 1: return "Axe";
    case 2: return "Dragon Knight";
    case 3: return "OgreMage";
    case 4: return "SkeletonKing";
    case 5: return "Troll";
    case 6: return "Viper";
    case 7: return "Underlord";
    case 8: return "Bane";
    case 9: return "Doom";
    case 10:return "Disruptor";
    case 11:return "Enigma";
    case 12:return "Enigma";
    case 13:return "CentaurWarruner";
    case 14:return "Lich";
    case 15:return "Lina";
    case 16:return "Sven";
    case 17:return "Naix";
    case 18:return "Invoker";
    case 19:return "Legion";
    case 20:return "Meepo";
    }
    return"Error!";
}
std::string getPlayerName(int number)
{
    switch (number)
    {
    case 0: return "Fireman";
    case 1: return "Eazy";
    case 2: return "Darius";
    case 3: return "Sensei";
    case 4: return "Senpai";
    case 5: return "S1mple";
    case 6: return "Niko";
    case 7: return "Reeper";
    case 8: return "Javelin";
    case 9: return "Joe";
    case 10:return "Pito";
    case 11:return "NoobMaster";
    case 12:return "WoopWoop";
    case 13:return "Taraslav";
    case 14:return "Sein";
    case 15:return "Kuyol";
    case 16:return "Kola";
    case 17:return "Maximus";
    case 18:return "Paralyzed";
    case 19:return "Arheim";
    case 20:return "Haskie";
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
    void setId(int newid) { id = newid; }
    void setName(std::string newname) { name = newname; }
    void setHP(int newhealth) { health = newhealth; }
    void setDamage(int newdamage) { damage = newdamage; }
    Hero (int id,int damage, int health,  std::string name)
    {
        this->id = id;
        this->damage = damage;
        this->name = name;
        this->health = health;
    }
    std::string getName() { return name;}
    int getID() { return id; }
    int getHealth() { return health; }
    int getDamage() { return damage; }
    Hero(){ }
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
    int getID() { return id; }
    void setRank(int newrank) { rank = newrank; }
    int getRank() { return rank; }
    std::string getName() { return name; }
    Player(int id, int rank, std::string name)
    {
        this->id = id;
        this->rank = rank;
        this->name = name;
    }
    Player() { }
    void Print()
    {
        std::cout << this->getName() << " " << this->getID() << " " << this->getRank();
    }
};
class Team
{
public:
    std::string team_name;
    Player  player_list[5];
    Hero hero_list[5];
    Team(std::string team_name, Player player_list[5], Hero hero_list[5])
    {
        this->team_name = team_name;
        for (int i = 0; i < 5; i++)
        {
            this->player_list[i] = player_list[i];
        }
        for (int i = 0; i < 5; i++)
        {
            this->hero_list[i] = hero_list[i];
        }
    }
};
class PlayerManager
{
public:
    Player CreatePlayer()
    {
        srand (time (NULL));
        std::this_thread::sleep_for(std::chrono::milliseconds(900));
        int randomid = rand() % 100;
        int randomrank = rand() % 100;
        Player player(randomid, randomrank, " Arheim ");   
        return player;
    }
    void ShowPlayerInfo(Player player)
    {
        player.Print();
    }
};
class HeroManager
{
public:
    Hero CreateHero()
    {
        srand(time(NULL));
        std::this_thread::sleep_for(std::chrono::milliseconds(900));
        int randomid = rand() % 100;
        int randomHP = rand() % 100;
        int randomDamage = rand() % 100;
        Hero hero(randomid, randomHP, randomDamage, " Orc ");
        return hero;
    }
    void ShowInfo(Hero hero)
    {
        hero.Print();
    }
};
class TeamManager
{
public:
    Team  GenerateNewTeam()
    {
        HeroManager heromanager;
        PlayerManager playermanager;
        Player player_list[5];
        Hero hero_list[5];
        for (int i = 0; i < 5; i++)
        {
            Hero Hero = heromanager.CreateHero();
            hero_list[i] = Hero;
        }
        for (int i = 0; i < 5; i++)
        {
            Player Player = playermanager.CreatePlayer();
            player_list[i] = Player;
        }
        Team first(" Dire ", player_list, hero_list);
        return first;
    }
    void GetTeamInfo(Team first)
    {
        std::cout << first.team_name << "\n";
        for (int i = 0; i < 5; i++)
        {
            first.hero_list[i].Print();
            std::cout << std::endl;
        }
        for (int i = 0; i < 5; i++)
        {
            first.player_list[i].Print();
            std::cout << std::endl;
        }
    }
};


int main()
{
    TeamManager newteam;
    Team Radiant = newteam.GenerateNewTeam();
    newteam.GetTeamInfo(Radiant);

    return 0;
}
