#include "../inc/ConnectFour.h"
#include "../inc/Board.h"
#include <random>

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
        std::cout << "Choose your piece (X/O): ";
        std::cin >> input;
        if (input == "x" || input == "X") 
        {
            pcChar = 'O';
            return 'X';
        }
        else if (input == "o" || input == "O") 
        {
            pcChar = 'X';
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
            if (col >= 1 && col <= cols && gameBoard.isValidMove(col-1))
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

void ConnectFour::playerMove()
{
    int usersMove = getUserMove(gameBoard.cols);
    gameBoard.makeMove(usersMove, playerChar);
}

void ConnectFour::computerMove()
{
        // Create a random device and generator
    std::random_device rd;
    std::mt19937 gen(rd()); // Mersenne Twister RNG
    std::uniform_int_distribution<> dist(0, 6); // Range 1 to 7
    int randomMove = dist(gen);

    while(!gameBoard.isValidMove(randomMove))
    {
        randomMove = dist(gen);
    }

    gameBoard.makeMove(randomMove, pcChar);
}

void ConnectFour::playTurn()
{
    gameBoard.drawBoard();
    playerMove();
    computerMove();
}

// main game loop - calls play until winner is found
void ConnectFour::play()
{
    GameResult result = GameResult::PlayerWon;

    while(!finished && !gameBoard.isBoardFull())
    {
        playTurn();
    }

    displayWinner(result);
}

void ConnectFour::displayWinner(GameResult res)
{
    gameBoard.drawBoard();
    
    switch (res) 
    {
        case GameResult::PlayerWon:
            std::cout << "You Won!!!" << std::endl;
            break;
        case GameResult::PcWon:
            std::cout << "You Lost!!!" << std::endl;
            break;
        case GameResult::Draw:
            std::cout << "It's a draw!" << std::endl;
            break;
    }
}