/**
 * @file PlayGround.h 
 * @brief The class that represents playground.
 * @author Dmytro Molokoiedov
 * @bugs No known bugs.
 */
#ifndef PLAYGROUND_H_INCLUDED
#define PLAYGROUND_H_INCLUDED

#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>

using namespace std;

class PlayGround
{
private:
    int width; ///< width of the playground
    int length; ///< length of the playground
    vector< vector<int> > ground; ///< playground
public:
    /**
     * @brief Constructor that creates playground
     * @param length, width
     */
    PlayGround(int length, int width);
    /**
     * @brief Constructor that creates playground with existing map
     * @param help
     */
    PlayGround(vector< vector<int> > help);
    /**
     * @brief Operator << for the playground
     * @param os, a
     * @return ostream &
     */
    friend ostream & operator <<(ostream & os, const PlayGround & a);
    /**
     * @brief Method that updates playground with a tower.
     * @param i, j, tower
     * @return void
     */
    void update(int i, int j, char tower);
    /**
     * @brief Getter of the parameter width
     * @return int
     */
    int getWidth() const;
    /**
     * @brief Getter of the parameter length
     * @return int
     */
    int getLength() const;
    /**
     * @brief Method that checks if there is free on x, y coordinates.
     * @param x, y
     * @return bool
     */
    bool isFree(int x, int y) const;
    /**
     * @brief Getter for the parameter ground
     * @return vector < vector<int> >
     */
    vector< vector<int> > Vector() const;
    /**
     * @brief Support method for method checkWay in class Wave
     * @return vector < vector<int> >
     */
    vector< vector<int> > transform() const;
};


#endif // PLAYGROUND_H_INCLUDED
