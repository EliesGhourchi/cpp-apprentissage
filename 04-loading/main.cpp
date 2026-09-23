#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

enum class Element { Fire, Wind, Water, Earth, None };

struct Character  {
    std::string name = "noname"; //0
    int maxHp = 100; //1
    int hp = maxHp; //2
    int actionPoints = 6; //3
    int movePoints = 3; //4
    Element element = Element::None; //5
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



Element elementFromName(const std::string& name){
    if (name == "Fire"){
        return Element::Fire;
    }
    else if (name == "Wind"){
        return Element::Wind;
    }
    else if (name == "Earth"){
        return Element::Earth;
    }
    else if (name == "Water"){
        return Element::Water;
    }
    else{
        return Element::None;
    }
}

Character makeCharacter(const std::vector<std::string>& ligne){
    Character Character;
    Character.name = ligne[0];
    Character.maxHp = std::stoi(ligne[1]);
    Character.hp = std::stoi(ligne[1]);
    Character.actionPoints = std::stoi(ligne[2]);
    Character.movePoints = std::stoi(ligne[3]);
    Character.element = elementFromName(ligne[4]);
    return Character;
    
}

std::vector<std::string> splitLine(const std::string& line, char separator) {
    std::vector<std::string> result;
    std::istringstream data(line);
    std::string field;

    while (std::getline(data, field, separator)) {
        result.push_back(field);
    }

    return result;
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
    std::ifstream file("./characters.txt");
    if(!file){
        std::cout<< "No file";
    }
    else{
        std::string line;
        std::cout << elementName(elementFromName("Earth")) << "\n";   // doit afficher Earth
        std::cout << elementName(elementFromName("Banane")) << "\n";  // doit afficher None
        while(std::getline(file,line)){
            std::vector<std::string> ligne = splitLine(line,';');
            std::cout << ligne.size() << " champs : ";
            // for (std::string mot : ligne){
            //     std::cout << "[" << mot << "]";
            // }
            showInvoc(makeCharacter(ligne));
       }

       
    }

    return 0;
}