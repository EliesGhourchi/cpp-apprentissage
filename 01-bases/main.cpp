#include <iostream>
#include <string>
#include <limits>

int main() {
    std::string playerName;
    std::cout << "UserName : " ;
    std::getline(std::cin, playerName);
    
    int playerLevel = 0;
    std::cout << "Level :";
    std::cin >> playerLevel;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string playerClass;
    std::cout << "Class : ";
    std::getline(std::cin, playerClass);

    std::cout << "Welcome: " << playerName << ", your class is: " << playerClass 
    << ", level: " << playerLevel << "\n";

    return 0;
}