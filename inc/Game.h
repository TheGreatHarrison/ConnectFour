// YourClass.h

#ifndef Game
#define Game

#include <iostream>
#include <string>
#include <vector>


class Game {
public:
    Game();
    ~Game();


private:
    int currentPlayer;
    char player1;
    char player2;
    Board board; // to be implmented
    int gameMode;


    // Private member functions (optional)
    void switchPlayer();
    void getValidMove();
    void playTurn();
    void computerMove();

    // main game loop - calls playTurn untill winner is cound
    void play();

    void displayWinner();

};

#endif // YOUR_CLASS_H