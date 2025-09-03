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
    char getPlayerChoice();
    int getUserMove(int cols);
    void playerMove();
    void playTurn();
    void computerMove();

    // main game loop - calls playTurn untill winner is cound
    void play();

    void displayWinner(GameResult res);
};
