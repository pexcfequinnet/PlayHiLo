#include "configmenu.h"
#include "mainmenu.h"

#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <thread>
int choice{}, minVal{ 1 }, maxVal{ 100 }, maxAttempts{ 10 };

void menuHelper(int signal)
{
	if (signal == 0)
		mainMenu(0, minVal, maxVal, maxAttempts);
	if (signal == 1)
		gameConfigMainMenu();
	if (signal == 2)
		valueConfigMenu();
	if (signal == 3)
		maxGuessesConfigMenu();


}
void gameConfigMainMenu()
{
	system("cls");
	// Config menu
	std::cout << "Game configuration:" << '\n'
		<< "1: Change number range." << '\n'
		<< "2: Change max guess attempt." << '\n'
		<< "3: Exit to main menu. " << '\n'
		<< "Enter a number: ";
	
	int choice{};
	std::cin >> choice;
	
	while ((!std::cin >> choice) || choice < 1 || choice > 3)
	{
		std::cout << "Invalid input." << '\n' << "Enter a number: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	if (choice == 1)
		menuHelper(2);
	if (choice == 2)
		menuHelper(3);
	if (choice == 3) // Exit to main menu
		menuHelper(0);
}


// Config: Change number range
void valueConfigMenu()
{
	using namespace std::this_thread;
	using namespace std::chrono_literals;
	using std::chrono::system_clock;

	system("cls");
	std::cout << "Change number range (currently " << minVal << '-' << maxVal << "): " << '\n'
		<< "1. Mimimum value" << '\n'
		<< "2. Maximum value" << '\n'
		<< "3. Exit to config menu." << '\n'
		<< "Enter a number: ";

	int valChoice{};
	while (!(std::cin >> valChoice) || valChoice < 1 || valChoice > 3)
	{
		std::cout << "Invalid input." << '\n' << "Enter a number: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	// Change number range: Minimum value
	if (valChoice == 1)
	{
		system("cls");
		std::cout << "Enter minimum value (currently " << minVal << "): ";
		while (!(std::cin >> minVal) || minVal > maxVal)
		{
			std::cout << "Invalid input." << ' ';
			if (minVal > maxVal)
				std::cout << "Minimum value has to be smaller than maximum value." << '\n'
				<< "Enter a number: ";
			else
				std::cout << '\n' << "Enter a number: ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		std::cout << "Minimum value is now set to " << minVal;
		sleep_for(1.5s);
		menuHelper(2); // Return to value config menu
	}
	// Change number range: Maximum value

	if (valChoice == 2)
	{
		system("cls");
		std::cout << "Enter maximum value (currently " << maxVal << "): ";
		while (!(std::cin >> maxVal) || maxVal < minVal)
		{
			std::cout << "Invalid input." << ' ';
			if (maxVal < minVal)
				std::cout << "Minimum value has to be bigger than maximum value." << '\n'
				<< "Enter a number: ";
			else
				std::cout << '\n' << "Enter a number: ";

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		std::cout << "Maximum value is now set to " << maxVal;
		sleep_for(1.5s);
		valueConfigMenu(); // Return to value config menu
	}

	if (valChoice == 3)
		menuHelper(0); // Return to main menu
}

// Config: Change amount of guesses
void maxGuessesConfigMenu()
{
	using namespace std::this_thread;
	using namespace std::chrono_literals;
	using std::chrono::system_clock;

	std::cout << "Change max amount of guesses (currently " << maxAttempts << "): ";
	while (!(std::cin >> maxAttempts))
	{
		std::cout << "Invalid input.";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	std::cout << "Max guess(es) is now: " << maxAttempts;
	sleep_for(1.5s);
	menuHelper(1); // Exit to config menu
}
	