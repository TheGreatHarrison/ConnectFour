#pragma once

#include <iostream>
#include <string>
#include <vector>

class Board {
public:
    Board(int rows, int cols);

    int rows = 6;
    int cols = 7;

    std::vector<char> boarder;
    std::vector<std::vector<char>> gameBoard;

    std::vector<std::vector<char>> fullBoard;

    void displayBoard();

    void makeMove(int col, char player);

private:

    void isValidMove();

    void checkWinner();
    
    void isBoardFull();

};