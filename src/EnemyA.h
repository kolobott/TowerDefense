/**
 * @file EnemyA.h 
 * @brief This class is a derivate from the class Enemy.
 * @author Dmytro Molokoiedov
 * @bugs No known bugs.
 */
#ifndef ENEMYA_H_INCLUDED
#define ENEMYA_H_INCLUDED

#include "Enemy.h"


class EnemyA: public Enemy
{
private:
    int health, power; /**< health and power of the enemy.*/
    bool alive; /**< determines enemy is alive or not */
public:
    /**
     * @brief Constructor that creates an enemy and sets health and power.
     * @param health, power
     */
    EnemyA(int health, int power);
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
};

#endif // ENEMYA_H_INCLUDED
