#pragma once

#include <iostream>
#include <string>
#include <vector>

class Board {
public:
    Board();

    int rows = 6;
    int cols = 7;

    void drawBoard();

    void makeMove(int col, char player);
    bool isValidMove(int col);

private:

    std::vector<std::vector<char>> gameBoard;
    std::vector<char> boarder;
    std::vector<std::vector<char>> displayBoard;

    void checkWinner();
    
    void isBoardFull();

};