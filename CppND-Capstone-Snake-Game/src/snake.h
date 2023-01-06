#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "SDL.h"

class Snake {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };
	Snake();
  Snake(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height),
        head_x(grid_width / 2),
        head_y(grid_height / 2),
  		x_prev(grid_width / 2),
        y_prev(grid_height / 2){}

  void Update();
  /* 
  First ask the user for a starting speed of the snake.
  Validate user's input and save the speed.
  */
  void SetStartSpeed();
  void SetStartSpeed(float f);
  void GrowBody();
  bool SnakeCell(int x, int y);
   void HeadDistanceTravel(float &h_tot_dist, float h_x, float head_y, float &x_prev, float &y_prev);
float GetHeadDistance();
  Direction direction = Direction::kUp;

  float speed=0.1f;
  int size=1;
  bool alive=true;
  float head_x;
  float head_y;
  float x_prev;
  float y_prev;
  std::vector<SDL_Point> body;

 private:
  void UpdateHead();
  void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell);

  bool growing{false};
  int grid_width;
  int grid_height;
  float startSpeed_min=0.1;
  float startSpeed_max=0.6;
  static float head_distance;
};

#endif