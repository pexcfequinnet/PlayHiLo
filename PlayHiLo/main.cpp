#include "mainmenu.h"

#include <iostream>
#include <chrono>
#include <thread>
void mainMenu(int choice, int minVal, int maxVal, int maxAttempts)
{
    system("cls");
    // Main menu
    std::cout << "Welcome to the Hi-Lo game.\n"
        << "1: Play\n" << "2: Config.\n" << "3: Quit.\n";
    std::cout << "Enter a number to continue: ";

    while (!(std::cin >> choice) || choice < 1 || choice > 3)
    {
        using namespace std::this_thread;
        using namespace std::chrono_literals;
        using std::chrono::system_clock;
        system("cls");
        std::cout << "Invalid input.";
        sleep_for(0.75s);

        system("cls");
        // Main menu
        std::cout << "Welcome to the Hi-Lo game.\n"
            << "1: Play\n" << "2: Config.\n" << "3: Quit.\n";

        std::cout << "Enter a number to continue: ";

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    if (choice == 1)
        hiloGame(minVal, maxVal, maxAttempts);
    else if (choice == 2)
        gameConfigMainMenu();
    else
        exit(0);
}
int main()
{
	int minVal{1}, maxVal{100}, maxAttempts{10};
    mainMenu(0, minVal, maxVal, maxAttempts);
    return 0;
}