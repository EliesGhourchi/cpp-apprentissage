#include <string>
#include <iostream>
#include <vector>
#include "character.h"
#include "display.h"

// l'affichage

void showInvoc(const Character& x){
    std::cout<< x.name << " | " << x.maxHp << " | " << x.hp << " | " << x.actionPoints << " | " << x.movePoints << " | " << elementName(x.element) << " | " << x.Pow << "\n";
}

void showTeam(const std::vector<Character>& team, const std::string& teamName){
    std::cout << teamName << "\n";
    std::cout<< "Name | Max HP | HP | AP | MP | Element | Puissance\n";
    for (const Character& n : team){
        showInvoc(n);
    }

}
