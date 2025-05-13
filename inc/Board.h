#pragma once

#include <iostream>
#include <string>
#include <vector>

class Board {
public:
    Board(int rows, int cols);

    int rows;
    int cols;
    std::vector<std::vector<char>> board;


    void displayBoard();

    void makeMove(int col, char player);

private:

    void isValidMove();

    void checkWinner();
    
    void isBoardFull();

};