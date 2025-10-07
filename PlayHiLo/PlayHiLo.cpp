#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <limits>
static void hiloGame(int n)
{
    int maxAttempt{ 20 };
    srand(time(NULL));
    int answer{ rand() % 1001 };
    std::cout << "I will pick a number from 0 to 1000, you will have " << maxAttempt << " attempts to guess that number." << '\n';
    std::cout << "Guess the number: ";
    

    for (int i{ 1 }; i <= maxAttempt; ++i)
    {
        int guess{};
        std::cin >> guess;

        while (std::cin >> guess)
        {
            std::cout << "Invalid input.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        }
            
        if (guess == answer)
        {
            std::cout << "Correct answer! You won." << '\n';
            break;
        }

        else if (guess > answer)
        {
            std::cout << "Wrong answer. The number you guessed is too high." << '\n'
            << "You have " << maxAttempt - i << " attempt(s) left.";
            if (i != maxAttempt)
                std::cout << "\nGuess the number: ";
        }


        else
        {
            std::cout << "Wrong answer. The number you guessed is too low." << '\n'
                << "You have " << maxAttempt - i << " attempt(s) left.";
            if (i != maxAttempt)
                std::cout << "\nGuess the number: ";
        }


        if (i == maxAttempt)
        {
            std::cout << "\nYou lost. The correct answer is " << answer;
        }
    }
}

int main()
{

    std::cout << "Welcome to the Hi-Lo game, enter 1 to continue, enter 0 to exit: ";
    int n{};

    while (!(std::cin >> n) || n < 0 || n > 2)
    {
        std::cout << "Invalid input.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    
    if(n == 1)
        hiloGame(n);
    else
        return 0;
}
