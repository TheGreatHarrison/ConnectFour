#include "Game.h"

// Constructor
Game::Game(int mode) :
    gameMode(mode)
{
    std::cout << "Game constructed" << std::endl;
}

// Private member functions (optional)
void Game::switchPlayer()
{
}

void Game::getValidMove()
{
}

void Game::playTurn()
{
}

void Game::computerMove()
{
}

// main game loop - calls playTurn until winner is found
void Game::play()
{
}

void Game::displayWinner()
{
}