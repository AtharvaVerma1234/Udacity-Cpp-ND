#include "player_info.h"
#include <iostream>
#include <string>

using std::string;


void Player::SetPlayerName()
{
  string s;
  std::cout<<"Enter a name "<<std::endl;
  std::cin>>s;
  player_name=s;
}

string Player::GetPlayerName(){

    return player_name;
}








