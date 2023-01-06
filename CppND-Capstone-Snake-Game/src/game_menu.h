#ifndef GAME_MENU_H
#define GAME_MENU_H
#include <iostream>
#include "player_info.h"
#include <vector>

using std::vector;

class GameMenu
{

public:
    GameMenu()
    {

        std::cout << " " << std::endl;
    };

   
    bool InitMenu();
   
    static bool quit_game_flag;


   
   
};
#endif