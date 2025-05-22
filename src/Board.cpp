#include "../inc/Board.h"

// Constructor
Board::Board(int rows, int cols) :
    rows(rows),
    cols(cols),
    gameBoard(rows, std::vector<char>(cols, ' ')),
    boarder(cols, '|')
{
    std::cout << "Board constructed" << std::endl;

}

void Board::displayBoard()
{
    for(int i=1; i < cols+1; i++)
    {
        std::cout << " " << i;
    }

    for (int i=0; i < cols; i++)
    {
        for (int j=0; j < rows; j++)
        {
            std::cout << " " << fullBoard[j][i];
        }
    }
}

void Board::makeMove(int col, char player)
{
}

void Board::isValidMove()
{
}

void Board::checkWinner()
{
}

void Board::isBoardFull()
{
}
