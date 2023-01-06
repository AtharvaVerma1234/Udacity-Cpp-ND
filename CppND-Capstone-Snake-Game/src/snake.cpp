#include "snake.h"
#include <cmath>
#include <iostream>
#include <string>
Snake::Snake()
{}
void Snake::SetStartSpeed(float f)
{
  speed =f;
}
void Snake::SetStartSpeed()
{
  float uSpeed;
  char bufferRange[25];
  char ans_user[25];
  sprintf(bufferRange, "%0.1f and %0.1f", startSpeed_min, startSpeed_max);
  std::string Str(bufferRange);

  std::cout << "Enter a starting speed of snake before playing the game" << std::endl;
  std::cout << "Select a number between " << Str << std::endl;

  while (true)
  {
    int isNum = scanf("%f", &uSpeed);
    if (isNum)
    {
      if (uSpeed >= startSpeed_min && uSpeed <= startSpeed_max)
      {
        speed = uSpeed;
        return;
      }
    }
    std::cerr << "\n\n\nOoops!! Please provide a valid decimal between " << Str << std::endl;
  };
}

void Snake::Update() {
  SDL_Point prev_cell{
      static_cast<int>(head_x),
      static_cast<int>(
          head_y)};  // We first capture the head's cell before updating.
  UpdateHead();
  SDL_Point current_cell{
      static_cast<int>(head_x),
      static_cast<int>(head_y)};  // Capture the head's cell after updating.

  // Update all of the body vector items if the snake head has moved to a new
  // cell.
  if (current_cell.x != prev_cell.x || current_cell.y != prev_cell.y) {
    UpdateBody(current_cell, prev_cell);
  }
}

float Snake::head_distance=0;
void Snake::UpdateHead() {
  switch (direction) {
    case Direction::kUp:
      head_y -= speed;
      break;

    case Direction::kDown:
      head_y += speed;
      break;

    case Direction::kLeft:
      head_x -= speed;
      break;

    case Direction::kRight:
      head_x += speed;
      break;
  }

  // Wrap the Snake around to the beginning if going off of the screen.
  head_x = fmod(head_x + grid_width, grid_width);
  head_y = fmod(head_y + grid_height, grid_height);
  HeadDistanceTravel(head_distance, head_x, head_y, x_prev, y_prev);
}
void Snake::HeadDistanceTravel(float &h_tot_dist, float h_x, float head_y, float &x_prev, float &y_prev)
{

  h_tot_dist = h_tot_dist + abs(head_x - x_prev) + abs(head_y - y_prev);
  x_prev = head_x;
  y_prev = head_y;
}
float Snake::GetHeadDistance()
{
  return head_distance;
}


void Snake::UpdateBody(SDL_Point &current_head_cell, SDL_Point &prev_head_cell) {
  // Add previous head location to vector
  body.push_back(prev_head_cell);

  if (!growing) {
    // Remove the tail from the vector.
    body.erase(body.begin());
  } else {
    growing = false;
    size++;
  }

  // Check if the snake has died.
  for (auto const &item : body) {
    if (current_head_cell.x == item.x && current_head_cell.y == item.y) {
      alive = false;
    }
  }
}

void Snake::GrowBody() { growing = true; }

// Inefficient method to check if cell is occupied by snake.
bool Snake::SnakeCell(int x, int y) {
  if (x == static_cast<int>(head_x) && y == static_cast<int>(head_y)) {
    return true;
  }
  for (auto const &item : body) {
    if (x == item.x && y == item.y) {
      return true;
    }
  }
  return false;
}