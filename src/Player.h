/**
 * @file Player.h 
 * @brief The class that represents player.
 * @author Dmytro Molokoiedov
 * @bugs No known bugs.
 */
#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <string>
#include "TowerA.h"
#include "TowerB.h"
#include "PlayGround.h"

using namespace std;

class Player
{
private:
    vector<Tower*> towers; ///< Vector of towers that player have.
    int gold; ///< Player's gold.
    string name; ///< Player's name.
    int health; ///< Player's health.
public:
    /**
     * @brief Constructors for player
     * @param name, gold
     */
    Player(string name, int gold);
    Player() {}
    /**
     * @brief Method that sets a tower on the playground if it is possible.
     * @param playground, tower
     * @return bool
     */
    bool setTower(PlayGround & playground, Tower * tower);
    /**
     * @brief Method that sells a tower if it is possible.
     * @param playground, tower
     * @return bool
     */
    bool sellTower(PlayGround & playground, Tower * tower);
    /**
     * @brief Getter of the parameter gold
     * @return int
     */
    int Gold() const;
    /**
     * @brief Getter of the parameter health 
     * @return int
     */
    int Health() const;
    /**
     * @brief Getter of the parameter name
     * @return string
     */
    string Name() const;
    /**
     * @brief Method that updates fire for all towers.
     * @param a, b
     * @return void
     */
    void updateFire(int a, int b);
    /**
     * @brief Method that adds player's gold.
     * @param a
     * @return void
     */
    void addGold(int a);
    /**
     * @brief Method that takes away some player's health.
     * @param a
     * @return void
     */
    void minusHealth(int a);
    /**
     * @brief Getter of the parameter towers
     * @return vector <Tower*>
     */
    vector <Tower*> Towers() const;
};

#endif // PLAYER_H_INCLUDED
