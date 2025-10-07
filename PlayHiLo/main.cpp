#include "playHiLo.cpp"

#include <iostream>
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

    if (n == 1)
        hiloGame(n);
    else
        return 0;