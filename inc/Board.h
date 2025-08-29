#pragma once

#include <iostream>
#include <string>
#include <vector>

class Board {
public:
    Board(int rows, int cols);

    int rows = 6;
    int cols = 7;

    std::vector<std::vector<char>> gameBoard;
    std::vector<char> boarder;

    std::vector<std::vector<char>> displayBoard;

    void drawBoard();

    void makeMove(int col, char player);

private:

    void isValidMove();

    void checkWinner();
    
    void isBoardFull();

};