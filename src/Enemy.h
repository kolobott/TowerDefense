/**
 * @file Enemy.h 
 * @brief An abstract class that derivates two classes: EnemyA and EnemyB.
 * @author Dmytro Molokoiedov
 * @bugs No known bugs.
 */
#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED


class Enemy
{
protected:
    int x, y, fire; /**< x, y coordinate of the enemy and its fire */
    char name; /** enemie's name (% or @) */
public:
    /** 
     * @brief Constructor that sets name of enemy.
     * @param name
     */
    Enemy(char name);
    /**
     * @brief Getter of the parameter x
     * @return int
     */
    virtual int X() const;
    /**
     * @brief Getter of the parameter y
     * @return int
     */
    virtual int Y() const;
    /**
     * @brief Getter of the parameter name
     * @return char
     */
    virtual char Name() const;
    /**
     * @brief Abstract getter of the parameter alive
     * @return bool
     */
    virtual bool isAlive() const = 0;
    virtual void Dead() = 0;
    /**
     * @brief Abstract getter of the parameter power
     * @return int
     */
    virtual int Power() const = 0;
    /**
     * @brief Abstract getter of the parameter health
     * @return int
     */
    virtual int Health() const = 0;
    /** 
     * @brief Abstract method that moves enemy to x, y
     * @param x, y
     * @return void
     */
    virtual void Move(int x, int y) = 0;
    /**
     * @brief Method that hits enemy and takes away some health
     * @param health
     * @return void
     */
    virtual void hitted(int health) = 0;
};

#endif // ENEMY_H_INCLUDED
