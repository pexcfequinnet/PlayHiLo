#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <limits>



int hiloGame(int minVal, int maxVal, int maxAttempt)
{
    // Random number generator
    srand(time(NULL));
    int answer{ minVal + rand() % maxVal + 1 };

    // Core game
    system("cls");
    std::cout << "I will pick a number from " << minVal << " to " << maxVal
        << ", you will have " << maxAttempt << " attempts to guess that number." << '\n';

    std::cout << "Guess the number: ";

    // Game mechanic
    for (int i{ 1 }; i <= maxAttempt; ++i)
    {
        int guess{};

        while (!(std::cin >> guess))
        {
            std::cout << "Invalid input.\nGuess the number: ";
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
            std::cout << "You lost. The correct number is " << answer << '\n';
            std::cout << "Do you want to play again? (y / n): ";
            char again{};
            do {
                std::cin >> again;
                if (again != 'Y' && again != 'N' && again != 'y' && again != 'n')
                    std::cout << "Invalid input.";
            } while (again != 'Y' && again != 'N' && again != 'y' && again != 'n');

            if (again == 'Y' || again == 'y')
                return 1;
            return 0;
        }
    }
}