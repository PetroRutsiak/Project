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
class PlayerManager
{
public:
    bool isNameExist(Player playerlist[], int lenght, std::string name)
    {
        for (int i = 0; i < lenght; i++)
        {
            if (playerlist[i].GetName() == name)
            {
                return true;
            }
        }
        return false;
    }
    void  ShowPlayerInfo(Player  player)
    {

        std::cout
            << "\tName: " << player.GetName()
            << "\tRank: " << player.GetRank() << std::endl;

    }
    Player* DeletePlayer(Player playerlist[], int lenght, int pos)
    {
        Player* new_playerlist = new Player[lenght - 1];

        for (int i = 0; i < lenght - 1; i++)
        {
            if (pos >= i)
            {
                new_playerlist[i] = playerlist[i + 1];
                continue;
            }
            new_playerlist[i] = playerlist[i];
        }

        return new_playerlist;
    }
    Player CreatePlayer(Player* playerlist, int lenght)
    {
        srand((unsigned)time(NULL));
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        int randomPlayerName = rand() % 20;
        int randomPlayerRank = rand() % 1001;
        int randomID = rand() % 1001;

        std::string Name = getPlayerName(randomPlayerName);
        while (isNameExist(playerlist, lenght, Name))
        {
            Name = getPlayerName(randomPlayerName);
        }
        Player player(randomID, Name, randomPlayerRank);

        return player;
    }
    Player* GetPlayerByName(Player playerlist[], int lenght, std::string name)
    {
        for (int i = 0; i < lenght; i++)
        {
            if (playerlist[i].GetName() == name)
                return &playerlist[i];
        }
        return nullptr;
    }

    Player* GetPlayerById(Player playerlist[], int lenght, int id)
    {
        for (int i = 0; i < lenght; i++)
        {
            if (playerlist[i].GetId() == id)
                return &playerlist[i];
        }
        return nullptr;
    }
};
class HeroManager
{
public:
    bool isNameExist(Hero herolist[], int lenght, std::string name)
    {
        for (int i = 0; i < lenght; i++)
        {
            if (herolist[i].GetName() == name)
            {
                return true;
            }
        }
        return false;
    }
    void static  ShowHeroInfo(Hero  hero)
    {
        std::cout
            << "\tName: " << hero.GetName()
            << "\tHP: " << hero.GetHP()
            << "\tDamage: " << hero.GetDamage() << std::endl;

    }
    Hero* DeleteHero(Hero herolist[], int lenght, int  pos)
    {
        Hero* new_herolist = new Hero[lenght - 1];

        for (int i = 0; i < lenght - 1; i++)
        {
            if (pos >= i)
            {
                new_herolist[i] = herolist[i + 1];
                continue;
            }
            new_herolist[i] = herolist[i];
        }
        return new_herolist;
    }
    Hero  CreateHero(Hero* herolist, int lenght)
    {
        srand((unsigned)time(NULL));
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        int randomHeroName = rand() % 20;
        int randomHeroHealth = rand() % 101;
        int randomHeroDamage = rand() % 101;
        int randomId = rand() % 1001;

        std::string Name = getHeroName(randomHeroName);
        while (isNameExist(herolist, lenght, Name))
        {
            Name = getHeroName(randomHeroName);
        }
        Hero hero(randomId, Name, randomHeroHealth, randomHeroDamage);

        return hero;
    }
    Hero* GetHeroByName(Hero herolist[], int lenght, std::string name)
    {
        for (int i = 0; i < lenght; i++)
        {
            if (herolist[i].GetName() == name)
                return &herolist[i];
        }
        return nullptr;
    }

    Hero* GetHeroById(Hero herolist[], int lenght, int id)
    {
        for (int i = 0; i < lenght; i++)
        {
            if (herolist[i].GetId() == id)
                return &herolist[i];
        }
        return nullptr;
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
