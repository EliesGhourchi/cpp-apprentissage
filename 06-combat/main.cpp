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
    int turn = 1;
    while(isAlive(feubuleux) and isAlive(rocfort)){
        std::cout << "Tour : " << turn << "\n";
        if(isAlive(feubuleux)){
            std::cout <<"   feubuleux attaque rocfort, il inflige : " << attack(feubuleux,rocfort,engine) << "degats, rocfort a : "<< rocfort.hp << " point de vie \n";           
        }
        else{
            break;
        }
       
        if(isAlive(rocfort)){
            std::cout <<"   rocfort attaque feubuleux, il inflige : " << attack(rocfort,feubuleux,engine) << " degats, feubuleux a : "<< feubuleux.hp << " point de vie \n";
        }
        else{   
            break;
        }
        
        turn +=1;
    
    }

        if(!isAlive(feubuleux)){
            std::cout << "rocfort est le vainqueur en " << turn-1 << " tours.\n";            
        }
        else{
            std::cout << "feubuleux est le vainqueur en " << turn-1 << " tours.\n";
        }




    return 0;
}