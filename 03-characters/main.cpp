#include <iostream>
#include <string>
#include <vector>
enum class Element { Fire, Wind, Water, Earth, None };

struct Character  {
    std::string name = "noname";
    int maxHp = 100;
    int hp = maxHp;
    int actionPoints = 6;
    int movePoints = 3;
    Element element = Element::None;
};

std::string elementName(Element element){
    switch (element)
    {
        case Element::Fire:  return "Fire";
        case Element::Wind:  return "Wind";
        case Element::Earth:  return "Earth";
        case Element::Water:  return "Water";
        case Element::None:  return "None";
    }
    return"";
}

void showInvoc(const Character& x){
    std::cout<< x.name << " | " << x.maxHp << " | " << x.hp << " | " << x.actionPoints << " | " << x.movePoints << " | " << elementName(x.element) <<"\n";
}

void showTeam(const std::vector<Character>& team, const std::string& teamName){
    std::cout << teamName << "\n";
    std::cout<< "Name | Max HP | HP | AP | MP | Element\n";
    for (const Character& n : team){
        showInvoc(n);
    }

}

int main(){
    
    //equipe A
    Character rocfort{"Rocfort",200,200,6,1,Element::Earth};
    Character samu_Rai{"Samu-Rai",70,70,9,4,Element::Wind};
    std::vector<Character> teamA = {rocfort, samu_Rai};
    //equipe B
    Character judeau{"Judeau",160,160,8,2,Element::Water};
    Character feubuleux{"Feubuleux",80,80,8,3,Element::Fire};
    std::vector<Character> teamB = {judeau, feubuleux};

    
    showTeam(teamA,"team A");

    showTeam(teamB,"team B");


    

    return 0;
}