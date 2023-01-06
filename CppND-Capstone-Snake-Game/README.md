# CPPND: Capstone Snake

This was a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

This C++ project is the fifth and final project of the Udacity C++ Nanodegree.
The starter code is loacted at [https://github.com/udacity/CppND-Capstone-Snake-Game.git].

The code is divided into four different components i.e 
-> Renderer component is responsible for rendering the state of the game using the popular [SDL library](https://www.libsdl.org/)

-> Game component constructs and maintains the game board and placement of the game elements like the snake and food.

-> Snake component constructs and maintains the snake object as it moves across the board gaining points and checking if it ran into itself.

-> Controller component receives input from the user in order to control movement of the snake.
Upon launching the game, the user is first greeted with the system platform detected.
Then a main menu is displayed which asks whether the user wants to play the game or not.

The user then enters a name and a valid starting speed of snake and then is able to play the game.
The user is by default given 3 lives and the final score is calculated by adding scores of all 3 lives.
At end the player details, score, distance travelled by snake, and play time are displayed.
## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.

######RUBRICS


1-> `Object Oriented Programming - The project uses Object Oriented Programming techniques.`

To meet this requirement, a ` class was created (inside `additional_feature.h`) to hold information about the Operating System. The class uses the member functions `getOS` and `printOS` to fetch and print the Operating System in which the game is currently running.


2-> `Object Oriented Programming - Classes use appropriate access specifiers for class members.`

Within `additional_feature.h`, the private variable `OSUsed` (line 23) is used to store the user's Operating system. No other class can access this variable.


3-> `Object Oriented Programming - Class constructors utilize member initialization lists.`

Within `additional_feature.h` (line 11) the default argument for the private variable `OSUsed` is a null string which is set within the class's initiaziation list.

4->  `Object Oriented Programming - Classes abstract implementation details from their interfaces.`

The name of the functions and comments describe the working of the member functions - (Line 14 in additional_feature.h)

The member functions getOS() and printOS() are abstracted as they are defined in a separate file 'additional_feature.cpp'.
The main function just calls the printOS() function without knowing the working of the function itself.

5-> Loops, Functions, I/O - The project accepts user input and processes the input.
A game menu has been created using 'game_menu.cpp' which asks whether the player wants to play or quit.
User details are taken input using a smart pointer to player class using 'player_info.cpp'.

The user selects the starting speed of the snake. A Snake class member function `SetStartSpeed` (main.cpp line 44) is called.
 asks the user for a starting speed within the pre-defined range. The function then proceeds to validate the user's input and assign it to the private member `speed`.
 A infinite while loop is implemented to take a valid answer from user whether he wants to play or not in 'main.cpp'.
 A while loop is implemented for generating 3 lives of the player in 'main.cpp'.
 
## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
