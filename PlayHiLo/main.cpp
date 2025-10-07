#include "mainheader.h"

#include <iostream>

int main()
{
	int choice{}, minVal{1}, maxVal{100}, maxAttempt{10};

    std::cout << "Welcome to the Hi-Lo game.\n"
        << "1: Play\n" << "2: Config.\n" << "3: Quit.\n";

    std::cout << "Enter a number to continue: ";

    while (!(std::cin >> choice) || choice < 0 || choice > 3)
    {
        std::cout << "Invalid input." << '\n' << "Enter a number to continue: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    if (choice == 1)
        hiloGame(minVal, maxVal, maxAttempt);
    else if (choice == 2)
        gameConfig(minVal, maxVal, maxAttempt);
		return 0;
}