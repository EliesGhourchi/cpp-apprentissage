#include <random>
#include <iostream>
int rollDice(std::mt19937& engine, int sides){

    std::uniform_int_distribution<int> dice(1, sides);       // des entiers de 1 à 6, équiprobables
    return dice(engine);
}

int main(){
        std::random_device seedSource;
        std::mt19937 engine(seedSource());
        for(int i =0; i<5;i++){

        std::cout << rollDice(engine,6) << " ";
    }
    return 0;
}