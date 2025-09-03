#include "../inc/Board.h"

// Constructor
Board::Board() :
    gameBoard(rows, std::vector<char>(cols, ' ')),
    boarder(cols, '|')
{
    std::cout << "Board constructed" << std::endl;

}

void Board::drawBoard()
{
    // build displayBoard fresh each time
    displayBoard.assign(rows + 2, std::vector<char>(cols + 2, ' '));

    // Top and bottom border
    for (int c = 0; c < cols + 2; ++c) 
    {
        displayBoard[0][c]        = '-';   // top
        displayBoard[rows + 1][c] = '-';   // bottom
    }

    // Left and right borders
    for (int r = 0; r < rows + 2; ++r) 
    {
        displayBoard[r][0]        = '|';   // left
        displayBoard[r][cols + 1] = '|';   // right
    }

    // Copy logical game board into the center
    for (int r = 0; r < rows; ++r) 
    {
        for (int c = 0; c < cols; ++c) {
            displayBoard[r + 1][c + 1] = gameBoard[r][c];
        }
    }

    // Print offset for column headers
    std::cout << "  ";
    // Print column headers
    for (int c = 1; c <= cols; ++c) {
        std::cout << ' ' << c;
    }
    std::cout << "\n";

    // Print display board
    for (int r = 0; r < rows + 2; ++r) {
        for (int c = 0; c < cols + 2; ++c) {
            std::cout << ' ' << displayBoard[r][c];
        }
        std::cout << '\n';
    }
}


void Board::makeMove(int col, char player)
{
    int r = rows-1;
    while(gameBoard[r][col] != ' ')
    {
        r--;
    }
    gameBoard[r][col] = player;
}


bool Board::isValidMove(int col)
{
    bool isValidMove = false;

    if (gameBoard[0][col] == ' ')
    {
        isValidMove = true;
    }

    return isValidMove;
}

void Board::checkWinner()
{
}

bool Board::isBoardFull()
{
    for(int col = 0; col <= cols-1; col++)
    {
        if (gameBoard[0][col] == ' ')
        {
            return false;
        }
    }
    return true;
}
