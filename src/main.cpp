#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <list>
#include <iomanip>
#include <fstream>
#include <stdexcept>
#include "Game.h"

using namespace std;

int main()
{
    try
    {
        Game game;
        game.initialize();
        game.run();
    }
    catch(invalid_argument& a)
    {
        cout<<a.what()<<endl;
    }
}
