/**
 * @file Game.h 
 * @brief The main class that creates the game.
 * @author Dmytro Molokoiedov
 * @bugs No known bugs.
 */
#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>
#include <ctype.h>
#include <limits>
#include <termios.h>
#include <unistd.h>
#include "PlayGround.h"
#include "Player.h"
#include "Cursor.h"
#include "Wave.h"


#define KEY_UP -4
#define KEY_DOWN -3
#define KEY_LEFT -1
#define KEY_RIGHT -2
#define START_WAVE 115
#define SPACE 32
#define CHANGE 99
#define INFORMATION 105
#define EXIT 113

using namespace std;

class Game
{
private:
    int score; /**< player's score */
public:
    /**
     * @brief Constructor
     */
    Game() { score = 0; }
    /**
     * @brief This method sets terminal to non-canonical mode and reads from the keyboard. Analogue of getch() in Windows.
     * @return int
     */
    int myGetch() const;
    /** 
     * @brief Method that calculates gold for the player depending on the size of the playground.
     * @param length, width of the playground
     * @return int
     */		
    int calculateGold( int length, int width ) const;
    /**
     * @brief Method that prints rules of the game on the terminal.
     * @return void
     */
    void initialize() const;
    /**
     * @brief Run the game.
     * @return void
     */
    void run();
};
#endif // GAME_H_INCLUDED
