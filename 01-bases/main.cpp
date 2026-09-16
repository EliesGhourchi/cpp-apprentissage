#include <iostream>
#include <string>
#include <limits>

int main() {
    std::string playerName;
    std::cout << "UserName: " ;
    std::getline(std::cin, playerName);
    
    int playerLevel = 0;
    while(playerLevel <= 0 || playerLevel > 20)
    {
        std::cout << "Level:";
        std::cin >> playerLevel;

        if(std::cin.fail())
        {
            std::cin.clear();
            std::cout << "Not a number\n";
        }
        else if(playerLevel < 0)
        {
            std::cout << "Negative value not accepted\n";
        }
        else if(playerLevel > 20)
        {
            std::cout << "Max level is 20\n";
        }
        else if(playerLevel == 0)
        {
            std::cout << "Level 0 not accepted\n";
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    
    std::string playerClass;
    std::cout << "Class: ";
    std::getline(std::cin, playerClass);

    std::cout << "Welcome: " << playerName << ", your class is: " << playerClass << ", level: " << playerLevel << "\n";

    return 0;
}