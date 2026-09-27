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


bool teamIsAlive(const std::vector<Character>& team){
    for(Character membre : team){
        if(isAlive(membre)){
            return true;
        }
    }
    return false;
}

int firstAliveIndex(const std::vector<Character>& team){
    int i = 0;
    if(teamIsAlive(team)){
        for(Character membre : team){
            if(isAlive(membre)){
                return i;
            }
            i+=1;
        }
    }
    return -1;
}


bool runTeamDuel(std::vector<Character> teamA, std::vector<Character> teamB,std::mt19937& engine, bool showLog){
    int cible = 0;
    int turn = 1;
    while(teamIsAlive(teamA) and teamIsAlive(teamB)){
        if(showLog){
            std::cout << "Tour : " << turn << "\n";
        }
        for(Character& attaker : teamA){
            if(isAlive(attaker)){
                cible = firstAliveIndex(teamB);
                if(cible<0){
                    break;
                }
                else{
                    if(showLog){
                        std::cout << "  "<< attaker.name <<" attaque " << teamB[cible].name << ", il inflige : " << 
                        attack(attaker,teamB[cible],engine) << " degats, "<< teamB[cible].name << " a : " << teamB[cible].hp << " point de vie \n";
                    }
                    else{
                        attack(attaker,teamB[cible],engine);
                    }
                    
                }
            }
        }
        for(Character& attaker : teamB){
            if(isAlive(attaker)){
                cible = firstAliveIndex(teamA);
                if(cible<0){
                    break;
                }
                else{
                    if(showLog){
                        std::cout << "  "<< attaker.name <<" attaque " << teamA[cible].name << ", il inflige : " << 
                        attack(attaker,teamA[cible],engine) << " degats, "<< teamA[cible].name << " a : " << teamA[cible].hp << " point de vie \n";
                    }
                }
            }
        }
        turn+=1;
    }

    if(!teamIsAlive(teamA)){
        if(showLog){
            std::cout << "Team B est le vainqueur en " << turn-1 << " tours.\n";
        }
        return false;
    }
    else{
        if(showLog){
            std::cout << "Team A est le vainqueur en " << turn-1 << " tours.\n";
        }
        return true;
    }    
}
