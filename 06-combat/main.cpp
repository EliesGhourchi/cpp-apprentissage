#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <random>
enum class Element { Fire, Wind, Water, Earth, None };

struct Character  {
    std::string name = "noname";
    int maxHp = 100;
    int hp = maxHp;
    int actionPoints = 6;
    int movePoints = 3;
    Element element = Element::None;
    int Pow = 0;
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
    std::cout<< x.name << " | " << x.maxHp << " | " << x.hp << " | " << x.actionPoints << " | " << x.movePoints << " | " << elementName(x.element) << " | " << x.Pow << "\n";
}

void showTeam(const std::vector<Character>& team, const std::string& teamName){
    std::cout << teamName << "\n";
    std::cout<< "Name | Max HP | HP | AP | MP | Element | Puissance\n";
    for (const Character& n : team){
        showInvoc(n);
    }

}

void applyDamage(Character& target, int amount){
    if (target.hp> amount){
        target.hp -= amount;
    }
    else{
        target.hp =0;
    }
}
int rollDice(std::mt19937& engine, int sides){

    std::uniform_int_distribution<int> dice(1, sides);       // des entiers de 1 à 6, équiprobables
    return dice(engine);
}
int computeDamage(const Character& attacker, std::mt19937& engine){
    return attacker.Pow + rollDice(engine,6);
}

int attack(const Character& attacker, Character& defender, std::mt19937& engine){
    int atkerDmg = computeDamage(attacker,engine);
    applyDamage(defender,atkerDmg);
    return atkerDmg;
}

bool isAlive(const Character& character){
    if(character.hp>0){
        return true;
    }
    else{
        return false;
    }
}



bool runDuel(Character first, Character second, std::mt19937& engine, bool showLog){
    int turn = 1;
    while (isAlive(first) and isAlive(second)){
        if(showLog){
            std::cout << "Tour : " << turn << "\n";
        }
        if(isAlive(first)){

            if(showLog){
                std::cout << first.name << " wins " << wins << " / " << fights
          << " (" << 100.0 * wins / fights << "%) against " << second.name << "\n";

            }
            else{
                attack(first,second,engine);
            }
        }
        else{
            break;
        }

        if(isAlive(second)){

            if(showLog){
                std::cout << first.name << " wins " << wins << " / " << fights
          << " (" << 100.0 * wins / fights << "%) against " << second.name << "\n";

            }
            else{
                attack(second,first,engine);
            }
        }
        else{
            break;
        }
        turn +=1;
    }
    
        if(!isAlive(first)){

            if(showLog){
                std::cout << second.name << " est le vainqueur en " << turn-1 << " tours.\n";
            }
            return false;
        }
        else{
            if(showLog){
                std::cout << first.name << " est le vainqueur en " << turn-1 << " tours.\n";
            }
            return true;
        }

    
}

int main(){
    
    //equipe A
    Character rocfort{"Rocfort",200,200,6,1,Element::Earth,5};
    Character samu_Rai{"Samu-Rai",70,70,9,4,Element::Wind,10};
    std::vector<Character> teamA = {rocfort, samu_Rai};
    //equipe B
    Character judeau{"Judeau",160,160,8,2,Element::Water,6};
    Character feubuleux{"Feubuleux",80,80,8,3,Element::Fire,9};
    std::vector<Character> teamB = {judeau, feubuleux};

    showInvoc(rocfort);          //→ après
    showTeam(teamA,"team A");

    std::random_device seedSource;
    std::mt19937 engine(seedSource());
    int i = 0;
    int cptWinFirst =0;
    bool firstWin = false;
    int j =0;
    for (j =0;j<5;j++ ){
    for(i = 0; i<1000;i++){
        
        firstWin = runDuel(feubuleux,feubuleux,engine,false);
        if(firstWin){
            cptWinFirst += 1;
        }
    }
    }
    std::cout << " first a gagnee " << cptWinFirst << " fois, et a perdu " << (j*1000) - cptWinFirst << "fois contre second\n";




    return 0;
}