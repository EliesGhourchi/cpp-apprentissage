#include <random>
#include <iostream>
#include <string>

#include "character.h"
#include "combat.h"

// les règles

int rollDice(std::mt19937& engine, int sides){

    std::uniform_int_distribution<int> dice(1, sides);       // des entiers de 1 à 6, équiprobables
    return dice(engine);
}

bool isAlive(const Character& character){
    if(character.hp>0){
        return true;
    }
    else{
        return false;
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

int computeDamage(const Character& attacker, std::mt19937& engine){
    return attacker.Pow + rollDice(engine,6);
}

int attack(const Character& attacker, Character& defender, std::mt19937& engine){
    int atkerDmg = computeDamage(attacker,engine);
    applyDamage(defender,atkerDmg);
    return atkerDmg;
}

bool runDuel(Character first, Character second, std::mt19937& engine, bool showLog){
    int turn = 1;
    while (isAlive(first) and isAlive(second)){
        if(showLog){
            std::cout << "Tour : " << turn << "\n";
        }
        if(isAlive(first)){

            if(showLog){
                std::cout << "  "<< first.name <<" attaque " << second.name << ", il inflige : " << 
                attack(first,second,engine) << "degats, "<< second.name << " a : " << second.hp << " point de vie \n";
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
                std::cout << "  "<< second.name <<" attaque " << first.name << ", il inflige : " << 
                attack(second,first,engine) << "degats, "<< first.name << " a : " << first.hp << " point de vie \n";
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
