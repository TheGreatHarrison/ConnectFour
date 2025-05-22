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
    char player1 = 'X';
    char player2 = 'O';
    //Board board; // to be implmented
    int gameMode = 0;

    // Private member functions (optional)
    void switchPlayer();
    void getValidMove();
    void playTurn();
    void computerMove();

    // main game loop - calls playTurn untill winner is cound
    void play();

    void displayWinner();

};