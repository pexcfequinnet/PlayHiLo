#include <iostream>
#include <stdlib.h>
#include <time.h>
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

            
        if (guess == answer)
        {
            std::cout << "Correct answer! You won.";
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

    
    int n{};

    do {
        std::cout << "Welcome to the Hi-Lo game, enter 1 to continue: ";
        std::cin >> n;
        if (n != 1)
            std::cout << "Invalid input.\n";
    } while (n != 1);

    hiloGame(n);
    return 0;
}
