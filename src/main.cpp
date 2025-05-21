#include <iostream>
#include <string>
#include <vector>

#include "../inc/Game.h"
#include "../inc/Board.h"

constexpr int ROWS = 6;
constexpr int COLS = 7;

int main() {
    // Your program's entry point starts here.

    std::cout << "Connect Four!" << std::endl;
    Board board1(ROWS, COLS);
    board1.displayBoard();
    return 0;
}