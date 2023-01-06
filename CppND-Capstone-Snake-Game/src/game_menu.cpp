#include "game_menu.h"

#include <iostream>



bool GameMenu::quit_game_flag = false;

bool GameMenu::InitMenu()
{

    std::cout << " ### WELCOME TO SNAKE GAME ###" << std::endl;
    std::cout << "   " << std::endl;
    std::cout << " 1. Start New Game" << std::endl;
   
    std::cout << " 2. QUIT" << std::endl;
    std::cout << "your choice --> ";

    int key_pressed;

    while (!(std::cin >> key_pressed))
    {

        std::cin.clear();

        while (std::cin.get() != '\n')
            continue;

        // Ask user to try again:
        std::cout << "FAILED. Only number is allowed. Please enter correct number -->  ";
    }
    if ((key_pressed < 1) || (key_pressed > 2))
    {
        std::cout << "you pressed : " << key_pressed << std::endl;
        std::cout << "FAILED. Please enter correct number!"
                  << "\n\n";
        return false;
    }

    switch (key_pressed)
    {

    case 1:
    {
        return true;
    };
    break;

    
    case 2:
    {
        std::cout << "quiting the game ... Thanks" << std::endl;
        quit_game_flag = true;
    };

        return false;
    }
}



