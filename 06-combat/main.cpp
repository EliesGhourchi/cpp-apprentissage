#include <iostream>
#include <string>
#include <vector>
#include <random>
#include "character.h"
#include "combat.h"
#include "display.h"

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
        
        firstWin = runDuel(feubuleux,samu_Rai,engine,false);
        if(firstWin){
            cptWinFirst += 1;
        }
    }
    }
    std::cout << feubuleux.name << " wins " << cptWinFirst << " / " << j*i
          << " (" << 100.0 * cptWinFirst / (j*i) << "%) against " << samu_Rai.name << "\n";




    return 0;
}