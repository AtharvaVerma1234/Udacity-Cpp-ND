#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "additional_feature.h"
#include "player_info.h"
#include "game_menu.h"
#include <memory>
#include <chrono>
#include "snake.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};
//Stats from additional features
  AdditionalFeature platform;
  platform.printOS();
  
  bool start_game;
  start_game=false;
  int total_head_distance=0;
  int total_score=0;
  Snake snake1;
  //infinite while loop to get a valid entry from user
  while (start_game == false)
    {
      GameMenu gm;

      if (gm.quit_game_flag == true)
      {
        return 0;
      }
	//to break out of while loop
      start_game = gm.InitMenu();
    }
    
  std::unique_ptr<Player> player=std::make_unique<Player>();
  player->SetPlayerName();
  int lives_remaining=3;
  snake1.SetStartSpeed();
  std::cout<<"Game Begins"<<std::endl;
  auto start=std::chrono::high_resolution_clock::now();
  
  while(lives_remaining>0)
  {
  Game game(kGridWidth, kGridHeight);

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  
  game.Run(controller, renderer, kMsPerFrame);
    --lives_remaining;
    total_head_distance+=snake1.GetHeadDistance();
    total_score+=game.GetScore();
    std::cout<<"Snake size reached :"<<game.GetSize()<<std::endl;
    std::cout<<"Head Distance Travelled : "<<snake1.GetHeadDistance()<<std::endl;
  std::cout << "Lives Remaining : "<<lives_remaining<<std::endl;;
 
  }
  auto end=std::chrono::high_resolution_clock::now();
  auto duration=std::chrono::duration_cast<std::chrono::seconds>(end - start);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "-----------------------------------" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
  std::cout<<"Player Name: "<<player->GetPlayerName()<<std::endl;
  std::cout<<"Score : "<<total_score<<std::endl;
  std::cout<<"Snake Total Head Travel : "<<total_head_distance<<std::endl;
  std::cout<<"Total Play Time : "<<duration.count()<<std::endl;
  return 0;
}