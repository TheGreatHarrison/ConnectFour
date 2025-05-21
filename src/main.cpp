#include <iostream>
#include <string>
#include <vector>

#include "../inc/Game.h"

#define ROWS 6;
#define COLS 7;

int main() {
    // Your program's entry point starts here.

    std::cout << "Hello, C++ World!" << std::endl;

    // You can create instances of your classes here:
    // YourClass myObject;
    // Game myGame(1); // Assuming your Game constructor takes an integer

    // Perform operations with your objects:
    // myObject.somePublicMethod();
    // myGame.play();

    // You can also use standard library components:
    std::string message = "This is a string.";
    std::cout << message << std::endl;

    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::cout << "Numbers in the vector: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // The main function should return an integer to indicate the program's exit status.
    // A return value of 0 typically indicates successful execution.
    return 0;
}