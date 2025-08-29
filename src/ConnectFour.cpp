#include "../inc/ConnectFour.h"
#include "../inc/Board.h"

// Constructor
ConnectFour::ConnectFour(int mode) :
    gameMode(mode),
    gameBoard()
{
    playerChar = getPlayerChoice();
    std::cout << "Game constructed" << std::endl;
    play();
}

char ConnectFour::getPlayerChoice()
{
    std::string input;
    while (true) 
    {
        std::cout << "Choose your piece (x/o): ";
        std::cin >> input;
        if (input == "x" || input == "X") 
        {
            return 'X';
        }
        else if (input == "o" || input == "O") 
        {
            return 'O';
        }
        else 
        {
            std::cout << "Invalid choice. Please enter 'x' or 'o'.\n";
        }
    }
}

int ConnectFour::getUserMove(int cols) 
{
    int col;
    while (true)
    {
        std::cout << "Enter a column (1-" << cols << "): ";
        if (std::cin >> col) 
        {
            if (col >= 1 && col <= cols && gameBoard.isValidMove(col))
            {
                return col - 1; // zero-based index
            }
            else 
            {
                std::cout << "Invalid column. Try again.\n";
            }
        }
        else 
        {
            // bad input (like a letter), clear and retry
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number.\n";
        }
    }
}

void ConnectFour::getValidPlayerMove()
{
    int usersMove = getUserMove(gameBoard.cols);
    gameBoard.makeMove(usersMove, playerChar);
}

void ConnectFour::computerMove()
{
}

void ConnectFour::playTurn()
{
}

// main game loop - calls play until winner is found
void ConnectFour::play()
{
    while(!finished)
    {
        gameBoard.drawBoard();
        getValidPlayerMove();
        gameBoard.drawBoard();
        computerMove();
    }
}

void ConnectFour::displayWinner()
{
}