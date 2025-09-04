#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "../inc/Board.h"

// ConnectFour will handle the game loop.
class ConnectFour {
public:
    ConnectFour(int mode);

private:
    int gameMode = 0;
    Board gameBoard;
    
    char playerChar;
    char pcChar;

    bool finished = false;

    enum class GameResult
    {
        PlayerWon,
        PcWon,
        Draw
    };

    // Private member functions

    // Prompts user for a char to use x/o for now.
    // ToDo allow user to pick any char.
    char getPlayerChoice();

    // Prompt the user for their game input. This function will make sure it is a valid input.
    // If user input is invalid it will keep prompting for a valid input.
    int getUserMove(int cols);

    // Gets the move from the respective place and adds it to the board. 
    void playerMove();
    void computerMove();

    // One game "loop"
    // Will draw the board and one round of turns.
    void playTurn();


    // main game loop - calls playTurn untill winner is cound
    void play();

    // Will display the outcome of the game.
    void displayWinner(GameResult res);
};
