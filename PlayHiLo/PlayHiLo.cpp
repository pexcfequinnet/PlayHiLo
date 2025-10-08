#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <limits>
#include <random>


void hiloGame(int minVal, int maxVal, int maxAttempt)
{
    char again{};
    do {


        // Random number generator
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(minVal, maxVal);

        int answer = dist(gen);

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
                system("cls");
                std::cout << "I will pick a number from " << minVal << " to " << maxVal
                    << ", you will have " << maxAttempt << " attempts to guess that number." << '\n';
                std::cout << "Invalid input.\nGuess the number: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

            if (guess == answer)
            {
                system("cls");
                std::cout << "Correct answer! You won." << '\n';
                break;
            }

            else if (guess > answer)
            {
                system("cls");
                std::cout << "I will pick a number from " << minVal << " to " << maxVal
                    << ", you will have " << maxAttempt << " attempts to guess that number." << '\n';
                std::cout << "Wrong answer. The number you guessed is too high." << '\n'
                    << "You have " << maxAttempt - i << " attempt(s) left.";
                if (i != maxAttempt)
                    std::cout << "\nGuess the number: ";
            }


            else
            {
                system("cls");
                std::cout << "I will pick a number from " << minVal << " to " << maxVal
                    << ", you will have " << maxAttempt << " attempts to guess that number." << '\n';
                std::cout << "Wrong answer. The number you guessed is too low." << '\n'
                    << "You have " << maxAttempt - i << " attempt(s) left.";
                if (i != maxAttempt)
                    std::cout << "\nGuess the number: ";
            }


            if (i == maxAttempt)
            {
                system("cls");
                std::cout << "You lost. The correct number is " << answer << '\n';
            }
        }
        std::cout << "Do you want to play again? (y / n): ";

        do {
            std::cin >> again;
            if (again != 'Y' && again != 'N' && again != 'y' && again != 'n')
                std::cout << "Invalid input. Please enter y or n: " << '\n';

        } while (again != 'Y' && again != 'y' && again != 'N' && again != 'n');

    } while (again == 'Y' || again == 'y');
    system("cls");
    std::cout << "Thanks for playing!\n";
}