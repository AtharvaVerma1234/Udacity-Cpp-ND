#ifndef PLAYER_INFO_H
#define PLAYER_INFO_H
#include <iostream>
#include <string>
#include <vector>
#include "snake.h"

using std::string;

class Player
{

public:
    Player() { std::cout << "--- New Player --- " << std::endl; };
   
    string GetPlayerName();
    void SetPlayerName();
private:
    string player_name;
 
};
#endif