#include <vector>
#include <iostream>
#include <string>
#include <limits>

int readNumberBetween(int min, int max){
    int playerValue = min-1;
    while (true)
    {
        std::cout << "Choose a number between : " << min << " and " << max << "\n"; 
        std::cin >> playerValue;
        bool readFailed = std::cin.fail();

        if(readFailed)
        {
            std::cin.clear();
            
        }
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if(readFailed)
        {
            
            std::cout<< "Not a number \n";
        }

        else if( playerValue < min )
        {
            std::cout << "Minimum is : " << min << "\n";
        }
        else if (playerValue > max)
        {
            std::cout << "Maximum is : " << max << "\n";
        }
        else
        {
            return playerValue;
        }

    }
    
}
void addItem(std::vector<std::string>& items){
    std::string objectName;
    std::cout << "Choose an Item to add\n";
    std::getline(std::cin, objectName);
    if(objectName.empty()){
        std::cout << "Empty not accepted\n";
        return;
    }
    std::cout << "Added: " << objectName << "\n";
    items.push_back(objectName);
}

void showInventory(const std::vector<std::string>& items){
    std::cout << "Inventory (" << items.size() << " items):\n"; 
    for (std::size_t i = 0; i < items.size(); ++i) {
            std::cout << i+1 << ". " << items[i] << '\n';
    }

}

void removeItem(std::vector<std::string>& items){
    if(items.empty()){
        std::cout << "Inventory is empty\n";
        return;
    }
    showInventory(items);
    std::cout << "Choose item to delete : ";
    
    int itemNumber = readNumberBetween(1, items.size()) -1;
    std::cout << "Removed: " << items[itemNumber] << "\n";
    items.erase(items.begin() + itemNumber);

}

int main() {
    std::vector<std::string> items = {"Sword","Healing potion","Rope"};
    std::vector<std::string> menu = {"Add an item","Show inventory","Remove an item","Quit"};
    items.push_back("Torch");

    unsigned menuChoice = 0;
    showInventory(items);

    // show menu
    while (true)
    {
        std::cout << "\n -- MENU -- \n";
        for (std::size_t i = 0; i < menu.size(); ++i) {
            std::cout << i+1 << ". " << menu[i] << '\n';
        }

        menuChoice = readNumberBetween(1,menu.size());

        if(menuChoice == menu.size()){
            std::cout << "bye!";
            break;
        }
        else if (menuChoice == 1)
        {
            addItem(items);
        }
        else if (menuChoice == 2)
        {
            showInventory(items);
        }
        else if (menuChoice == 3)
        {
            removeItem(items);
        }
        else{
            std::cout << "Not implemented yet \n";
        }
    }
    

    return 0;
}
