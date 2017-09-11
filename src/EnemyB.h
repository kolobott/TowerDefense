/**
 * @file EnemyB.h 
 * @brief This class is a derivate from the class Enemy.
 * @author Dmytro Molokoiedov
 * @bugs No known bugs.
 */
#ifndef ENEMYB_H_INCLUDED
#define ENEMYB_H_INCLUDED

#include <string>
#include "Enemy.h"

using namespace std;

class EnemyB: public Enemy
{
private:
    int health, power; /**< health and power of the enemy.*/
    bool alive; /**< determines enemy is alive or not */
    string color; /** it is a color of the enemy B you cannot see =) */
public:
    /**
     * @brief Constructor that creates an enemy and sets health and power.
     * @param health, power
     */
    EnemyB(int health, int power);
    /**
     * @brief Getter of the parameter alive
     * @return bool
     */
    virtual bool isAlive() const;
    /**
     * @brief Methot that kills enemy
     * @return void
     */
    virtual void Dead();
    /**
     * @brief Getter of the parameter health 
     * @return int
     */
    virtual int Health() const;
    /**
     * @brief Getter of the parameter health 
     * @return int
     */
    virtual int Power() const;
    /** 
     * @brief Method that moves enemy to x, y
     * @param x, y
     * @return void
     */
    virtual void Move(int x, int y);
    /**
     * @brief Method that hits enemy and takes away some health
     * @param health
     * @return void
     */
    virtual void hitted(int health);
    /**
     * @brief Getter of the parameter color
     * @return string
     */
    string Color() const;
};


#endif // ENEMYB_H_INCLUDED
